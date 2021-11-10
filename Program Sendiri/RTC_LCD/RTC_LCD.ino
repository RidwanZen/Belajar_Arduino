#include <LiquidCrystal_I2C.h>
#include <virtuabotixRTC.h>
int buzzer=2;
virtuabotixRTC myRTC(6, 7, 8); //CLK, DAT, RST

//Inisialisasi pembuatan variable
LiquidCrystal_I2C lcd(0x27, 16, 2);
// PanggilLibrary , Variabel , ( Alamat I2C , panjang karakter lcd , lebar karakter lcd)

void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 lcd.begin();
 myRTC.setDS1302Time(00, 51, 18, 6, 9, 11, 2021); 
 pinMode(buzzer,OUTPUT);
}
  
void loop() {
  myRTC.updateTime();
  
 //Program yang akan dijalankan berulang-ulang
 lcd.clear(); //Untuk Menghapus karakter pada LCD
 lcd.setCursor(0,0); lcd.print("Tgl :");    //setCursor(colom,baris)
  lcd.print(myRTC.dayofmonth);
  lcd.print(",");
  lcd.print(myRTC.month);
  lcd.print(",");
  lcd.print(myRTC.year);
 lcd.setCursor(0,1); lcd.print("Jam :");    //setCursor(colom,baris)
  lcd.print(myRTC.hours);
  lcd.print(",");
  lcd.print(myRTC.minutes);
  lcd.print(",");
  lcd.print(myRTC.seconds);
 delay(1000);

  
 
 
}
