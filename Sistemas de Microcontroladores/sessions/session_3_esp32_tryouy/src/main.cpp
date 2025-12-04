#include <Arduino.h>

int ledPin = D9;    //Define LED pin 
void setup(){
   pinMode(ledPin, OUTPUT);// Set ledPin as output mode 
}

void loop(){
   digitalWrite(ledPin, HIGH);   // Outputting high, the LED turns on 
   delay(1000);     //Delay 1 second 
   digitalWrite(ledPin, LOW);  // Outputting low, the LED turns off
   delay(1000);           
}