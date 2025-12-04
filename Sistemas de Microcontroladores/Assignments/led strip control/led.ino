#include <LiquidCrystal.h>

// Initialize LCD (Crystal Ball Example Wiring)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Define MOSFET control pins for Red, Green, and Blue channels
int redPin = 9;
int greenPin = 10;
int bluePin = 6;  

void setup() {
  // Set RGB control pins as output
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Initialize LCD
  lcd.begin(16, 2);
  delay(500);  // Add this delay to ensure proper initialization
  lcdPrint("Starting...");
}

void loop() {
  // Fade to Red
  lcdPrint("Color: RED");
  fadeToColor(redPin, 255, greenPin, 0, bluePin, 0);
  delay(1000);

  // Fade to Green
  lcdPrint("Color: GREEN");
  fadeToColor(redPin, 0, greenPin, 255, bluePin, 0);
  delay(1000);

  // Fade to Blue
  lcdPrint("Color: BLUE");
  fadeToColor(redPin, 0, greenPin, 0, bluePin, 255);
  delay(1000);
}

// Function to fade to a specified color
void fadeToColor(int redPin, int redValue, int greenPin, int greenValue, int bluePin, int blueValue) {
  for (int i = 0; i <= 255; i++) {
    analogWrite(redPin, map(i, 0, 255, 0, redValue));
    analogWrite(greenPin, map(i, 0, 255, 0, greenValue));
    analogWrite(bluePin, map(i, 0, 255, 0, blueValue));
    delay(10);  // Adjust fade speed
  }
}

// Function to update LCD text
void lcdPrint(String text) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(text);
}
