// NESSE CÓDIGO O LED ACENDERÁ SE ULTRAPASSAR 1 SEGUNDO COM O PUSH BUTTON PRESSIONADO.O MESMO PARA DESLIGAR O LED

unsigned long ultimo_tempo = 0;
unsigned long tempo_atual = 0;
int estado = 0;
const int LED = 13;
const int BUTTON = 3;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON , INPUT);
}

void loop() {
   int bot = digitalRead(BUTTON);
   tempo_atual = millis();
   if(bot == LOW) {
     ultimo_tempo = tempo_atual;
     digitalWrite(LED, LOW);
   }
   if ((bot == HIGH) && (tempo_atual - ultimo_tempo >= 1000)){
      estado = !estado;
      ultimo_tempo = tempo_atual;
   }

   if(estado == 1){
      digitalWrite(LED, HIGH);
   }
   else if(estado == 0){
      digitalWrite(LED, LOW);
   }
}
