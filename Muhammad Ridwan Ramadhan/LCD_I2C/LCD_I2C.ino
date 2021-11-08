#include <LiquidCrystal_I2C.h>
int IR=3;

//Inisialisasi pembuatan variable
LiquidCrystal_I2C lcd(0x27, 16, 2);
// PanggilLibrary , Variabel , ( Alamat I2C , panjang karakter lcd , lebar karakter lcd)

void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 lcd.begin();
 pinMode(IR,INPUT);
}

void loop() {
  int bacaIR=digitalRead(IR);
  float suhu=random(20.1,75.5);   //DATA SUHU RANDOM
 //Program yang akan dijalankan berulang-ulang
 lcd.clear(); //Untuk Menghapus karakter pada LCD
 lcd.setCursor(0,0); lcd.print("SUHU:");    //setCursor(colom,baris)
 lcd.setCursor(5,0); lcd.print(suhu);
 lcd.setCursor(12,0); lcd.print("C");
 
 lcd.setCursor(0,1); lcd.print("SENSOR IR:");    //setCursor(colom,baris)
 lcd.setCursor(10,1); lcd.print(bacaIR);
 delay(1000); //Jeda waktu perulagan seama 1000 mili detik
 /*lcd.clear(); //Untuk Menghapus karakter pada LCD
 lcd.setCursor(0,0); lcd.print(" PROJECT");
 lcd.setCursor(0,1); lcd.print(" ARDUINO");
 delay(1000); //Jeda waktu perulagan seama 1000 mili detik
 */
}
