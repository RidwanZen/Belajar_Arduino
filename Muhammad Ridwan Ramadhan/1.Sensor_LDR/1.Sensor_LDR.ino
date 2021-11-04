//INISIALISASI
int pinLDR =A0;
int R=5;

void setup() {
  Serial.begin(9600);
  pinMode(R,OUTPUT);
}

void loop() {
  //BACA SENSOR
  int bacaLDR=analogRead(pinLDR);

  //PRINT SERIAL
  Serial.print("NILAI :");
  Serial.print(bacaLDR);
  Serial.println();

  //LOGIKA
  if(bacaLDR > 600){
    Serial.println("LAMPU MENYALA");
    digitalWrite(R,HIGH);
  }
  else{
    Serial.println("LAMPU MATI");
    digitalWrite(R,LOW);
  }
}
