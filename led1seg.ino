// NESSE CÓDIGO O LED ACENDERÁ SE ULTRAPASSAR 1 SEGUNDO COM O PUSH BUTTON PRESSIONADO.O MESMO PARA DESLIGAR O LED

unsigned long ultimo_tempo = 0;
unsigned long tempo_atual = 0;
int estadoLed = 0;
const int LED = 13;
const int BUTTON = 3;



void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON , INPUT);
}

void loop() {
   int pressionado = digitalRead(BUTTON);
   if(pressionado == LOW) {
     ultimo_tempo = tempo_atual;
   }
   tempo_atual = millis();
   if ((pressionado == HIGH) && (tempo_atual - ultimo_tempo >= 1000)){
      estadoLed = !estadoLed;
      ultimo_tempo = tempo_atual;
   }

   if(estadoLed == 1){
      digitalWrite(LED, HIGH);
   }
   else if(estadoLed == 0){
      digitalWrite(LED, LOW);
   }
}
