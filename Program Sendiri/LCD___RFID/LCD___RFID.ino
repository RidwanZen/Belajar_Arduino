//INISIALISASI
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>

//Inisialisasi pembuatan variable LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);
// PanggilLibrary , Variabel , ( Alamat I2C , panjang karakter lcd , lebar karakter lcd)

//Inisialisasi pembuatan variable RFID
String uidString;
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); // Creat MFRC522 instance.

void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(9600); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
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
    delay(500);
    lcd.setCursor(0,1); lcd.print("|");
    delay(500);
    lcd.setCursor(1,1); lcd.print("|");
    delay(500);
    lcd.setCursor(2,1); lcd.print("|");
    delay(500);
    lcd.setCursor(3,1); lcd.print("|");
    delay(500);
    lcd.setCursor(4,1); lcd.print("|");
    delay(500);
    lcd.setCursor(5,1); lcd.print("|");
    delay(500);
    lcd.setCursor(6,1); lcd.print("|");
    delay(500);
    lcd.setCursor(7,1); lcd.print("|");
    delay(500);
    lcd.setCursor(8,1); lcd.print("|");
    delay(500);
    lcd.setCursor(9,1); lcd.print("|");
    delay(500);
    lcd.setCursor(10,1); lcd.print("|");
    delay(500);
    lcd.setCursor(11,1); lcd.print("|");
    delay(500);
    lcd.setCursor(12,1); lcd.print("|");
    delay(500);
    lcd.setCursor(13,1); lcd.print("|");
    delay(500);
    lcd.setCursor(14,1); lcd.print("|");
    delay(500);
    lcd.setCursor(15,1); lcd.print("|");
    delay(500);
  }

}
