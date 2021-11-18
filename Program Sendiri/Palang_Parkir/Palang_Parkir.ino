//INISIALISASI RFID
#include <SPI.h>      
#include <MFRC522.h>  //LIBRARY RFID
String uidString;   //Variable ID Card
#define SS_PIN 10   //PIN 10 SEBAGAI SS
#define RST_PIN 9   //PIN9 SEBAGAI RESET
MFRC522 mfrc522(SS_PIN, RST_PIN);

//INISIALISASI LCD
#include <LiquidCrystal_I2C.h>  //LIBRARY LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); //Inisialisasi LCD

//INISIALISASI SERVO
#include <Servo.h>  //LIBRARY SERVO
int outServo=3; 
Servo servo;

//INISIALISASI ULTRASONIK
#include <NewPing.h>  //LIBRARY ULTRASONIK
int triger=2;   //PIN 2 SEBAGAI TRIGER
int echo=8;     //PIN 8 SEBAGAI ECHO
int batas=400;  //BATAS JARAK MAX 400cm
NewPing cm(triger,echo,batas);

//INISIALISASI PIN
int merah=6;    //PIN 6 LED MERAH
int kuning=5;   //PIN 5 LED KUNING
int hijau=4;    //PIN 4 LED HIJAU
//int IR=2;       //PIN 2 SENSOR IR
int buzzer=7;   //PIN 7 BUZZER
int kunci=0;    //Variable Kunci

void setup(){
  Serial.begin(9600);
  lcd.begin();
  SPI.begin();
  mfrc522.PCD_Init();
  servo.attach(outServo);
  pinMode(merah,OUTPUT);
  pinMode(kuning,OUTPUT);
  pinMode(hijau,OUTPUT);
  pinMode(buzzer,OUTPUT);
  
  //pinMode(IR, INPUT);
  digitalWrite(merah,HIGH); //Kondisi awal led merah menyala
  Serial.print("TEMPELKAN KARTU");
  lcd.clear();
  lcd.setCursor(3,0); lcd.print("SILAHKAN");
  lcd.setCursor(0,1); lcd.print("TEMPELKAN KARTU");
  servo.write(90);  //kondisi awal servo 90
  delay(1000);
}

void berhasil(){    //UNTUK KARTU YANG TERDAFTAR
  Serial.println("PALANG DIBUKA");
  kunci=1;
  digitalWrite(merah,LOW);
  digitalWrite(hijau,HIGH);
  lcd.clear();
  lcd.setCursor(2,0); lcd.print("PALANG DIBUKA");
  delay(500);
  lcd.setCursor(1,1); lcd.print("SILAHKAN MASUK");
  delay(500);
  Serial.println("SILAHKAN MASUK");
  digitalWrite(buzzer,HIGH);
  delay(200);
  digitalWrite(buzzer,LOW);
  delay(200);
  digitalWrite(buzzer,HIGH);
  delay(200);
  digitalWrite(buzzer,LOW);
  delay(200);
  servo.write(0);
  delay(1000); 
}

void gagal(){   //UNTUK KARTU TIDAK TERDAFTAR
  Serial.println("MAAF KARTU GAGAL");
  kunci=0;
  lcd.clear();
  lcd.setCursor(3,0); lcd.print("MOHON MAAF");
  lcd.setCursor(0,1); lcd.print("KARTU ANDA GAGAL");
  digitalWrite(merah,LOW);
  delay(100);
  digitalWrite(merah,HIGH);
  digitalWrite(buzzer,HIGH);
  delay(1000);
  digitalWrite(buzzer,LOW);
  lcd.clear();
  lcd.setCursor(3,0); lcd.print("SILAHKAN");
  lcd.setCursor(0,1); lcd.print("TEMPELKAN KARTU");
  Serial.println("TEMPELKAN KARTU");
}
void readRFID(){    //PEMBACAAN ID CARD RFID
  mfrc522.PICC_ReadCardSerial();
  uidString = String(mfrc522.uid.uidByte[0],HEX) +"-" +
              String(mfrc522.uid.uidByte[1],HEX) +"-" +
              String(mfrc522.uid.uidByte[2],HEX) +"-" +
              String(mfrc522.uid.uidByte[3],HEX);
              uidString.toUpperCase();
}

void loop(){
  //BACA DATA
  //int bacaIR=digitalRead(IR);
  int bacaJarak=cm.ping_cm();
  //PRINT SERIAL
  Serial.println(bacaJarak);

  //LOGIKA
  if (mfrc522.PICC_IsNewCardPresent() && kunci==0){
    readRFID();
    Serial.print("tag UID: ");
    Serial.println(uidString);
    if(uidString=="C3-45-96-15"){
      berhasil();
    }
    else{
      gagal();
    }
  }
  else if(bacaJarak<=20 && kunci==1 && bacaJarak!=0){
    kunci=2;
  }
  else if(bacaJarak>=21 && kunci==2){
    kunci=0;
    Serial.println("PALANG DITUTUP");
    lcd.clear();
    lcd.setCursor(1,0); lcd.print("PALANG DITUTUP");
    delay(500);
    digitalWrite(hijau,LOW);
    delay(100);
    digitalWrite(kuning,HIGH);
    servo.write(90);
    delay(1000);
    digitalWrite(kuning,LOW);
    digitalWrite(merah,HIGH);
    lcd.setCursor(2,1); lcd.print("TERIMAKASIH");
    delay(1000);
  }
}
