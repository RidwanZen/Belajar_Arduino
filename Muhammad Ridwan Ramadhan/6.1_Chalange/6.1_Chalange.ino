//INISIALISASI
#include <NewPing.h>
int R=9,Y=10,G=11;
int triger=4;
int echo=3;
int batas=200;  //max 400cm
int Buzzer=5;

NewPing cm(triger,echo,batas);

void setup() {
  Serial.begin(9600);
  pinMode(Buzzer,OUTPUT);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
}

void loop() {
  //BACA SENSOR
  int bacaJarak=cm.ping_cm();
  
  //PRINT SERIAL
  
  Serial.println();
  //LOGIKA ULTRASONIC
  if(bacaJarak<=20 && bacaJarak!=0){
    Serial.print(bacaJarak);
    Serial.print(" | BERHENTI");
    digitalWrite(R,HIGH);
    digitalWrite(Y,LOW);
    digitalWrite(G,LOW);
    digitalWrite(Buzzer,HIGH);
    delay(50);
    digitalWrite(Buzzer,LOW);
    delay(50);
  }
  else if(bacaJarak >=21 && bacaJarak <=70){
    Serial.print(bacaJarak);
    Serial.print(" | BAHAYA");
    digitalWrite(R,LOW);
    digitalWrite(Y,HIGH);
    digitalWrite(G,LOW);
    digitalWrite(Buzzer,HIGH);
    delay(1000);
    digitalWrite(Buzzer,LOW);
    delay(1000);
  }
  /*else if(bacaJarak >= 71 or bacaJarak==0){
    Serial.print(bacaJarak);
    Serial.print(" | AMAN");
    digitalWrite(R,LOW);
    digitalWrite(Y,LOW);
    digitalWrite(G,HIGH);
    digitalWrite(Buzzer,LOW);
  }*/
  else{
    Serial.print(bacaJarak);
    Serial.print(" | AMAN");
    digitalWrite(Buzzer,LOW);
    digitalWrite(R,LOW);
    digitalWrite(Y,LOW);
    digitalWrite(G,HIGH);
  }
}
