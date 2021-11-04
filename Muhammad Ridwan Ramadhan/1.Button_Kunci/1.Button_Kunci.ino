int tombol1=2,tombol2=3,tombol3=4;
int R=5,Y=6,G=7;
int button1;
int button2;
int button3;

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
    button1++;
    delay(100);
    if(button1==1){
      digitalWrite(R,HIGH);
      delay(100);
    }
    if(button1==2){
      digitalWrite(R,LOW);
      delay(100);
      button1=0;
    }
  }
  if(bacaTombol2==1){
    button2++;
    delay(100);
    if(button2==1){
      digitalWrite(Y,HIGH);
      delay(100);
    }
    if(button2==2){
      digitalWrite(Y,LOW);
      delay(100);
      button2=0;
    }
  }
  if(bacaTombol3==1){
    button3++;
    delay(100);
    if(button3==1){
      digitalWrite(G,HIGH);
      delay(100);
    }
    if(button3==2){
      digitalWrite(G,LOW);
      delay(100);
      button3=0;
    }
  }
  else{
    
  }
}
