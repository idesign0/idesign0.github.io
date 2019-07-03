/* this code will help to print the distance from the data to serial monitor , readings will be taken by ultrasonic sensor*/


#include <Ultrasonic.h>
// ULTRASONIC LIBRARY

#include <SoftwareSerial.h>
// include SOFTWERE SERIAL library above, with softwere serial any two I/O pins can be run as Rx , Tx

SoftwareSerial mySerial(0, 1); // RX, TX // to send and receive the data to serial port(Monitor)
Ultrasonic ultrasonic(A5, A4); // ultrasonic pins defined ( triger(5) and echo(4)) , echo pin will send sound waves and triger will receive sound signals

int distance; // defining variable

void setup() 
{
 pinMode(2,OUTPUT); 
  mySerial.begin(9600);
}

void loop() {
  // Pass INC as a parameter to get the distance in inches
  distance = ultrasonic.read(); // reading values
  
  mySerial.print("Distance in CM: ");
  mySerial.println(distance); // printing distance on serial
  delay(1000);

  // if else condition , if condition is fulfilled then , led will High , if no it will be low.
  if(distance <= 50) 
  {
    digitalWrite(2,HIGH);
  }
  else
  {
    digitalWrite(2,LOW);
  }
}
