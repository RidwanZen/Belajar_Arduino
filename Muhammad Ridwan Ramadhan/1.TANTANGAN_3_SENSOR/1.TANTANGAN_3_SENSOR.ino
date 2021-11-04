int pinLDR=A0;
int pinFlame=A1;
int pinPIR=2;
int Buzzer=5;
int R=9,Y=10,G=11;

void setup() {
  Serial.begin(9600);
  pinMode(pinPIR,INPUT);
  pinMode(Buzzer,OUTPUT);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);

}

void loop() {
  //BACA SENSOR FLAME
  int bacaFlame=analogRead(pinFlame);
      bacaFlame=map(bacaFlame,24,1016,100,0);
  //BACA SENSOR LDR
  int bacaLDR=analogRead(pinLDR);
      bacaLDR=map(bacaLDR,30,1010,0,255);
  //BACA SENSOR PIR
  int bacaPIR=digitalRead(pinPIR);
      
  //PRINT SERIAL
  Serial.print("FLAME :");
  Serial.print(bacaFlame);
  Serial.print(" | LDR :");
  Serial.print(bacaLDR);
  Serial.print(" | PIR :");
  Serial.print(bacaPIR);
  Serial.println();

 //LOGIKA LDR
 
  analogWrite(R,bacaLDR);
 
  //LOGIKA FLAME
 if(bacaFlame==0){
  Serial.println("AMAN BANGET");
  digitalWrite(Buzzer,LOW);
  digitalWrite(G,HIGH);
  digitalWrite(Y,LOW);
 }
 else if(bacaFlame >=20 && bacaFlame <=50){
  Serial.println("WARNING SILAHKAN PERIKSA");
  digitalWrite(R,LOW);
  digitalWrite(G,LOW);
  digitalWrite(Y,HIGH);
  digitalWrite(Buzzer,HIGH);
  delay(1000);
  digitalWrite(Buzzer,LOW);
  delay(1000);
 }
 else if(bacaFlame>=50){
  Serial.println("WASPADA HARAP MENGUNGSI");
  digitalWrite(R,LOW);
  digitalWrite(G,HIGH);
  digitalWrite(Y,HIGH);
  digitalWrite(Buzzer,HIGH);
  delay(50);
  digitalWrite(Buzzer,LOW);
  delay(50);
 }
 else{
  digitalWrite(R,LOW);
  digitalWrite(Y,LOW);
  digitalWrite(G,LOW);
 }

}
