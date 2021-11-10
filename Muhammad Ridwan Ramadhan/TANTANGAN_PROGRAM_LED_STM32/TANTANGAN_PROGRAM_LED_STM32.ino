//INISIALISASI
int ridwan_T1=PA11;
int ridwan_T2=PA12;
int ridwan_T3=PA15;

int ridwan_merah=PA1;
int ridwan_kuning=PA2;
int ridwan_hijau=PA3;

void setup(){
  Serial.begin(9600);
  pinMode(ridwan_T1,INPUT);
  pinMode(ridwan_T2,INPUT);
  pinMode(ridwan_T3,INPUT);

  pinMode(ridwan_merah,OUTPUT);
  pinMode(ridwan_kuning,OUTPUT);
  pinMode(ridwan_hijau,OUTPUT);
}

void loop(){
  //BACA DATA
  int ridwan_bacaT1=digitalRead(ridwan_T1);
  int ridwan_bacaT2=digitalRead(ridwan_T2);
  int ridwan_bacaT3=digitalRead(ridwan_T3);

  //PRINT TO SERIAL
  Serial.print("Tombol1 :");  Serial.print(ridwan_bacaT1);
  Serial.print(" | Tombol2 :");  Serial.print(ridwan_bacaT2);
  Serial.print(" | Tombol3 :");  Serial.print(ridwan_bacaT3);
  Serial.println();
  
  //LOGIKA TOMBOL 1
  if(ridwan_bacaT1==1){
    digitalWrite(ridwan_merah,HIGH);
  }else{
    digitalWrite(ridwan_merah,LOW);
  }
  //LOGIKA TOMBOL 2
  if(ridwan_bacaT2==1){
    digitalWrite(ridwan_kuning,HIGH);
  }else{
    digitalWrite(ridwan_kuning,LOW);
  }
  //LOGIKA TOMBOL 3
  if(ridwan_bacaT3==1){
    digitalWrite(ridwan_hijau,HIGH);
  }else{
    digitalWrite(ridwan_hijau,LOW);
  }
}
