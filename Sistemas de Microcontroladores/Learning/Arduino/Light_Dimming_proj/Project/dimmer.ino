//Reading Voltage

int readPin = A5;
float calcVal = 0;
  
void setup()
{
  pinMode(readPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  calcVal = (5. /1023. ) * (analogRead(readPin)); //convert from 0-1023 to 0-5v values
  Serial.println( calcVal);
}