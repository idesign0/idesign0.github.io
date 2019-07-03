#include <Wire.h> // wire library
#include <Servo.h> // servo library

int d1=0; // initialize d1
Servo myservo;

void setup() {
  pinMode(13,OUTPUT);
  myservo.attach(5); 
  Serial.begin(9600);
  Wire.begin(9);     //address of the slave
  Wire.onReceive(recieveEvent); // will create recieve event
}

void loop() {

  if (d1 == 1) // if touch sensor is detecting something , master will write '1' and it will be sent to slave , see recieveevent below
    {
      digitalWrite(13, HIGH);
      myservo.write(180); // servo will go to 180
    } else if (d1 == 0)
    {
      digitalWrite(13, LOW);
      myservo.write(0); // if not it will go to 0
    } else
    {
     
    }

  
  delay(200);
}

// recieveevent : it will define d1's value
void recieveEvent(int howMany)
{
  while (Wire.available()) // if so0methoing is available
  {
    d1 = Wire.read(); // d1 will be equal to '1' or '0' depends on data written on slave by master
  }
}
