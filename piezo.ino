// Através do uso do piezoelétrico,com a batida o led acenderá
const int sensor=0; //A0
const int led=11;
const int limiarLimite=50; // BATIMENTO

void setup(){
    pinMode(led, OUTPUT);
}

void loop(){
int val= analogRead(sensor);
    if (val >= limiarLimite)
    {
        digitalWrite(led, HIGH);
        delay(1000);
        digitalWrite(led, LOW);
    }
    else
    {
       digitalWrite(led, LOW);
    }
}
