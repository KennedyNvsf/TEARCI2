// LED Controller Class
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
      digitalWrite(yellow1, LOW); // Not used in logic
      digitalWrite(green1, LOW);
      digitalWrite(red2, LOW);
      digitalWrite(green2, HIGH); // Initially ON
    }

    void turnOn(int led) {
      digitalWrite(led, HIGH);
    }

    void turnOff(int led) {
      digitalWrite(led, LOW);
    }
};

// Sensor Class
class Sensor {
  public:
    int trigger, echo;

    Sensor(int trig, int ech) {
      trigger = trig;
      echo = ech;
    }

    void begin() {
      pinMode(trigger, OUTPUT);
      pinMode(echo, INPUT);
    }

    bool detectMovement() {
      digitalWrite(trigger, LOW);
      delayMicroseconds(2);
      digitalWrite(trigger, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigger, LOW);

      long duration = pulseIn(echo, HIGH);
      float distance = duration * 0.034 / 2; // Convert to cm

      return (distance > 0 && distance < 10); // Detect movement within 10cm
    }
};

// Timer Class
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

// State Machine & Motion System Class
class MotionSystem {
  private:
    LEDController &leds;
    Sensor &sensor;
    Timer &timer;
    enum State { WAITING_FOR_MOVEMENT, MOVEMENT_DETECTED, RESET_LEDGREEN2, REENABLE_SENSOR };
    State currentState;

  public:
    MotionSystem(LEDController &ledControl, Sensor &sens, Timer &tim)
      : leds(ledControl), sensor(sens), timer(tim), currentState(WAITING_FOR_MOVEMENT) {}

    void update() {
      switch (currentState) {
        case WAITING_FOR_MOVEMENT:
          if (sensor.detectMovement()) {
            Serial.println("Movement detected!");

            leds.turnOff(leds.red1);    // Turn OFF Ledred1
            leds.turnOn(leds.green1);   // Turn ON Ledgreen1
            leds.turnOff(leds.green2);  // Turn OFF Ledgreen2
            leds.turnOn(leds.red2);     // Turn ON Ledred2

            currentState = MOVEMENT_DETECTED;
            timer.reset();
          }
          break;

        case MOVEMENT_DETECTED:
          if (timer.hasElapsed(timer.green2Duration)) {
            leds.turnOn(leds.green2);  // Turn Ledgreen2 back ON
            currentState = RESET_LEDGREEN2;
            timer.reset();
          }
          break;

        case RESET_LEDGREEN2:
          if (timer.hasElapsed(timer.sensorReenable)) {
            leds.turnOn(leds.red1);   // Turn Ledred1 back ON
            leds.turnOff(leds.green1);// Turn Ledgreen1 OFF
            leds.turnOff(leds.red2);  // Turn Ledred2 OFF
            currentState = WAITING_FOR_MOVEMENT;
          }
          break;
      }
    }
};

// Object Instantiation
LEDController leds(5, 6, 9, 10, 11);  // LED Pins
Sensor sensor(12, 13);                // Sensor Pins
Timer timer(10000, 15000);             // Timing Config
MotionSystem motionSystem(leds, sensor, timer); // Main System

void setup() {
  Serial.begin(9600);
  leds.begin();
  sensor.begin();
}

void loop() {
  motionSystem.update();
}
