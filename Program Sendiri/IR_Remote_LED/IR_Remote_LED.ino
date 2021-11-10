#include <IRremote.h> // Masukan Library IR Remote

int RECV_PIN = 11; // lokasi pin data dari IR Recaiver
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
Serial.begin(9600);
irrecv.enableIRIn();
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);

}
unsigned long data;
void loop() 
  {
    if (irrecv.decode(&results))  // jalankan jika ada data masuk
      {
        Serial.println(results.value); 
        data = results.value; // simpan data di variabel data
        irrecv.resume(); 

        switch (data)
          {

            case 16724175: // kode untuk angka '1' ganti kode untuk remote anda 
            digitalWrite(4,HIGH); // hidupkan led 1
            digitalWrite(5,LOW); //matikan Led 2
            digitalWrite(6,LOW); //matikan Led 3
            
            break;

            case 16718055: // kode untuk angka '2' ganti kode untuk remote anda 
            digitalWrite(4,LOW); //matikan Led 1
            digitalWrite(5,HIGH); // hidupkan led 2
            digitalWrite(6,LOW); //matikan Led 3
            
            break;
  
            case 16743045: // kode untuk angka '2' ganti kode untuk remote anda 
            digitalWrite(4,LOW); //matikan Led 1
            digitalWrite(5,LOW); //matikan Led 2
            digitalWrite(6,HIGH); // hidupkan led 3
            
            break;

            case 16738455: // kode untuk angka '2' ganti kode untuk remote anda 
            digitalWrite(4,LOW); //matikan Led 1
            digitalWrite(5,LOW); //matikan Led 2
            digitalWrite(6,LOW); // hidupkan led 3
            
            break;   

            case 16761405: // kode untuk angka '2' ganti kode untuk remote anda 
            digitalWrite(4,HIGH); //matikan Led 1
            delay(200);
            digitalWrite(4,LOW); //matikan Led 1
            delay(200);
            digitalWrite(5,HIGH); //matikan Led 1
            delay(200);
            digitalWrite(5,LOW); //matikan Led 1
            delay(200);
            digitalWrite(6,HIGH); //matikan Led 1
            delay(200);
            digitalWrite(6,LOW); //matikan Led 1
            delay(200);
            
            break;
         }
      }
}
