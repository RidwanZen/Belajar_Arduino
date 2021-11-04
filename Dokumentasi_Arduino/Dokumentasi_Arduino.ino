DOKUMENTASI
int  //Data dijadikan bilangan Bulat 1 (angka aja)
float //Data dijadikan bilangan Desimal 0.1  (ada koma)
String //Data dijadikan sebagai karakter (Huruf atau kata)

int variable_nya=pinArduino; //perintah untuk membuat variable yang digunakan sebagai (alias) / 
                             //pengganti pin atau nilai pada arduino
Serial.begin(9600);  //perintah untuk setting baudrate komunikasi Serial / Serial Monitor
pinMode(pinArduino,INPUT);  //Perintah untuk setting Mode pin pada Arduino sebagai Inputan (button,Sensor, dll)
pinMode(pinArduino,OUTPUT); //Perintah untuk setting Mode pin pada Arduino sebagai Outputan(LED,Buzzer, dll)
digitalWrite(pinArduino,HIGH); //Perintah untuk memberikan pin Arduino nilai 5 Volt (LED HIDUP)
digitalWrite(pinArduino,LOW); //Perintah untuk memberikan pin Arduino nilai 0 Volt  (LED MATI)
analogWrite (pinArduino,0 s/d 255); //Perintah untuk memberikan pin Arduino nilai 0 Volt s/d 5 Volt
                                    //dengan Konversi nilai PWM 0 s/d 255                   
int bacaData=digitalRead(pinArduino); //Perintah untuk megambil data di Pin Digital (data bernilai antara 0 dan 1) D0 s/d D13
int bacaData=analogRead(pinArduino); //Perintah untuk megambil data di Pin analog (data bernilai antara 0 dan 1024) A0 s/d A5
int tampungData=bacadata*5; //Untuk pengambilan data dari senor dan di kalikan nilai 5 (perhitungan matematika) 
                            // * (perkalian), / (pembagian), - (pengurangan), + (penambahan)
    bacaData=map(bacaData,0,1024,0,100); //Untuk merubah data dari pembacaan data 0 s/d 1024 menjadi 0 s/d 100
   //Tampung=merubah data(tampung,datawal sensor,dataahir sensor,nilai awal rubah, Nilai ahir rubah);
Serial.print("Nilai :");  //perintah untuk menampikan data String pada serial monitor
Serial.print(bacaData);  //perintah untuk menampikan data sensor pada serial monitor
Serial.println();  //perintah untuk enter pada serial monitor
delay(1000); //Perintah untuk menjeda perulangan (looping) dengan nilai 1000 atau 1 detik


Program Fungsi (if, for, or, and, <=, >=,  ==  dan !=)
---------------------------------------------------------------------- 
Contoh IF
##########
if(bacaData==1){  //Untuk pembuatan logika pada arduino (Jika bacaData bernilai 1 maka memanggil perintah dibawahnya)
  //isi dengan Perintah                         
}else if(bacaData==2){ //Untuk pembuatan logika tambahan (Jika bacaData bernilai 2 maka memanggil perintah dibawahnya)
  //isi dengan Perintah 
}else{                 //Untuk pembuatan logika selain dari logika diatasnya (Jika bacaData bukan bernilai 1 atau 2 maka memanggil perintah dibawahnya
  //isi dengan Perintah
}

Contoh FOR
##########
for (int i=0; i<100; i++){ //membuat variable dengan isi nilai yang bisa berubah dengan nilai perulangan dari penjumlahan (0+1=1, 1+1=2, 2+1=3, n+1=n)
  Serial.print(i); //Cetak Hasil Perulangan
  //isi dengan Perintah
}

for (int i=100; i>0; i--){ //membuat variable dengan isi nilai yang bisa berubah dengan nilai perulangan dari pengurangan (100-1=99, 99-1=98, 98-1=97, n-1=n)
  Serial.print(i); //Cetak Hasil Perulangan
  //isi dengan Perintah
}

Contoh OR
##########
if ( bacaTomboll == 1 or bacaTombol2 == 1 ){ //jika tombol1 bernilai 1 atau tombol2 bernilai 1, maka jalankan perintah dibawah bisa menggunakan (or atau ||)
  //isi dengan Perintah
} else { //Selain itu Jika logika diatas tidak dipenuhi maka jalankan perintah dibawahnya
  //isi dengan Perintah
}

Contoh AND
##########
if ( bacaTomboll == 1 and bacaTombol2 == 1 ){ //jika tombol1 bernilai 1 dan tombol2 bernilai 1, maka jalankan perintah dibawah bisa menggunakan (and atau &&)
  //isi dengan Perintah
} else { //Selain itu Jika logika diatas tidak dipenuhi maka jalankan perintah dibawahnya
  //isi dengan Perintah
}

Contoh "<=" (Kurang Dari Sama Dengan)
##########
if ( bacaData<= 10 ){ //jika data bernilai  kurang dari 10 (maksudnya 9,8,5,4, dst.), maka jalankan perintah dibawahnya 
  //isi dengan Perintah
} else { //Selain itu Jika logika diatas tidak dipenuhi maka jalankan perintah dibawahnya
  //isi dengan Perintah
}

Contoh ">=" (Lebih Dari Sama Dengan)
##########
if ( bacaData>= 10 ){ //jika data bernilai  lebih dari 10 (maksudnya 11,12,13 dst.), maka jalankan perintah dibawahnya 
  //isi dengan Perintah
} else { //Selain itu Jika logika diatas tidak dipenuhi maka jalankan perintah dibawahnya
  //isi dengan Perintah
}

Contoh "==" (Sama Dengan)
##########
if ( bacaTomboll == 1 ){ //jika tombol bernilai 1 atau sama dengan satu, jalankan perintah dibawah
  //isi dengan Perintah
} else {
  //isi dengan Perintah
}

Contoh != (Tidak Sama Dengan)
##########
if ( bacaTomboll != 1 ){ //jika tombol bernilai bukan 1 atau tidak sama dengan 1 (nilai yang ada di dalamnya), jalankan perintah dibawah
 //isi dengan Perintah
} else {
  //isi dengan Perintah
}

void fungsion(){  //Untuk membuat variable function untuk menjalankan perintah dan dapat di panggil dengan perintah  fungsion();
  //Perintah
}

fungsion(); //Pemanggilan Function
