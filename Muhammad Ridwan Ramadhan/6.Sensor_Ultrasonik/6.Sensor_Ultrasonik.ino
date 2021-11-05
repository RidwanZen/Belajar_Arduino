//INISIALISASI
#include <OneWire.h>
#include <DallasTemperature.h>
#include <NewPing.h>

int triger=4;
int echo=3;
int batas=400;  //max 400cm
int Buzzer=5;
int sensorSuhu=2;
OneWire oneWire(sensorSuhu);
DallasTemperature sensors(&oneWire);

NewPing cm(triger,echo,batas);

void setup() {
  Serial.begin(9600);
  sensors.begin();
  pinMode(Buzzer,OUTPUT);
  
}

void loop() {
  //BACA SENSOR
  sensors.requestTemperatures();
  float bacaSuhu=sensors.getTempCByIndex(0);
  int bacaJarak=cm.ping_cm();
  
  //PRINT SERIAL
  Serial.print("SUHU :");
  Serial.print(bacaSuhu);
  Serial.print(" C");
  Serial.print(" | DATA JARAK :");
  Serial.print(bacaJarak);
  Serial.print(" cm");
  Serial.println();
/*
  //LOGIKA
  if(bacaSuhu>=30){
    digitalWrite(Buzzer,HIGH);
    delay(1000);
    digitalWrite(Buzzer,LOW);
    delay(500);
  }
  else{
    digitalWrite(Buzzer,LOW);
  }
  */
  /*
  if(bacaSuhu!=DEVICE_DISCONNECTED_C){
    Serial.print("Data Suhu Yang Terbaca Pada Bus 1 (index0):");
    Serial.println(bacaSuhu);
  }
  else{
    Serial.println("Error:Sensor Pada Index 0 Tidak Ditemukan!");
  }
  */
}
