#include <Arduino.h>

#define Ledred1 D5     // Movement detection LED (Normally ON)
#define Ledyellow1 D6  // Unused in logic (can be implemented)
#define Ledgreen1 D9   // Turns ON when movement detected

#define Ledred2 D10    // Turns ON when Ledred1 turns OFF
#define Ledgreen2 D11  // Normally ON, turns OFF when movement detected

#define TRIGGER_PIN D12 // HC-SR04 Trigger Pin
#define ECHO_PIN D13    // HC-SR04 Echo Pin

enum State {
  WAITING_FOR_MOVEMENT,
  MOVEMENT_DETECTED,
  RESET_LEDGREEN2,
  REENABLE_SENSOR
};

State currentState = WAITING_FOR_MOVEMENT;
unsigned long previousMillis = 0;
const unsigned long LED_GREEN2_DURATION = 10000; // 10 seconds before Ledgreen2 turns ON again
const unsigned long SENSOR_REENABLE = 15000;     // 15 seconds before re-enabling movement detection

void setup() {
  pinMode(Ledred1, OUTPUT);
  pinMode(Ledyellow1, OUTPUT);
  pinMode(Ledgreen1, OUTPUT);
  pinMode(Ledred2, OUTPUT);
  pinMode(Ledgreen2, OUTPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Initial state: Ledred1 ON, Ledgreen2 ON
  digitalWrite(Ledred1, HIGH);
  digitalWrite(Ledyellow1, LOW);  // Not used but can be implemented
  digitalWrite(Ledgreen1, LOW);
  digitalWrite(Ledred2, LOW);
  digitalWrite(Ledgreen2, HIGH);

  Serial.begin(115200);
}

bool detectMovement() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.034 / 2; // Convert to cm

  return (distance > 0 && distance < 50); // Detect movement within 50cm
}

void loop() {
  unsigned long currentMillis = millis();

  switch (currentState) {
    case WAITING_FOR_MOVEMENT:
      if (detectMovement()) {
        Serial.println("Movement detected!");

        digitalWrite(Ledred1, LOW);    // Turn OFF Ledred1
        digitalWrite(Ledgreen1, HIGH); // Turn ON Ledgreen1
        digitalWrite(Ledgreen2, LOW);  // Turn OFF Ledgreen2
        digitalWrite(Ledred2, HIGH);   // Turn ON Ledred2

        currentState = MOVEMENT_DETECTED;
        previousMillis = currentMillis;
      }
      break;

    case MOVEMENT_DETECTED:
      if (currentMillis - previousMillis >= LED_GREEN2_DURATION) {
        digitalWrite(Ledgreen2, HIGH); // Turn Ledgreen2 back ON
        currentState = RESET_LEDGREEN2;
        previousMillis = currentMillis;
      }
      break;

    case RESET_LEDGREEN2:
      if (currentMillis - previousMillis >= SENSOR_REENABLE) {
        digitalWrite(Ledred1, HIGH);   // Turn Ledred1 back ON
        digitalWrite(Ledgreen1, LOW);  // Turn Ledgreen1 OFF
        digitalWrite(Ledred2, LOW);    // Turn Ledred2 OFF
        currentState = WAITING_FOR_MOVEMENT;
      }
      break;
  }
}
