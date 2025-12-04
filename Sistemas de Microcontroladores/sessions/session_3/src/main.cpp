#include <Arduino.h>

#define LED1_RED_GREEN  4  // First LED (Red/Green)
#define LED2_RED_GREEN  16  // Second LED (Red/Green)
#define LED3_GY_RED     17  // Third LED (Green/Yellow/Red)

// Enum to represent LED states
enum LedState {
  GREEN_STATE,
  YELLOW_STATE,
  RED_STATE
};

LedState currentState = GREEN_STATE;  // Initial state is Green

void setup() {
  pinMode(LED1_RED_GREEN, OUTPUT);
  pinMode(LED2_RED_GREEN, OUTPUT);
  pinMode(LED3_GY_RED, OUTPUT);

  // Initial state: LED3 Green, LED1 and LED2 Red
  setLedState(currentState);
}

void loop() {
  switch (currentState) {
    case GREEN_STATE:
      delay(10000);  // Wait for 10 seconds
      currentState = YELLOW_STATE;  // Transition to Yellow
      setLedState(currentState);
      break;

    case YELLOW_STATE:
      delay(5000);  // Wait for 5 seconds
      currentState = RED_STATE;  // Transition to Red
      setLedState(currentState);
      break;

    case RED_STATE:
      // LEDs stay in their final red state, no further actions needed
      break;
  }
}

void setLedState(LedState state) {
  switch (state) {
    case GREEN_STATE:
      digitalWrite(LED1_RED_GREEN, HIGH);  // LED1 Red ON
      digitalWrite(LED2_RED_GREEN, HIGH);  // LED2 Red ON
      digitalWrite(LED3_GY_RED, HIGH);    // LED3 Green ON
      break;

    case YELLOW_STATE:
      digitalWrite(LED1_RED_GREEN, HIGH);  // LED1 Red ON
      digitalWrite(LED2_RED_GREEN, HIGH);  // LED2 Red ON
      digitalWrite(LED3_GY_RED, LOW);     // LED3 Green OFF
      delay(100);                         // Small delay to avoid flicker
      digitalWrite(LED3_GY_RED, HIGH);    // LED3 Yellow ON
      break;

    case RED_STATE:
      digitalWrite(LED1_RED_GREEN, LOW);   // LED1 Green ON
      digitalWrite(LED2_RED_GREEN, LOW);   // LED2 Green ON
      digitalWrite(LED3_GY_RED, LOW);     // LED3 Red ON
      break;
  }
}
