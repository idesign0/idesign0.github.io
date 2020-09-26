#include <Servo.h>

Servo servo1;
Servo servo2;
int x_key = A1;                                               
int y_key = A0;                                               
int x_pos;
int y_pos;
int servo1_pin = 6;
int servo2_pin = 9;  
int initial_position = 90;
int initial_position1 = 90;
int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;
int VRx = A1;
int VRy = A0;
int SW = 8;

void setup ( ) {
Serial.begin (9600) ;
servo1.attach (servo1_pin ) ; 
servo2.attach (servo2_pin ) ; 
servo1.write (initial_position);
servo2.write (initial_position1);
pinMode (x_key, INPUT) ;                     
pinMode (y_key, INPUT) ;
  Serial.begin(9600); 
  
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP);                      
}

void loop ( ) {
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  SW_state = digitalRead(SW);
  mapX = map(xPosition, 0, 1023, -512, 512);
  mapY = map(yPosition, 0, 1023, -512, 512);
  
  Serial.print("X: ");
  Serial.print(mapX);
  Serial.print(" | Y: ");
  Serial.print(mapY);
  Serial.print(" | Button: ");
  Serial.println(SW_state);

  delay(100);
x_pos = analogRead (x_key) ;  
//y_pos = analogRead (y_key) ;                      

if (x_pos < 300){
if (initial_position < 10) { } else{ initial_position = initial_position - 10; servo1.write ( initial_position ) ; delay (120) ; } } if (x_pos > 700){
if (initial_position > 180)
{  
}  
else{
initial_position = initial_position + 10;
servo1.write ( initial_position ) ;
delay (120) ;
}
}

if (y_pos < 300){
if (initial_position1 < 10) { } else{ initial_position1 = initial_position1 - 20; servo2.write ( initial_position1 ) ; delay (100) ; } } if (y_pos > 700){
if (initial_position1 > 180)
{  
}        
else{
initial_position1 = initial_position1 + 20;
servo2.write ( initial_position1 ) ;
delay (100) ;
}
}
}
