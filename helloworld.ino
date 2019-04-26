// Nesse programa será exibido no display OLED o texto "Hello World!!"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Definicao de pinos interface SPI
#define OLED_SDA   9
#define OLED_SCK   10
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13
Adafruit_SSD1306 display(OLED_SDA, OLED_SCK, OLED_DC, OLED_RESET, OLED_CS);

void setup()   
{
  Serial.begin(9600);
  // Inicializa o display
  display.begin(SSD1306_SWITCHCAPVCC);
  // Apaga o display
  display.clearDisplay();
}

void loop() 
{
  display.setTextSize(2); //tamanho do texto
  display.setTextColor(WHITE);
  display.println(" Hello");
  display.println(" World!!");
  display.display(); //executa o texto no display
}

