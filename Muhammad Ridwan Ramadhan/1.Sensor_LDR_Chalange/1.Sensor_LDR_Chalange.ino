//INISIALISASI
int pinLDR =A0; //SUDAH JADI ANALOG INPUT
int R=5;

void setup() {
  Serial.begin(9600);
  pinMode(R,OUTPUT);
}

void loop() {
  //BACA SENSOR
  int bacaLDR=analogRead(pinLDR);
      bacaLDR=map(bacaLDR,17,1024,0,255);    //MAPPING  //(data awal sensor,data akhir sensor,nilai yang diinginkan,nilai akhir yang diinginkan)
  
  //PRINT SERIAL
  Serial.print("NILAI :");
  Serial.print(bacaLDR);
  Serial.println();

  //LOGIKA
  analogWrite(R,bacaLDR);
 
}
