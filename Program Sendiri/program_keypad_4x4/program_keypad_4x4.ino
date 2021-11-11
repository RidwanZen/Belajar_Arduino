#include <Keypad.h>
char tombol [4] [4] = {
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'},
};

byte pinKolom[] = {9, 10, 11, 12};  //S1, S2, S3, S4
byte pinBaris[] = {6, 5, 4, 3};     //S1, S5, S9, S13
Keypad keypad = Keypad(makeKeymap (tombol), pinBaris, pinKolom, 4, 4);

void setup() {
Serial.begin(9600);
}

void loop() {
char kode = keypad.getKey();
if (kode != NO_KEY){
Serial.println(kode);
}
}
