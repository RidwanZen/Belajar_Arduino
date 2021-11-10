#include <LiquidCrystal_I2C.h>

#define pinSensor A0  // mendefinisikan pin A0 sebagai pin yang berhubungan dengan sensor
int sensorValue = 0; // variable untuk menampung nilai baca dari sensor dalam bentuk integer
float tinggiAir = 0; // variabel untuk menampung ketinggian air
float sensorVoltage = 0; // untuk menampung nilai ketinggian air
//Inisialisasi pembuatan variable
LiquidCrystal_I2C lcd(0x27, 16, 2);

int nilaiMax = 1023; // nilai "sensorValue" saat sensor terendam penuh kedalam air, bisa dirubah sesuai sensor dan jenis air yang anda pakai
float panjangSensor = 4.0 ; // 4.0 cm, bisa dirubah, menyesuikan dengan panjang sensor yang kalian gunakan

//        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//        |||||||||| Variabel di Atas Bisa Dirubah ||||||||||



void setup() {
  Serial.begin(9600); // mengatur boudrate komunikasi serial antara arduino dengan PC
  lcd.begin();
  Serial.println("Pembacaan Ketinggian Air");
  lcd.clear();
  lcd.setCursor(3,0); lcd.print("WATER LEVEL");
  delay(3000);
}

void loop() {
  sensorValue = analogRead(pinSensor); // membaca tengan dari sensor dalam bentuk integer
  tinggiAir = sensorValue*panjangSensor/nilaiMax;
  sensorVoltage = sensorValue*5.0/1023;

  // print data ke serial monitor
  Serial.print("Sensor Value = ");
  Serial.println(sensorValue);
  Serial.print("Sensor Voltage = ");
  Serial.println(sensorVoltage);
  Serial.print("Tinggi Air = ");
  Serial.println(tinggiAir);
  Serial.println();

  //PRINT DATA KE LCD
  lcd.clear(); 
  lcd.setCursor(0,0); lcd.print("VALUE   : ");
  lcd.print(sensorValue);
  lcd.setCursor(0,1); lcd.print("VOLTAGE : ");
  lcd.print(sensorVoltage);
  lcd.print("v");
  delay(3000);

  lcd.clear(); 
  lcd.setCursor(3,0); lcd.print("TINGGI AIR");
  lcd.setCursor(5,1); lcd.print(tinggiAir);
  lcd.print("cm");
  delay(3000);
}
