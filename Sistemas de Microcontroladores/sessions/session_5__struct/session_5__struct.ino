typedef struct {
  int red1;
  int yellow1;
  int green1;
  int red2;
  int green2;
} LEDConfig;

typedef struct {
  int trigger;
  int echo;
} SensorConfig;

typedef struct {
  unsigned long previousMillis;
  const unsigned long green2Duration;
  const unsigned long sensorReenable;
} TimingConfig;

LEDConfig leds = {5, 6, 9, 10, 11};
SensorConfig sensor = {12, 13};
TimingConfig timing = {0, 10000, 15000};

enum State {
  WAITING_FOR_MOVEMENT,
  MOVEMENT_DETECTED,
  RESET_LEDGREEN2,
  REENABLE_SENSOR
};

State currentState = WAITING_FOR_MOVEMENT;

void setup() {
  pinMode(leds.red1, OUTPUT);
  pinMode(leds.yellow1, OUTPUT);
  pinMode(leds.green1, OUTPUT);
  pinMode(leds.red2, OUTPUT);
  pinMode(leds.green2, OUTPUT);
  pinMode(sensor.trigger, OUTPUT);
  pinMode(sensor.echo, INPUT);

  digitalWrite(leds.red1, HIGH);
  digitalWrite(leds.yellow1, LOW);
  digitalWrite(leds.green1, LOW);
  digitalWrite(leds.red2, LOW);
  digitalWrite(leds.green2, HIGH);

  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();

  switch (currentState) {
    case WAITING_FOR_MOVEMENT:
      if (detectMovement()) {
        Serial.println("Movement detected!");
        digitalWrite(leds.red1, LOW);
        digitalWrite(leds.green1, HIGH);
        digitalWrite(leds.green2, LOW);
        digitalWrite(leds.red2, HIGH);

        currentState = MOVEMENT_DETECTED;
        timing.previousMillis = currentMillis;
      }
      break;

    case MOVEMENT_DETECTED:
      if (currentMillis - timing.previousMillis >= timing.green2Duration) {
        digitalWrite(leds.green2, HIGH);
        currentState = RESET_LEDGREEN2;
        timing.previousMillis = currentMillis;
      }
      break;

    case RESET_LEDGREEN2:
      if (currentMillis - timing.previousMillis >= timing.sensorReenable) {
        digitalWrite(leds.red1, HIGH);
        digitalWrite(leds.green1, LOW);
        digitalWrite(leds.red2, LOW);
        currentState = WAITING_FOR_MOVEMENT;
      }
      break;
  }
}

bool detectMovement() {
  digitalWrite(sensor.trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(sensor.trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensor.trigger, LOW);

  long duration = pulseIn(sensor.echo, HIGH);
  float distance = duration * 0.034 / 2;

  return (distance > 0 && distance < 10); // Detect movement within 10cm
}
