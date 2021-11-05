//INISIALISASI
#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9

int R=5,Y=6,G=7,Buzzer=2;
MFRC522 mfrc522(SS_PIN,RST_PIN);
void panggil(){
  digitalWrite(G,HIGH);
  digitalWrite(R,LOW);
  digitalWrite(Buzzer,HIGH);
  delay(100);
  digitalWrite(Buzzer,LOW);
  delay(100);
  digitalWrite(Buzzer,HIGH);
  delay(100);
  digitalWrite(Buzzer,LOW);
  delay(100);
}
void gagal(){
  digitalWrite(R,HIGH);
  digitalWrite(G,LOW);
  digitalWrite(Buzzer,HIGH);
  delay(1000);
  digitalWrite(Buzzer,LOW);
  delay(1000);
}
void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(Buzzer,OUTPUT);
}

void loop() {
  if(!mfrc522.PICC_IsNewCardPresent()){return;}

  if(!mfrc522.PICC_ReadCardSerial()){return;}

  Serial.print("UID tag :");String content="";
  byte letter;
  for (byte i=0;i<mfrc522.uid.size;i++)
  {
    Serial.print(mfrc522.uid.uidByte[i]<0x10?"0":"");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : ""));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  
  if (content== "044F27BA8F6180") //Sesuaikan dengan ID kartu anda
  {
  Serial.println("Selamat datang Ridwan Zen!!!");
  delay(100);
  panggil();
  }
  else if(content=="CFE681AE"){
    Serial.println("Selamat datang COK!!!");
  delay(100);
  panggil();
  }
  else{
  Serial.println("Kartu Tidak Terdaftar!");
  gagal();
  }
  digitalWrite(R,LOW);
  digitalWrite(G,LOW);
  Serial.println("Tempelkan Kartu!");
  delay(500); //Jeda waktu perulagan seama 500 mili detik
  }
