int sentuh=2;
int merah=4, kuning=5, hijau=6;
int buzzer=9;
int kunci=0;

void setup() {
  Serial.begin(9600);
  pinMode(merah,OUTPUT);
  pinMode(kuning,OUTPUT);
  pinMode(hijau,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(sentuh,INPUT);
}

void loop() {
  int bacaSentuh=digitalRead(sentuh);

  Serial.print(bacaSentuh);
  Serial.println();

  if(bacaSentuh==1 && kunci==0){
    digitalWrite(merah,HIGH);
    digitalWrite(kuning,LOW);
    digitalWrite(hijau,LOW);
    digitalWrite(buzzer,HIGH);
    delay(1000);
    kunci=1; 
  }
  else if(bacaSentuh==1 && kunci==1){
    digitalWrite(merah,LOW);
    digitalWrite(kuning,HIGH);
    digitalWrite(hijau,LOW);
    digitalWrite(buzzer,LOW);
    delay(1000);
    kunci=2; 
  }
  else if(bacaSentuh==1 && kunci==2){
    digitalWrite(merah,LOW);
    digitalWrite(kuning,LOW);
    digitalWrite(hijau,HIGH);
    digitalWrite(buzzer,HIGH);
    delay(1000);
    kunci=3; 
  }
  else if(bacaSentuh==1 && kunci==3){
    digitalWrite(merah,LOW);
    digitalWrite(kuning,LOW);
    digitalWrite(hijau,LOW);
    digitalWrite(buzzer,LOW);
    delay(1000);
    kunci=0; 
  }
}
