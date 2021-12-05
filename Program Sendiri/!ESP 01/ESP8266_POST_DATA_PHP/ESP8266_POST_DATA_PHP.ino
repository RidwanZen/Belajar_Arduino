#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
#include <SPI.h>
#include <MFRC522.h>


//char* ssid    = "www.interactiverobotics.club";
char* ssid    = "04FS_2c9560"; //isi dengan SSID WIFI
char* pass    = "Rahasia01"; //isi dengan PASSWORD WIFI

int indikator=7;
String uidString;

int buzzer=5;
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

void setup () {
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  pinMode(indikator,OUTPUT);
  pinMode(buzzer,OUTPUT);
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  while (WiFi.status() != WL_CONNECTED) {
    //delay(1000);
    Serial.println("Connecting..");
    digitalWrite(indikator,HIGH);
    delay(200);
    digitalWrite(indikator,LOW);
    delay(200);
  }

  if(WiFi.status() == WL_CONNECTED){
    Serial.println("Connected!!!");
    digitalWrite(indikator,HIGH);
  }
  else{
    Serial.println("Connected Failed!!!");
  }
bunyibuzzer();
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    if(mfrc522.PICC_IsNewCardPresent()) {
    readRFID();
    HTTPClient http;  
    
    http.begin("http://192.168.1.13/rfidphp/data-api.php?rfid=" + String(uidString)); //Silakan ganti dengan ip address dan sesuaikan dengan direktori penyimpanan file php anda
    int httpCode = http.GET();

    if (httpCode > 0) {
      char json[500];
      String payload = http.getString();
      payload.toCharArray(json, 500);
      DynamicJsonDocument doc(JSON_OBJECT_SIZE(8));
      deserializeJson(doc, json);
       
     
     String ambil1          = doc["tanggal"];  
     String ambil2          = doc["rfid"]; 
  
     Serial.print("ambil1= ");Serial.println(ambil1);
     Serial.print("ambil2= ");Serial.println(ambil2);
     Serial.println(" ");
     delay(1000); 
    }

    http.end();
    bunyibuzzer();
  }
  }
}

void readRFID() {
  mfrc522.PICC_ReadCardSerial();
  // Sound the buzzer when a card is read
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(100);
  Serial.print("Tag UID: ");
  //Pembatas bisa dirubah sesuai keinginan, disini yang digunakan "-"
  uidString = String(mfrc522.uid.uidByte[0]) + "-" + String(mfrc522.uid.uidByte[1]) + "-" + 
  String(mfrc522.uid.uidByte[2]) + "-" + String(mfrc522.uid.uidByte[3]);
  Serial.println(uidString);  
}

void bunyibuzzer(){
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(100);
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(100);
}
