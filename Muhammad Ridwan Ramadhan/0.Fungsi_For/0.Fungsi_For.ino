void setup() {
 for(float i=5; i<=7; i++){
  pinMode(i,OUTPUT);
 }
}

void loop() {
  for(float i=5; i<=7; i++){
  digitalWrite(i,HIGH);
  delay(100);  
  digitalWrite(i,LOW);
  delay(100); 
  }
}
