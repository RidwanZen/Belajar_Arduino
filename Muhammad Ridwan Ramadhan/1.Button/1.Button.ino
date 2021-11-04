int tombol1=2,tombol2=3,tombol3=4;
int R=5,Y=6,G=7;

void setup() {
  Serial.begin(9600);
  pinMode(tombol1,INPUT);
  pinMode(tombol2,INPUT);
  pinMode(tombol3,INPUT);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);

}

void loop() {
  int bacaTombol1=digitalRead(tombol1);
  int bacaTombol2=digitalRead(tombol2);
  int bacaTombol3=digitalRead(tombol3);
  
  
  
  if(bacaTombol1==1){
    digitalWrite(R,HIGH);
    Serial.println("KONDISI tombol1:" +String(bacaTombol1));
  }
  
  else if(bacaTombol2==1){
    digitalWrite(Y,HIGH);
    Serial.println("KONDISI tombol2:" +String(bacaTombol2));
  }
  
  else if(bacaTombol3==1){
    digitalWrite(G,HIGH);
    Serial.println("KONDISI tombol3:" +String(bacaTombol3));
  }
  else{
    digitalWrite(R,LOW);
    digitalWrite(Y,LOW);
    digitalWrite(G,LOW);
  }

}
