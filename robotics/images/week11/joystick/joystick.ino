/* this code will help to get the x and y axis data from joystick , i have maped the readings in specific region , checkout on line 42 and 43 */



int VRx = A0; // variable VRx for x direction readings  
int VRy = A1; // variable for VRy direction readings
int SW = 8; // for switch       


// initialy kept zero


int xPosition = 0; 
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;

void setup() {
  Serial.begin(9600); 
  
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); 
  
}

void loop() {
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  SW_state = digitalRead(SW);

 // map function helps to change the analog read values in desirable way
 // in default it will give values between 0 and 1023 , but for joystick i may prefer values between the (-512,512),
 // it helps me to convert the range

// example
// mapX = map(variable,fromlower,fromhigh , tolower , tohigh)
// 0 converted into -512
// 1023 converted into 512
  
  mapX = map(xPosition, 0, 1023, -512, 512);
  mapY = map(yPosition, 0, 1023, -512, 512);

  //  for printing the values in serial

  Serial.print("X: ");
  Serial.print(mapX);
  Serial.print(" | Y: ");
  Serial.print(mapY);
  Serial.print(" | Button: ");
  Serial.println(SW_state);

  delay(100);
}
