#include <Arduino.h>

//TODO:Terminar implementação com o arduino e sensores
//algoritmo maquina de estados

unsigned long previous_time = millis();
unsigned long time = 5000;

bool ler_sensor = false;
bool acender_led = false;

void setup() {
  // configurar o periferico de leitura analogica do sensor
  pinMode(A0, OUTPUT);

  //configurar o periferico de saida digital
  pinMode(13, OUTPUT);
}

void loop() {
  
    if(millis() - previous_time > time){
        ler_sensor = true;
        previous_time = millis();
    }

  if(ler_sensor){
    //fazer leitura analogica do sensor
    analogRead(A0);
  }

  if(acender_led){
    //acender led
    digitalWrite(13, HIGH);
  }
  
}

