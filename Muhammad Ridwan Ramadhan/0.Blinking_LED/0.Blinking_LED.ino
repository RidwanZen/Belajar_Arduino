int R=5;
int Y=6;
int G=7;

void setup() {
 pinMode(R,OUTPUT);
 pinMode(Y,OUTPUT);
 pinMode(G,OUTPUT);
}

void loop() {
  digitalWrite(R,HIGH);
  digitalWrite(Y,HIGH);
  digitalWrite(G,HIGH);
  delay(1000);
  digitalWrite(R,LOW);
  digitalWrite(Y,LOW);
  digitalWrite(G,LOW);
  delay(1000);

}
