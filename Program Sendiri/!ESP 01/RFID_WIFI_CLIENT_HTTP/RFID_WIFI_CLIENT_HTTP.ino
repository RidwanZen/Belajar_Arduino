#include <WiFiEsp.h>
#include <ArduinoJson.h> //6.17.3
#include <SoftwareSerial.h>
#include <SPI.h>
#include <MFRC522.h>

SoftwareSerial wifiSerial(2, 3); // RX, TX

char ssid[]        = "04FS_2c9560";            // your network SSID (name)
char pass[]        = "Rahasia01";        // your network password
int    HTTP_PORT   = 80;
String HTTP_METHOD = "GET";
char   HOST_NAME[] = "192.168.1.13"; // change to your PC's IP address
String PATH_NAME   = "/rfidphp/proses.php";
String getData;
int status = WL_IDLE_STATUS;     // the Wifi radio's status

// Initialize the Ethernet client object
WiFiEspClient client;

#define SS_PIN 10
#define RST_PIN 9
#define buzzer 5

int merah=7;

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup()
{
  Serial.begin(115200);
  wifiSerial.begin(9600);
  WiFi.init(&wifiSerial);
  pinMode(merah,OUTPUT);
  pinMode (buzzer,OUTPUT);
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
        const size_t capacity = JSON_OBJECT_SIZE(8) + 130; //cari dulu nilainya pakai Arduino Json 5 Asisten
        DynamicJsonDocument doc(capacity);
        //StaticJsonDocument<192> doc;
        DeserializationError error = deserializeJson(doc, getData);
      
        const char* id_dibaca       = doc["id"]; 
        const char* rfid_dibaca     = doc["rfid"]; 
        const char* nama_dibaca     = doc["nama"]; 
        const char* alamat_dibaca   = doc["alamat"]; 
        const char* telepon_dibaca  = doc["telepon"]; 
        const char* tanggal_dibaca  = doc["tanggal"]; 
        const int saldo_dibaca      = doc["saldo"];
        const String status_dibaca        = doc["status_bayar"];
        

       //LOGIKA
       if(String(nama_dibaca)!=""){
        buzzeroke();
        Serial.println("Kartu Terdaftar!");
        Serial.println(getData);
        //POST TO SERIAL
         Serial.print("ID       = ");Serial.println(id_dibaca);
         Serial.print("RFID     = ");Serial.println(rfid_dibaca);
         Serial.print("Nama     = ");Serial.println(nama_dibaca);
         Serial.print("Alamat   = ");Serial.println(alamat_dibaca);
         Serial.print("Telepon  = ");Serial.println(telepon_dibaca);
         Serial.print("Waktu    = ");Serial.println(tanggal_dibaca);
         Serial.print("saldo    = ");Serial.println(saldo_dibaca);
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
