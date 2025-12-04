
int Delay5 = 5000;
int Delay3 = 3000;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop()
{
  digitalWrite(13, HIGH); //Red Light On
  
  delay(Delay5); // Wait for 5 second(s)
  
  digitalWrite(13, LOW);//Red Light Off
  digitalWrite(12, HIGH);//yellow Light On
  
  delay(Delay5); // Wait for 5 second(s)
  
  digitalWrite(12, LOW);//Yellow Light Off
  digitalWrite(8, HIGH);//Green Light On
  
  delay(Delay3);// Wait for 3 second(s)
   digitalWrite(8, LOW);//Green Light Off
}