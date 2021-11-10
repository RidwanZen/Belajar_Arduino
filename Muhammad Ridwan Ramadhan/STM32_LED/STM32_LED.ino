//INISIALISASI
int tombol1=PA11; //TOMBOL1 PIN PA11
int tombol2=PA12; //TOMBOL2 PIN PA12
int tombol3=PA15; //TOMBOL3 PIN PA15

int merah=PA1;  //LED MERAH PIN PA1
int kuning=PA2; //LED KUNING PIN PA2
int hijau=PA3;  //LED HIJAU PIN PA3

void setup() {
  Serial.begin(9600);
  pinMode(merah,OUTPUT);  //LED SEBAGAI OUTPUT
  pinMode(kuning,OUTPUT);
  pinMode(hijau,OUTPUT);
  
  pinMode(tombol1,INPUT); //TOMBOL SEBAGAI INPUT
  pinMode(tombol2,INPUT);
  pinMode(tombol3,INPUT);
}

void loop() {
  //BACA DATA
  int bacaTombol1=digitalRead(tombol1);
  int bacaTombol2=digitalRead(tombol2);
  int bacaTombol3=digitalRead(tombol3);

  //PRINT SERIAL
  Serial.print("Tombol1 :");    Serial.print(bacaTombol1);
  Serial.print(" | Tombol2 :"); Serial.print(bacaTombol2);
  Serial.print(" | Tombol3 :"); Serial.print(bacaTombol3);
  Serial.println(); //UNTUK ENTER

  //LOGIKA
  if(bacaTombol1==1){ //TOMBOL1 MENYALAKAN LED MERAH
    digitalWrite(merah,HIGH);
  }else{
    digitalWrite(merah,LOW);
  }
  
  if(bacaTombol2==1){ //TOMBOL2 MENYALAKAN LED KUNING
    digitalWrite(kuning,HIGH);
  }else{
    digitalWrite(kuning,LOW);
  }
  
  if(bacaTombol3==1){ //TOMBOL3 MENYALAKAN LED HIJAU
    digitalWrite(hijau,HIGH);
  }else{
    digitalWrite(hijau,LOW); 
  }
}
