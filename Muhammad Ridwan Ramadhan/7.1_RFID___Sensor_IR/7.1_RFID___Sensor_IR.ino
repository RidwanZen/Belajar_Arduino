//INISIALISASI
#include <SPI.h>
#include <MFRC522.h>

String uidString;
int IR=3;
int kunci=0;
int buzzer=2;
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); // Creat MFRC522 instance.

void setup(){
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  pinMode(IR,INPUT);
  SPI.begin();    // Initiate SPI Bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  buzzerOke();
  Serial.println("TEMPELKAN KARTU");
}

void buzzerOke(){         // Bunyi Kartu Terdaftar
  digitalWrite(buzzer,HIGH);
  delay(50);
  digitalWrite(buzzer,LOW);
  delay(50);
  digitalWrite(buzzer,HIGH);
  delay(50);
  digitalWrite(buzzer,LOW);
  delay(50);
}

void buzzerGagal(){       // Bunyi Kartu Tidak Terdaftar
  digitalWrite(buzzer,HIGH);
  delay(1000);
  digitalWrite(buzzer,LOW);
  delay(1000);
}

void berhasil(){
  Serial.println("BERHASIL");
  buzzerOke();
  Serial.println("Silahkan Masuk!");
  kunci=1;
}

void readRFID(){
  mfrc522.PICC_ReadCardSerial();
  //Buzzer menyala saat membaca kartu benar
  buzzerOke();
  //Pembatas bisa dirubah sesuai keinginan, disini yang digunakan "-"
  uidString = String(mfrc522.uid.uidByte[0],HEX) + "-" +
              String(mfrc522.uid.uidByte[1],HEX) + "-" +
              String(mfrc522.uid.uidByte[2],HEX) + "-" +
              String(mfrc522.uid.uidByte[3],HEX);
              uidString.toUpperCase();
}

void loop(){
  //BACA DATA
  int bacaIR=digitalRead(IR);
  
  if (mfrc522.PICC_IsNewCardPresent() && kunci==0){
    readRFID();
    Serial.print("Tag UID: ");
    Serial.println(uidString);
    if(uidString=="A-A8-90-15"){ // Sesuaikan dengan ID Kartu 1
      berhasil();
    }
    else if(uidString=="4-11-75-42"){ // Sesuaikan dengan ID Kartu 2
      berhasil();
    }
    else{
      Serial.println("GAGAL");
      buzzerGagal();
    }
  }
    if(bacaIR==0 && kunci==1){  // Program Sensor IR
      buzzerOke();
      Serial.println("SUDAH MASUK");
      delay(500);
      Serial.println("PALANG DITUTUP");
      delay(500);
      Serial.println("TEMPELKAN KARTU");
      kunci=0;
    }
    else{
     
    }
}
