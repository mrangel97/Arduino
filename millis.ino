#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

// Definicao do pino do sensor 
#define DHTPIN 3
// Tipo de sensor
#define DHTTYPE 22

//Definição do pino do push button
#define BUTTON 2

// Definicao de pinos interface SPI
#define OLED_SDA   9 
#define OLED_SCK   10 
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13
Adafruit_SSD1306 display(OLED_SDA, OLED_SCK, OLED_DC, OLED_RESET, OLED_CS);

// Criacao do objeto para comunicacao com o sensor
DHT dht(DHTPIN, DHTTYPE);

void umid_temp(){
  float umidade = dht.readHumidity();
  float temperatura = dht.readTemperature();

  display.setCursor(10 , 10);
  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.print("Umidade: ");
  display.print(umidade);
  display.println(" %");

  display.print("Temperatura: ");
  display.print(temperatura);
  display.println(" *C");

  display.display();
}

unsigned long tempo_ini = 0;
int bot_velho;
int tela;

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC);
  dht.begin();
  display.clearDisplay();
  pinMode(BUTTON , INPUT);
  bot_velho = digitalRead(BUTTON);
  tela = 0;
}

void loop() {
  int bot_novo = digitalRead(BUTTON);
  if(bot_velho != bot_novo){
    if(bot_novo == HIGH){
      tempo_ini = millis();  
    }
    bot_velho = bot_novo;
  }
  if((bot_velho == HIGH) && (millis() - tempo_ini >= 1000)){
    tela = !tela;
  }
  if(tela){
    umid_temp();
  }
  else{
    display.clearDisplay();
    display.display();
  }
}
