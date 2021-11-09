//Inisialisasi pembuatan variable
#define B1 5 // Motor B pins
#define B2 6
int incomingByte = 0; // for incoming serial data
int input = 0;
int IR=3;
void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(9600); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 pinMode(B1, OUTPUT);
 pinMode(B2, OUTPUT);
 digitalWrite(B1, LOW);
 digitalWrite(B2, LOW);
 pinMode(IR,INPUT);
  
}
void loop() {
 //Program yang akan dijalankan berulang-ulang
 int bacaIR=digitalRead(IR);

 
  analogWrite(B1, 150);
  analogWrite(B2, 0);
  delay(200);

  analogWrite(B1, 0);
  analogWrite(B2, 0);
  delay(1000);

  analogWrite(B1, 0);
  analogWrite(B2, 150);
  delay(200);

  analogWrite(B1, 0);
  analogWrite(B2, 0);
  delay(1000);
}
