#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#include <virtuabotixRTC.h>

// Set pin RTC
virtuabotixRTC myRTC(A1, A2, A3); //CLK, DAT, RST

LiquidCrystal_I2C lcd(0x27,16,2);
// Deklarasi PIN DHT11 //
#define DHTPIN A0
// Tipe sensor yang digunakan (DHT11 atau DHT22) //
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

int count = 0;
int flag = 0;

// Membuat ikon hati 1 // 
byte heart1[] = {
  0x00,
  0x00,
  0x0A,
  0x15,
  0x11,
  0x0A,
  0x04,
  0x00
};

// Membuat ikon hati 2 // 
byte heart2[] = {
  0x00,
  0x00,
  0x0A,
  0x1F,
  0x1F,
  0x0E,
  0x04,
  0x00
};

// Membuat ikon kelelembaban // 
byte suhu[8] =
{
  B00100,
  B01010,
  B01010,
  B01110,
  B11111,
  B11111,
  B01110,
  B00000
};

// Membuat ikon kelelembaban // 
byte kelembaban[8] =
{
  B00100,
  B01010,
  B01010,
  B10001,
  B10001,
  B10001,
  B01110,
  B00000
};

void setup() {
//  Serial.begin(9600);

//  myRTC.setDS1302Time(00, 20, 00, 0, 19, 12, 2022); // sesuaikan dengan waktu terkini
// posisi seting (detik, menit, jam, hari, tanggal, bulan, tahun)

  lcd.init();
  lcd.backlight();
  lcd.createChar(1, kelembaban);
  lcd.createChar(2, suhu);
  lcd.createChar(3, heart1);
  lcd.createChar(4, heart2);
  lcd.setCursor(2,0);
  lcd.print("Zen Wisteria");
  lcd.setCursor(1,1);
  lcd.print("DHT + RTC + LCD");
  dht.begin();
  delay(2000);
  lcd.clear();
//  lcd.setCursor(0,0);
//  lcd.write(2);
//  lcd.print(" Suhu: ");
//  lcd.setCursor(0,1);
//  lcd.write(1);
//  lcd.print(" Lembab: ");
  flag = 1;
}

void Waktu() {
  myRTC.updateTime();
  lcd.setCursor(0, 0);
  lcd.print("Tgl: ");
  lcd.print(myRTC.dayofmonth);
  lcd.print("/");
  lcd.print(myRTC.month);
  lcd.print("/");
  lcd.print(myRTC.year);
  lcd.print(" ");
  lcd.setCursor(0, 1);
  lcd.print("Jam: ");
  lcd.print(myRTC.hours);
  lcd.print(":");
  lcd.print(myRTC.minutes);
  lcd.print(":");
  lcd.print(myRTC.seconds);
  lcd.print("    ");
  delay(1000);
}

void Suhu() {
  // Membaca kelembaban //
  float h = dht.readHumidity();
  // Membaca suhu dalam satuan Celsius //
  float t = dht.readTemperature();
  // Membaca suhu dalam satuan Fahrenheit //
  float f = dht.readTemperature(true);

  // Menampilkan pesan Error jika sensor tidak terbaca //
  if (isnan(h) || isnan(t) || isnan(f)) {
    lcd.setCursor(8,0);
    lcd.print("Error   ");
    lcd.setCursor(10,1);
    lcd.print("Error   ");
    delay(100);
    return;
  }
  
  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);

  // Menampilkan data ke LCD //
  lcd.setCursor(8,0);
  lcd.print(t,1);
  lcd.print((char)223);
  lcd.print("C     ");
  lcd.setCursor(10,1);
  lcd.print(h,0);
  lcd.print("%     ");

  // Jeda Waktu, ubah menjadi 2000 untuk DHT22//
  delay(1000);
}

void loop() {
  if (count < 10) {
    Waktu();
  }

  if (count >=10 && count <20) {
    if (flag == 1){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.write(2);
      lcd.print(" Suhu: ");
      lcd.setCursor(0,1); 
      lcd.write(1);
      lcd.print(" Lembab: ");
    }
    Suhu();  
    flag = 0;
  }

  if (count == 20){
    flag = 1;
    count = 0;
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Sword Art Online");
    lcd.setCursor(0,0);
    lcd.write(3);
    lcd.setCursor(1,0);
    lcd.print("Ridwan");
    lcd.setCursor(8,0);
    lcd.write(4);
    lcd.setCursor(10,0);
    lcd.print("Asuna");
    lcd.setCursor(15,0);
    lcd.write(3);
    delay(5000);
    lcd.clear();
  }
  count ++;
//  Serial.println (count);
  
}
