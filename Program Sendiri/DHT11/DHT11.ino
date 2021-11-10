#include "DHT.h"
#define DHTPIN 2 // Deklarasi PIN DHT11
#define DHTTYPE DHT11   // Tipe sensor yang digunakan (DHT11 atau DHT22)
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  dht.begin();
}

void loop() {
  delay(500);
  float h = dht.readHumidity(); // Membaca kelembaban
  float t = dht.readTemperature(); // Membaca suhu dalam satuan Celsius
  float f = dht.readTemperature(true); // Membaca suhu dalam satuan Fahrenheit

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Gagal membaca sensor!!!"));
    return;
  }
  
  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Kelembaban: "); // Menampilkan data kelembaban di serial monitor
  Serial.print(h);
  Serial.println("%");
  
  Serial.print("Temperatur (C): "); // Menampilkan data Suhu (C) di serial monitor
  Serial.print(t);
  Serial.println(" C");
    
  Serial.print("Temperatur (F): "); // Menampilkan data Suhu (F) di serial monitor
  Serial.print(f);
  Serial.println(" F");
  Serial.println(" ");
}
