#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>

// RFID Module Pins (SPI)
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);

// LCD Display (Updated to Use Analog Pins)
LiquidCrystal lcd(A0, A1, 5, 4, 3, 2); // RS=A0, E=A1, D4=5, D5=4, D6=3, D7=2

// RGB LED Strip MOSFET Control Pins (Moved to Analog)
int redPin = A2;   // Red LED Channel
int greenPin = A3; // Green LED Channel

// Define the authorized RFID tag UID (Your tag UID)
byte authorizedUID[] = {0x07, 0x8E, 0x9F, 0xC8}; // Your RFID UID

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();

  // Set RGB control pins as output
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  // Initialize LCD
  lcd.begin(16, 2);
  
  // Start system in locked state
  lockSystem();
}

void loop() {
  // Check for RFID tag
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    if (isAuthorized()) {
      unlockSystem();  // If authorized, unlock
    } else {
      Serial.println("Unauthorized card detected.");
      lcdPrint("Access Denied");
      delay(2000);
      lockSystem();
    }
    mfrc522.PICC_HaltA();  // Stop scanning until next read
  }
}

// Function to check if the scanned tag matches the authorized UID
bool isAuthorized() {
  for (byte i = 0; i < 4; i++) {
    if (mfrc522.uid.uidByte[i] != authorizedUID[i]) {
      return false; // Not a match
    }
  }
  return true; // Match found
}

// Lock System (Red Light, "Locked" Display)
void lockSystem() {
  setColor(255, 0, 0); // Red
  lcdPrint("Locked");
}

// Unlock System (Green Light, "Unlocked" Display + Countdown)
void unlockSystem() {
  setColor(0, 255, 0); // Green
  lcdPrint("Unlocked");

  // Countdown from 10 to 0
  for (int i = 10; i >= 0; i--) {
    lcd.setCursor(0, 1);
    lcd.print("Timer: ");
    lcd.print(i);
    lcd.print("   ");  // Clear extra characters
    delay(1000);
  }

  lockSystem(); // Lock again after countdown
}

// Function to set LED Strip color
void setColor(int red, int green) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
}

// Function to update LCD text
void lcdPrint(String text) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(text);
}