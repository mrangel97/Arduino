//O programa faz com que ligue e desligue o led utilizando o componente push button
int pressao=0;
int ligado=0;
void setup() {
  pinMode(2,OUTPUT); // LED
  pinMode(3,INPUT); //BOTAO
}

void loop() {
  pressao=digitalRead(3);
  if(pressao==HIGH)
  {
     switch(ligado)
     {
        case 0:
          digitalWrite(2,HIGH);
          ligado=1;
          break;
        case 1:
          digitalWrite(2,LOW);
          ligado=0;
          break; 
     }
  }
}
