int pinFlame=A1;
int Buzzer=5;

void setup() {
  Serial.begin(9600);
  pinMode(Buzzer,OUTPUT);

}

void loop() {
  //BACA SENSOR
  int bacaFlame=analogRead(pinFlame);
      bacaFlame=map(bacaFlame,24,1016,100,0);    //MAPPING  //(data awal sensor,data akhir sensor,nilai yang diinginkan,nilai akhir yang diinginkan)
  
  //PRINT SERIAL
  Serial.print("NILAI :");
  Serial.print(bacaFlame);
  Serial.println();

  //LOGIKA
 if(bacaFlame>=50){
  digitalWrite(Buzzer,HIGH);
 }
 else{
  digitalWrite(Buzzer,LOW);
 }

}
