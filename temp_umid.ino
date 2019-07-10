// Nesse programa informa no monitor serial os valores da temperatura e da umidade através do sensor DHT22
#include <DHT.h>

#define DHTPIN 3
#define DHTTYPE 22

DHT dht(DHTPIN , DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float umidade = dht.readHumidity();
  float temperatura = dht.readTemperature();

  Serial.print("Umidade: ");
  Serial.print(umidade);
  Serial.println(" %\t");
  delay(2000);
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" *C");
}
