//master code:

#include <Wire.h> // for i2c include wire library
int touch = A0;

void setup() { // setting up board rate and I/Os
  Serial.begin(9600);
  pinMode(touch,INPUT);
  pinMode(13,OUTPUT);
  Wire.begin(); // for i2c
}

void loop()
{
int a = analogRead(touch); // reading values
Serial.println(a); // for getting idea in serial monitor
if ( a >=500) // if condition , if i touch the sensor , its analog value will be greagter then 500
{
  digitalWrite(13,HIGH); // another signal of working of touch sensor
   Wire.beginTransmission(9); //slace number 8 // transmitting Address '9' though SDA  to slave
    Wire.write(1); // will give message of '1'
    Wire.endTransmission(); // end the transmition
    delay(200); 
}
else
{digitalWrite(13,LOW);
   Wire.beginTransmission(9);
    Wire.write(0); // if condition is not satisfy it will give '0' on message
    Wire.endTransmission();
    //delay(200);
}

  
}
