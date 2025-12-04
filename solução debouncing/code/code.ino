//Kennedy Freitas
//Controlo de Relés com Arduino Uno para acionamento de sinalizador 230vac a partir de butões
//solução para Mitigar Debouncing

const int relay = 7;
const int buttonOn = 2;
const int buttonOff = 3;

bool lastButtonOnState = HIGH;
bool lastButtonOffState = HIGH;

void setup() {
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
  pinMode(buttonOn, INPUT_PULLUP);
  pinMode(buttonOff, INPUT_PULLUP);
  digitalWrite(relay, HIGH);  // Start with relay OFF
}

void loop() {
  bool currentOn = digitalRead(buttonOn);
  bool currentOff = digitalRead(buttonOff);

  if (lastButtonOnState == HIGH && currentOn == LOW) {
    digitalWrite(relay, LOW);
    Serial.println("Relay ON: Current Flowing");
    delay(50); // debounce
  }

  if (lastButtonOffState == HIGH && currentOff == LOW) {
    digitalWrite(relay, HIGH);
    Serial.println("Relay OFF: Current not Flowing");
    delay(50); // debounce
  }

  lastButtonOnState = currentOn;
  lastButtonOffState = currentOff;

  delay(10); // Short delay to reduce CPU usage
}
