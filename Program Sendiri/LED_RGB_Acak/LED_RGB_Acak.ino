// RGB LED - Warna acak LED RGB
 
int tunda = 1000; //nilai tunda 1 detik
int merah = 6; //nama alias pin 6 dengan nama merah
int hijau = 5; //nama alias pin 5 dengan nama hijau
int biru = 3; //nama alias pin 3 dengan nama biru
 
void setup() {
//deklarasi untuk purpose output
pinMode(merah, OUTPUT);
pinMode(hijau, OUTPUT);
pinMode(biru, OUTPUT);
}
 
void loop() {
//penulisan PWM dengan nilai acak dengan nilai tunda 1 detik
analogWrite(biru, random(255));
analogWrite(merah, random(255));
analogWrite(hijau, random(255));
delay(tunda);
}
