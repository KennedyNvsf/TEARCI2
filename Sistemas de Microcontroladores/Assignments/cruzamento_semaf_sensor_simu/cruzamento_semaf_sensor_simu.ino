// LED Controller Class (unchanged)
class LEDController {
  public:
    int red1, yellow1, green1, red2, green2;

    LEDController(int r1, int y1, int g1, int r2, int g2) {
      red1 = r1;
      yellow1 = y1;
      green1 = g1;
      red2 = r2;
      green2 = g2;
    }

    void begin() {
      pinMode(red1, OUTPUT);
      pinMode(yellow1, OUTPUT);
      pinMode(green1, OUTPUT);
      pinMode(red2, OUTPUT);
      pinMode(green2, OUTPUT);

      digitalWrite(red1, HIGH);   // Initially ON
      digitalWrite(yellow1, LOW); // Unused
      digitalWrite(green1, LOW);
      digitalWrite(red2, LOW);
      digitalWrite(green2, HIGH); // Initially ON
    }

    void turnOn(int led) { digitalWrite(led, HIGH); }
    void turnOff(int led) { digitalWrite(led, LOW); }
};

// Button Class (replaces Sensor)
class Button {
  private:
    int buttonPin;
    unsigned long lastDebounceTime = 0;
    const unsigned long debounceDelay = 50;

  public:
    Button(int pin) : buttonPin(pin) {}

    void begin() {
      pinMode(buttonPin, INPUT_PULLUP);
    }

    bool detectMovement() {
      bool currentState = digitalRead(buttonPin);
      if (currentState == LOW) {
        if (millis() - lastDebounceTime > debounceDelay) {
          lastDebounceTime = millis();
          return true;
        }
      }
      return false;
    }
};

// Timer Class (unchanged)
class Timer {
  public:
    unsigned long previousMillis;
    const unsigned long green2Duration;
    const unsigned long sensorReenable;

    Timer(unsigned long green2Dur, unsigned long sensorReen)
      : green2Duration(green2Dur), sensorReenable(sensorReen) {
      previousMillis = 0;
    }

    bool hasElapsed(unsigned long interval) {
      return millis() - previousMillis >= interval;
    }

    void reset() {
      previousMillis = millis();
    }
};

// State Machine & Motion System (modified for button)
class MotionSystem {
  private:
    LEDController &leds;
    Button &button;
    Timer &timer;
    enum State { WAITING_FOR_MOVEMENT, MOVEMENT_DETECTED, RESET_LEDGREEN2 };
    State currentState;

  public:
    MotionSystem(LEDController &ledControl, Button &btn, Timer &tim)
      : leds(ledControl), button(btn), timer(tim), currentState(WAITING_FOR_MOVEMENT) {}

    void update() {
      switch (currentState) {
        case WAITING_FOR_MOVEMENT:
          if (button.detectMovement()) {
            Serial.println("Button pressed!");
            leds.turnOff(leds.red1);    // Turn OFF Red1
            leds.turnOn(leds.green1);   // Turn ON Green1
            leds.turnOff(leds.green2);  // Turn OFF Green2
            leds.turnOn(leds.red2);     // Turn ON Red2

            currentState = MOVEMENT_DETECTED;
            timer.reset();
          }
          break;

        case MOVEMENT_DETECTED:
          if (timer.hasElapsed(timer.green2Duration)) {

            leds.turnOff(leds.green1);
            leds.turnOn(leds.yellow1);  
            leds.turnOn(leds.yellow1);  
            
            currentState = RESET_LEDGREEN2;
            timer.reset();
          }
          break;

        case RESET_LEDGREEN2:
          if (timer.hasElapsed(timer.sensorReenable)) {
            leds.turnOn(leds.red1);    // Restore Red1
            leds.turnOff(leds.green1); // Turn OFF Green1
            leds.turnOff(leds.yellow1);
            leds.turnOff(leds.red2);   // Turn OFF Red2
            leds.turnOn(leds.green2);

            currentState = WAITING_FOR_MOVEMENT;
          }
          break;
      }
    }
};

// Initialize Components
LEDController leds(5, 6, 9, 10, 11); // LED pins
Button button(2);                     // Button on pin 2
Timer timer(10000, 15000);            // 10s (Green2), 15s (reset)
MotionSystem motionSystem(leds, button, timer);

void setup() {
  Serial.begin(9600);
  leds.begin();
  button.begin();
}

void loop() {
  motionSystem.update();
}