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

unsigned long ultimo_tempo = 0;
unsigned long tempo_atual = 0;
bool tela = false;
int bot_velho = 0;

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
void lerBotTemp(){
    int bot_novo = digitalRead(BUTTON); //ler botao atual
      if(bot_velho != bot_novo){ // se o anterior for o contrario do atual
        if(bot_novo == HIGH){  //pressionar botao
          tempo_atual = millis(); // contar tempo
        }
        bot_velho = bot_novo;
      }
}

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC);
  dht.begin();
  display.clearDisplay();
  pinMode(BUTTON , INPUT);
}

void loop() {
  lerBotTemp();
  if((bot_velho == HIGH) && (tempo_atual - ultimo_tempo < 1000)){
      display.clearDisplay();
      display.display();
  }
  if((bot_velho == HIGH) && (tempo_atual - ultimo_tempo >= 1000)){
       tela = !tela;
  }
  if(tela){
     umid_temp();
  }
  else{
       display.clearDisplay();
       display.display();
  }
  ultimo_tempo = tempo_atual;     
}
