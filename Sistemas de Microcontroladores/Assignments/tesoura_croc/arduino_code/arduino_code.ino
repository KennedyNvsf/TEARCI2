//Crocodile scissor By Kennedy Freitas
#include <Servo.h>  // Include the Servo library

Servo myServo;     // Create a Servo object to control the motor
const int buttonPin = 2;  // Pin connected to the button
int buttonState = 0;      // Variable to hold the button state
int prevButtonState = 0;  // Variable to hold the previous button state

// LED Pins
const int greenLedPin = 3;   // Green LED for opening
const int redLedPin = 4;     // Red LED for closing
const int yellowLedPin = 5;  // Yellow LED for stopped

void setup() {
  myServo.attach(9);    // Pin 9 is connected to the servo's signal pin
  pinMode(buttonPin, INPUT_PULLUP);  // Set the button pin as input with internal pull-up resistor

  // Set LED pins as output
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);  // Read the state of the button

  if (buttonState == LOW) {  // Button is pressed (LOW because of the pull-up configuration)
  
    myServo.write(0);  // Close the "crocodile mouth"
    digitalWrite(greenLedPin, LOW);  // Turn off Green LED
    digitalWrite(redLedPin, LOW);   // Turn off Red LED
    digitalWrite(yellowLedPin, HIGH); // Turn on Yellow LED (stopped)

  } else {  // Button is not pressed
    // Continuously open and close the mouth (servo moves between 0 and 180 degrees)
    for (int pos = 0; pos <= 180; pos++) {
      myServo.write(pos);   // Move the servo to the current position
      digitalWrite(greenLedPin, HIGH); // Turn on Green LED (opening)
      digitalWrite(redLedPin, LOW);    // Turn off Red LED
      digitalWrite(yellowLedPin, LOW); // Turn off Yellow LED
      delay(15);            // Wait for the servo to reach the position
    }
    for (int pos = 180; pos >= 0; pos--) {
      myServo.write(pos);   // Move the servo to the current position
      digitalWrite(greenLedPin, LOW);  // Turn off Green LED
      digitalWrite(redLedPin, HIGH);   // Turn on Red LED (closing)
      digitalWrite(yellowLedPin, LOW); // Turn off Yellow LED
      delay(15);            // Wait for the servo to reach the position
    }
  }

  // Prevent flickering if the button is pressed and released quickly
  if (buttonState != prevButtonState) {
    delay(50);  // Debounce delay
  }

  prevButtonState = buttonState;  // Update previous button state
}
