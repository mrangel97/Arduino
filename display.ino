// Nesse projeto é utilizado o sensor de temperatura e umidade DHT22 e o piezoelétrico
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

// Definicao do pino do sensor 
#define DHTPIN 7
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

// Piezoeletrico
const int piezo = 0; // A0
const int limiarLimite = 50; // BATIMENTO

void setup()   
{
  Serial.begin(9600);
  // Inicializa o display
  display.begin(SSD1306_SWITCHCAPVCC);
  // Inicializa o sensor DHT22
  dht.begin();
  // Apaga o display
  display.clearDisplay();
}

void loop() 
{
  float umidade = dht.readUmidity(); // ler umidade
  float temperatura = dht.readTemperature(); // ler temperatura

  display.setTextSize(2); //tamanho do texto
  display.setTextColor(WHITE);
  display.println("Umidade: "); // mostra a umidade
  display.println(umidade);
  display.println(" %");
  display.println("Temperatura: "); // mostra a temperatura
  display.println(temperatura);
  display.println(" *C");
  display.display(); //executa o texto no display

  int val = analogRead(piezo);
    if (val >= limiarLimite)
    {
        display.println("TOC!TOC");
        display.display();
    }
    delay(1000);
}
