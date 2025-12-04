#include <Arduino.h>



unsigned long previous_time = millis();
const unsigned long tempo = 5000;
const int ledPin = 13;

void setup() {
  Serial.begin(9600); // Initialize the serial port
  pinMode(ledPin, OUTPUT);
}

void loop() {
  //implementar um temporizador 

  Serial.println(millis());
  Serial.println(previous_time);
  Serial.println("");
  
  // testar condição de tempo de intervalo 
  if(millis() - previous_time > tempo){

    Serial.println("LED ON");
    digitalWrite(ledPin, HIGH);
    
    //reset timer
    previous_time = millis();
    delay(2000);
    
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("LED OFF");

  }
}
