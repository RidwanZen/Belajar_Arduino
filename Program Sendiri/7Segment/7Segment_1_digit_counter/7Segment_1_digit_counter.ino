int angka[] = {
  B11111101,  //angka 0
  B01100001,  //angka 1
  B11011011,  //angka 2
  B11110011,  //angka 3
  B01100111,  //angka 4
  B10110111,  //angka 5
  B10111111,  //angka 6
  B11100001,  //angka 7
  B11111111,  //angka 8
  B11110111   //angka 9
};
 
int dataPin = 8;
int latchPin = 9;
int clockPin = 10;
 
void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}
 
void loop() {
  for (int i = 0; i < 10; i++) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, angka[i]);
    digitalWrite(latchPin, HIGH); 
    delay(1000);
  }
}
