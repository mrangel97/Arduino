// Nesse projeto é utilizado o sensor de temperatura e umidade DHT22 e o piezoelétrico
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
// Definicao do pino do sensor 
#define DHTPIN 2
// Tipo de sensor
#define DHTTYPE 22

// Definicao de pinos interface SPI
#define OLED_SDA   9
#define OLED_SCK   10
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13
Adafruit_SSD1306 display(OLED_SDA, OLED_SCK, OLED_DC, OLED_RESET, OLED_CS);

// Criacao do objeto para comunicacao com o sensor
DHT dht(DHTPIN, DHTTYPE);

//Piezoeletrico
const int piezo = 0; // A0
const int limiarLimite = 50; // Batimento

void setup()   
{
  Serial.begin(9600);
  // Inicializa o display
  display.begin(SSD1306_SWITCHCAPVCC);
  dht.begin();
  display.clearDisplay();
}

void loop() 
{
  float umidade = dht.readHumidity(); // ler umidade
  float temperatura = dht.readTemperature(); // ler temperatura

  display.setTextSize(1); //tamanho do texto
  display.setTextColor(WHITE);
  display.print("Umidade: "); // mostra a umidade
  display.print(umidade);
  display.println(" %");
  display.print("Temperatura: "); // mostra a temperatura
  display.print(temperatura);
  display.println(" *C");
  display.display(); //executa o texto no display
  
  int val = analogRead(piezo);
  if (val >= limiarLimite)
  {
    display.clearDisplay();
    display.setCursor(10,10);
    display.setTextSize(2);
    display.println("TOC!TOC!");
    display.display();
    delay(5000);
  }
}
