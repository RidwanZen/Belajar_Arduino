int tombol1=2,tombol2=3;
int R=5,Y=6;
int button;
void setup() {
  Serial.begin(9600);
  pinMode(tombol1,INPUT);
  pinMode(tombol2,INPUT);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  
}

void loop() {
  int bacaTombol1=digitalRead(tombol1);
  int bacaTombol2=digitalRead(tombol2);

  if(bacaTombol1==1 and bacaTombol2==1){
    digitalWrite(R,HIGH);
    Serial.println("KONDISI tombol1:" +String(bacaTombol1));
  }
  else{
    digitalWrite(R,LOW);
  }

}
