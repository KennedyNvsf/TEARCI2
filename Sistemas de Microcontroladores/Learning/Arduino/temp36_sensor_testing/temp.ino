const int sensorPin = A0;
const float baselineTemp = 20.0;

void setup() {
  Serial.begin(9600); // Initialize serial communication

  for (int pin = 2; pin < 5; pin++) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }
}

void loop() {
  // Read and convert sensor value
  int sensorVal = analogRead(sensorPin); // Read from A0 (0-1023)
  float voltage = sensorVal * (5.0 / 1023.0); // Convert ADC value to voltage
  float temperature = (voltage - 0.5) * 100; // Convert voltage to temperature (TMP36)

  // Print values
  Serial.print("Sensor Value: "); Serial.print(sensorVal);
  Serial.print(", Volts: "); Serial.print(voltage, 2); // 2 decimal places
  Serial.print(", degrees C: "); Serial.println(temperature, 2);

  // Control LEDs based on temperature
  digitalWrite(2, temperature >= baselineTemp);
  digitalWrite(3, temperature >= baselineTemp + 2);
  digitalWrite(4, temperature >= baselineTemp + 4);

  delay(500); // Allow time for readings to stabilize
}
