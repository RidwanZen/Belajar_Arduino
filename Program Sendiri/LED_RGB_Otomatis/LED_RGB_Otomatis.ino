// RGB LED - mengubah warna LED RGB secara otomotis
 
int merahPin = 6; //nama alias pin 6 sebagai merahPin
int hijauPin = 5; //nama alias pin 5 sebagai hijaupin
int biruPin = 3; //nama alias pin 3 sebagai biruPin
int tunda = 1000; // satuan dalam milisecond
 
void setup() {
//deklarasi pin menjadi output
pinMode(merahPin, OUTPUT);
pinMode(hijauPin, OUTPUT);
pinMode(biruPin, OUTPUT);
}
 
void loop() {
digitalWrite(merahPin, HIGH);
delay(tunda);
digitalWrite(merahPin, LOW);
 
digitalWrite(hijauPin, HIGH);
delay(tunda);
digitalWrite(hijauPin, LOW);
 
digitalWrite(biruPin, HIGH);
delay(tunda);
digitalWrite(biruPin, LOW);
}
