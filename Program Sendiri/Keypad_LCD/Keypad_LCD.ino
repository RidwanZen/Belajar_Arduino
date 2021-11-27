#define periodaKeypad         2000

#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int merah=2;

char tombol [4] [3] = {
{'1', '2', '3'},
{'4', '5', '6'},
{'7', '8', '9'},
{'*', '0', '#'},
};

byte pinKolom[] = {10, 11, 12};  //S1, S2, S3, S4
byte pinBaris[] = {9, 8, 7, 6};     //S1, S5, S9, S13
Keypad keypad = Keypad(makeKeymap (tombol), pinBaris, pinKolom, 4, 3);

char pad[11][11] = {
  "0 ",
  "1?!*#:=/+-",
  "2AaBbCc",
  "3DdEeFf",
  "4GgHhIi",
  "5JjKkLl",
  "6MmNnOo",
  "7PpQqRrSs",
  "8TtUuVvWw",
  "9XxYyZz",
};

byte padCounter;
char padChar;
bool padDitekan;
byte charCounter;
byte keySebelumnya;
char bufferKeypad[17];
char *bufferKeypadPtr;
 
long millisKeypad;

void setup() {
Serial.begin(9600);
lcd.begin();
pinMode(merah,OUTPUT);

lcd.clear();
lcd.setCursor(0,0); lcd.print("KETIK PESAN");
}

void loop(){
  lcd.setCursor(0,0); lcd.print("KETIK PESAN");
  panggilKeypad();
}

void panggilKeypad() {
  char key = keypad.getKey();
 
  if (key) {
    switch (key)
    {
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
 
        millisKeypad = millis() + periodaKeypad;
        if ((key == keySebelumnya) || (keySebelumnya == 0))
        {
          padChar = pad[key - '0'][charCounter];
          keySebelumnya = key;
        }
        else if ((padDitekan) && (padCounter < sizeof(bufferKeypad) - 1))
        {
          *bufferKeypadPtr++ = padChar;
          keySebelumnya = key;
          charCounter = 0;
          padCounter++;
          padChar = pad[key - '0'][charCounter];
        }
 
        padDitekan = true;
 
        lcd.setCursor(padCounter, 1);
        lcd.print(padChar);
        Serial.println(padChar);
        lcd.setCursor(padCounter, 1);
 
        charCounter++;
        if (!pad[key - '0'][charCounter])
        {
          charCounter = 0;
        }
        break;
 
      case '*':
        if (padCounter)
        {
          if (keySebelumnya)
          {
            keySebelumnya = 0;
          }
          lcd.setCursor(padCounter, 1);
          lcd.print(' ');
          charCounter = 0;
          padCounter--;
          bufferKeypadPtr--;
          padChar = *bufferKeypadPtr;
 
          lcd.setCursor(padCounter, 1);
        }
        else
        {
          resetInput();
        }
        break;
      case '#':
        if ((padDitekan) && (padCounter < sizeof(bufferKeypad) - 1))
        {
          *bufferKeypadPtr++ = padChar;
        }
        *bufferKeypadPtr = 0;
 
        Serial.print("String input = ");
        Serial.println(bufferKeypad);
        lcd.clear();
        //lcd.noBlink();
        lcd.setCursor(0, 0);
        lcd.print("Kirim Pesan = ");
        lcd.setCursor(0, 1);
        lcd.print(bufferKeypad);
        delay(3000);
 
        resetInput();
        break;
    }
    
  }
 
  if ((padDitekan) && (padCounter < sizeof(bufferKeypad) - 1))
  {
    if (millisKeypad < millis())
    {
      *bufferKeypadPtr++ = padChar;
      keySebelumnya = key;
      charCounter = 0;
      padCounter++;
      padDitekan = false;
 
      lcd.setCursor(padCounter, 1);
      lcd.print(' ');
      lcd.setCursor(padCounter, 1);
    }
  }
}

void resetInput()
{
  bufferKeypadPtr = bufferKeypad;
  charCounter = 0;
  padCounter = 0;
  keySebelumnya = 0;
  padDitekan = false;
 
  lcd.clear();
  //lcd.print("Masukkan string");
  //lcd.setCursor(0,0); lcd.print("Menunggu Pesan");
  //lcd.setCursor(padCounter, 1);
  //lcd.blink();
}
