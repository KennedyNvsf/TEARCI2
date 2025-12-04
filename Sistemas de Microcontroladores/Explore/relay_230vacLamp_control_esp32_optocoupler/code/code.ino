const int relay = 25;  // GPIO 25 connected to optocoupler input

void setup() {
  Serial.begin(115200);
  pinMode(relay, OUTPUT);
}

void loop() {
  // Normally Open configuration, send HIGH signal to activate the relay (NPN logic)
  digitalWrite(relay, HIGH);
  Serial.println("Relay ON: Current Flowing");
  delay(5000);

  // Send LOW signal to deactivate the relay
  digitalWrite(relay, LOW);
  Serial.println("Relay OFF: Current not Flowing");
  delay(5000);
}
