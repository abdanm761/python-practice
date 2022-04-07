int echoPin = 2;
int trigPin = 3;
int redLed = 4;
int orangeLed = 5;

float duration;
float distance;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(orangeLed, OUTPUT);
    
  Serial.begin(9600);
}

void loop()
{
  //clears the trigpin condition
  digitalWrite(trigPin, LOW);
  delay(100);
  // stes the trigpin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delay(100);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  //calculating the distane
  distance = duration * 0.034 / 2;
  //displays the distance on the serial monitor
  Serial.print("distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  if (distance <= 50)
  {
    digitalWrite(orangeLed, LOW);
    delay(1000);
    digitalWrite(redLed, HIGH);
    delay(1000);
  }
  else if (distance >= 150)
  {
    digitalWrite(redLed, LOW);
    delay(100);
    digitalWrite(orangeLed, HIGH);
    delay(100);
  }
  else
  {
     digitalWrite(redLed, LOW);
    digitalWrite(orangeLed, LOW);
  }
}  

    
    