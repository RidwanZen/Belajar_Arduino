//INISIALISASI
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>

//Inisialisasi pembuatan variable LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);
// PanggilLibrary , Variabel , ( Alamat I2C , panjang karakter lcd , lebar karakter lcd)

//Inisialisasi pembuatan variable RFID
String uidString;
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); // Creat MFRC522 instance.

//INISIALISASI TEMPERATURE
int sensorSuhu=2;
OneWire oneWire(sensorSuhu);
DallasTemperature sensors(&oneWire);

void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(9600); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 sensors.begin();
 lcd.begin();
 SPI.begin();    // Initiate SPI Bus
 mfrc522.PCD_Init();   // Initiate MFRC522
 Serial.println("TEMPELKAN KARTU");
 lcd.setCursor(0,0); lcd.print("TEMPELKAN KARTU");
}

void readRFID(){
  mfrc522.PICC_ReadCardSerial();
  //Buzzer menyala saat membaca kartu benar
  //buzzerOke();
  //Pembatas bisa dirubah sesuai keinginan, disini yang digunakan "-"
  uidString = String(mfrc522.uid.uidByte[0],HEX) + "-" +
              String(mfrc522.uid.uidByte[1],HEX) + "-" +
              String(mfrc522.uid.uidByte[2],HEX) + "-" +
              String(mfrc522.uid.uidByte[3],HEX);
              uidString.toUpperCase();
}

void loop() {
  //BACA SENSOR
  sensors.requestTemperatures();
  float bacaSuhu=sensors.getTempCByIndex(0);
  
  //PRINT SERIAL
  Serial.print("SUHU :");
  Serial.print(bacaSuhu);
  Serial.print(" C");
  Serial.println();
  lcd.setCursor(0,1); lcd.print("SUHU :");
  lcd.setCursor(6,1); lcd.print(bacaSuhu);
  lcd.setCursor(12,1); lcd.print("C");
  
  if (mfrc522.PICC_IsNewCardPresent()){
    readRFID();
    Serial.print("Tag UID: ");
    Serial.println(uidString);
    
    if(uidString=="C3-45-96-15"){ // Sesuaikan dengan ID Kartu 1
      lcd.clear();
      lcd.setCursor(0,0); lcd.print("ID :");
      lcd.setCursor(4,0); lcd.print(uidString);
      lcd.setCursor(0,1); lcd.print("KARTU BERHASIL");
    }
    else if(uidString=="FC-37-FB-38"){ // Sesuaikan dengan ID Kartu 2
      lcd.clear();
      lcd.setCursor(0,0); lcd.print("ID :");
      lcd.setCursor(4,0); lcd.print(uidString);
      lcd.setCursor(0,1); lcd.print("KARTU BERHASIL");
    }
    else{
      lcd.clear();
      lcd.setCursor(0,0); lcd.print("ID :");
      lcd.setCursor(4,0); lcd.print(uidString);
      lcd.setCursor(0,1); lcd.print("KARTU GAGAL");
    }
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0); lcd.print("TEMPELKAN KARTU");
  }

}
