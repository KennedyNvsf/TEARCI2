#include <Arduino.h>

// Define LED pins
const int ledPin1 = 17; // GPIO17
const int ledPin2 = 16; // GPIO16
const int ledPin3 = 4;  // GPIO4

// PWM properties
const int freq = 5000;       // Frequency in Hz
const int resolution = 8;    // 8-bit resolution

void setup() {
  // Attach each LED pin to PWM channel with the frequency and resolution
  ledcAttach(ledPin1, freq, resolution);
  ledcAttach(ledPin2, freq, resolution);
  ledcAttach(ledPin3, freq, resolution);
}

void loop() {
  // Increase brightness
  for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
    ledcWrite(ledPin1, dutyCycle); // Write brightness to LED 1
    ledcWrite(ledPin2, dutyCycle); // Write brightness to LED 2
    ledcWrite(ledPin3, dutyCycle); // Write brightness to LED 3
    delay(15);
  }

  // Decrease brightness
  for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
    ledcWrite(ledPin1, dutyCycle);
    ledcWrite(ledPin2, dutyCycle);
    ledcWrite(ledPin3, dutyCycle);
    delay(15);
  }
}
