#include <WiFiEsp.h>
#include <ArduinoJson.h> //6.17.3
#include <SoftwareSerial.h>
#include <SPI.h>
#include <MFRC522.h>

//INISIALISASI LCD
#include <LiquidCrystal_I2C.h>  //LIBRARY LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); //Inisialisasi LCD

//INISIALISASI SERVO
#include <Servo.h>  //LIBRARY SERVO
int outServo=5; 
Servo servo;

SoftwareSerial wifiSerial(2, 3); // RX, TX

char ssid[]        = "04FS_2c9560";            // your network SSID (name)
char pass[]        = "Rahasia01";        // your network password
int    HTTP_PORT   = 80;
String HTTP_METHOD = "GET";
char   HOST_NAME[] = "192.168.1.13"; // change to your PC's IP address
String PATH_NAME   = "/rfidui/proses.php";
String getData;
int status = WL_IDLE_STATUS;     // the Wifi radio's status

// Initialize the Ethernet client object
WiFiEspClient client;

#define SS_PIN 10
#define RST_PIN 9
#define buzzer 4
int IR=8;
int merah=7;
int kunci=0;
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup()
{
  Serial.begin(115200);
  wifiSerial.begin(9600);
  WiFi.init(&wifiSerial);
  lcd.begin();
  servo.attach(outServo);
  pinMode(merah,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(IR,INPUT);
  while(!Serial);
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522

  // check for the presence of the shield
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield Tidak terdeteksi");
    // don't continue
    while (true);
  }

  // attempt to connect to WiFi network
  while ( status != WL_CONNECTED) {
    Serial.print("Menghubungkan ke SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass);
  }

  // you're connected now, so print out the data
  Serial.println("Terhubung ke jaringan!");
  Serial.println();
  Serial.println("Mengubungkan ke Server...");
  // if you get a connection, report back via serial
  if (client.connect(HOST_NAME, HTTP_PORT)) {
    Serial.println("Berhasil terhubung ke Server!");
  }
}

void loop()
{
  //Baca data
  int bacaIR=digitalRead(IR);
  //Program yang akan dijalankan berulang-ulang
  if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {return;}
  
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String uidString;
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     uidString.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "" : ""));
     uidString.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.print("Message : ");
  uidString.toUpperCase();
  Serial.println(uidString);
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);

  //POST TO WEB
    client.connect(HOST_NAME, HTTP_PORT);
    client.println(HTTP_METHOD + " " + PATH_NAME + 
                   "?rfid=" + String(uidString) + 
                   "&namatol=bogor"
                   //"&sensor1=" + String(sensor1) + 
                   //"&sensor2=" + String(sensor2) + 
                   " HTTP/1.1");
    client.println("Host: " + String(HOST_NAME));
    client.println("Connection: close");
    client.println(); // end HTTP header
  
    while(client.connected()) {
      if(client.available()){
        char endOfHeaders[] = "\r\n\r\n";
        client.find(endOfHeaders);
        getData = client.readString();
        getData.trim();
        
        //AMBIL DATA JSON
        const size_t capacity = JSON_OBJECT_SIZE(9) + 144; //cari dulu nilainya pakai Arduino Json 5 Asisten
        DynamicJsonDocument doc(capacity);
        //StaticJsonDocument<192> doc;
        DeserializationError error = deserializeJson(doc, getData);
      
        const char* rfid_dibaca     = doc["rfid"]; 
        const char* nama_dibaca     = doc["nama"]; 
        const char* saldoawal       = doc["saldo"]; 
        const char* tarif_dibaca    = doc["tarif"]; 
        const char* saldoakhir      = doc["saldo_akhir"]; 
        const char* namatol_dibaca  = doc["namatol"];
        const char* tanggal_dibaca  = doc["tanggal"];
        const char* status_dibaca  = doc["status_bayar"];
        

       //LOGIKA
       if(String(rfid_dibaca)!=""){
        buzzeroke();
        Serial.println("Kartu Terdaftar!");
        Serial.println(getData);
        //POST TO SERIAL
         Serial.println("Silahkan Masuk!!");
         Serial.print("RFID         = ");Serial.println(rfid_dibaca);
         Serial.print("Nama         = ");Serial.println(nama_dibaca);
         Serial.print("Saldo Awal   = ");Serial.println(saldoawal);
         Serial.print("Tarif Tol    = ");Serial.println(tarif_dibaca);
         Serial.print("Saldo Akhir  = ");Serial.println(saldoakhir);
         Serial.print("Nama Tol     = ");Serial.println(namatol_dibaca);
         Serial.print("Waktu        = ");Serial.println(tanggal_dibaca);
         Serial.println(status_dibaca);
         Serial.println();
       }else{
        buzzergagal();
        Serial.println("Kartu Tidak terdaftar!");
       }
      } 
    }
    //delay(1000);
}


void buzzeroke(){
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(100);
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(100);
}

void buzzergagal(){
  digitalWrite(buzzer,HIGH);
  delay(1000);
  digitalWrite(buzzer,LOW);
  delay(10);
}
