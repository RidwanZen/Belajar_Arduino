//INISIALISASI
int tombol1=2;
int sensorIR=3;
int R=5,Y=6,G=7;
int kunci=0;

void setup() {
  Serial.begin(9600);
  pinMode(tombol1,INPUT);
  pinMode(sensorIR,INPUT);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
  Serial.println("SISTEM START");
}

void loop() {
  //BACA DATA
  int bacaTombol1=digitalRead(tombol1);
  int bacaIR=digitalRead(sensorIR);

  //PRINT SERIAL
  Serial.print("Tombol 1:");
  Serial.print(bacaTombol1);
  Serial.print(" | Sensor IR :");
  Serial.print(bacaIR);
  Serial.print(" | Flag :");
  Serial.print(kunci);
  Serial.println(); //UNTUK ENTER
  
  //LOGIKA PROGRAM
  if(bacaTombol1==0 && kunci==0){
    digitalWrite(R,HIGH);
  }
  if(bacaTombol1==1 && kunci==0){
    digitalWrite(R,LOW);
    digitalWrite(Y,HIGH);
    delay(500);
    digitalWrite(Y,LOW);
    digitalWrite(G,HIGH);
    kunci=1;
    Serial.println("PALANG DIBUKA");
    Serial.println("SELAMAT DATANG | SILAHKAN AMBIL TIKET");
    }
  if(bacaIR==0 && kunci==1){
    digitalWrite(G,LOW);
    delay(100);
    kunci=0;
    Serial.println("PALANG DITUTUP");
    Serial.println();
  }
  else{
    
  }
}
