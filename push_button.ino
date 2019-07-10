// Nesse programa informa no monitor serial se o push button está sendo pressionado (1) ou não pressionado (0)
#define BUTTON 2

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON , INPUT);
}

void loop() {
   int pressao = digitalRead(BUTTON);
   Serial.println(pressao);
   delay(2000);
}
