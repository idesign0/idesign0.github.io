#include <Servo.h>

// including servo library

Servo servo1;
// define servo name

// initialize variables and define pins                                             
int x_pos;
int y_pos;

// Define pin for servo , define PWM pins
int servo1_pin = 6;  
int initial_position = 90; // defined initial position , wanted to rotate both side

// set initial numbers
int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;
int VRx = A1;
int VRy = A0;
int SW = 8;

void setup ( ) {
  Serial.begin (9600) ; // defining the input and output pins
  servo1.attach (servo1_pin ) ;
  servo1.write (initial_position);;
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP);                      
}

void loop ( ) {
  // cod is reading joystick x and y axis readings
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  SW_state = digitalRead(SW);

  
  // printing on serial monitor
  Serial.print("X: ");
  Serial.print(mapX);
  Serial.print(" | Y: ");
  Serial.print(mapY);
  Serial.print(" | Button: ");
  Serial.println(SW_state);

  delay(100);
  
  x_pos = analogRead (xPosition) ;    // reading position for servo controll               

    // below code deviding the values in two segments , (0,300) and (700,1023).
    
    // first part , lets say it is for rotation servo anti-clockwise code

    /* Below if position comes below 300 */
    if (x_pos < 300){
    if (initial_position < 10) { 
      } // first it will check it is below 10 or what , if it is it will do nothing and forward the loop
    else{ 
      
      /* else it will decreaseb the data by 10 , and new servo position will be available , this position values
        will be added or decrease depends on the readings
      */
      
      initial_position = initial_position - 10;
          servo1.write ( initial_position ) ; 
          delay (120) ; } 
      } 

      // second segment if values are greated then the 700 , it will run servo to rotate oposite side
      
    if (x_pos > 700){
    if (initial_position > 980)
    {  
    }  
    else{
          initial_position = initial_position + 10; // it wwill just increase the values
          servo1.write ( initial_position ) ;
          delay (120) ;
        }
     }  


 // same things for y

      if (y_pos < 300){
    if (initial_position < 10) { 
      }
    else{ initial_position = initial_position - 10;
          servo1.write ( initial_position ) ; 
          delay (120) ; } 
      } 
    if (y_pos > 700){
    if (initial_position > 180)
    {  
    }  
    else{
          initial_position = initial_position + 10;
          servo1.write ( initial_position ) ;
          delay (120) ;
        }
     }
     
} 
