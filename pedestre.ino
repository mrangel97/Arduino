//Esse programa começa com o led verde ligado por alguns segundos fazendo com que depois o led vermelho pisque 3 vezes
//Depois disso,o led vermelho permanece ligado por uns segundos e em seguida o led verde pisca 3 vezes.E com isso segue o loop
void setup() {
  pinMode(10,OUTPUT); //LED VERDE
  pinMode(11,OUTPUT); // LED VERMELHO

}

void loop() {
  int j;  //j = VEZES QUE VAI PISCAR O LED VERDE E O VERMELHO 
  //PERMANECER LIGADO LED VERDE
  digitalWrite(10,HIGH); 
  delay(5000);
  digitalWrite(10,LOW); // DESLIGAR LED VERDE
  delay(1000);
  for(j=0;j<3;j++) // PISCAR LED VERMELHO
  {                 
    digitalWrite(11,HIGH);
    delay(1000);
    digitalWrite(11,LOW); 
    delay(1000);
  }
  //PERMANECER LIGADO LED VERMELHO
  digitalWrite(11,HIGH); 
  delay(5000);
  digitalWrite(11,LOW); //DESLIGAR LED VERMELHO 
  delay(1000);
  for(j=0;j<3;j++) //PISCAR LED VERDE
  {
    digitalWrite(10,HIGH);
    delay(1000);
    digitalWrite(10,LOW);
    delay(1000);
  }
}
