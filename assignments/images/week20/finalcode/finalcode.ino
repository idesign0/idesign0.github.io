#pragma GCC optimize ("O2")
// for opti,ization of code

#include <SPI.h> // For SPI Pins add spi library
#include <MFRC522.h> // for setting RFID interface add MRFC522 library
#include <Ultrasonic.h> // for ultrasonic Add ultrasonic library
#include <Servo.h>  // add servo library

Servo myservo; // define servo
Ultrasonic ultrasonic(A4, A5) ; // define (trig,echo)

int pos = 160; // defined initial position of servo

int distance; //  defined distance for ultrasonic

// setting up interface for (PWM pins needed) for RFID , it will help in communicate
#define SS_PIN 10 //RX slave select 
#define RST_PIN 9 // rst pin 

MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance.

String card_ID=""; //card UID

//Add as many cards you want 
String Name1="14710721526";//first UID card
String Name2="21799093";//second UID card
String Name3="8159175206";//third UID card
String Name4="13937143185";//fourth UID card
String Name5="2174114201";// fifth UID
String Name6="254161178115";//and so on.

// Arrays to run rfid LOOP
int NumbCard[6];//the number of cards. in my case I have 6 cards.
int j=0;  //incresd by one for every user you add
int statu[6];//the number of cards. in my case I have 6 cards.
int s=0;  //incresd by one for every user you add


String Name;//user name
long Number;//user number
String ExcelName="Logs"; // given names
int L=0;
int n ;//The number of card you want to detect (optional)  
int ID=1;
void setup() {
  myservo.attach(5); // servo pin
 
  Serial.begin(9600); // Initialize serial communications with the PC
  SPI.begin();  // Init SPI bus
  mfrc522.PCD_Init(); // Init MFRC522 card

  // for excel sheet
  Serial.println("CLEARSHEET");                 // clears starting at row 1
  Serial.println("LABEL,ID,Date,Name,Number,Card ID,Time IN");// make four columns (Date,Time,[Name:"user name"],[Number:"user number"])

  delay(200); 
   }
   
void loop() {
    
  // Pass INC as a parameter to get the distance in inches
  distance = ultrasonic.read(); // getting distance
  //Serial.println("distance : ");
  if(distance>70 && distance<80)  //  and condition , if Distance is between 70 and 80 cm , servo will open 
  {
for (pos = 160; pos >= 80; pos -= 1) { // goes from 160 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);
    
  }
  delay(2000); // Flapper will open for 2 sec ,
  for (pos = 80; pos <= 160; pos += 1) { // goes from 0 degrees to 160 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);  
  } 
  }
  else
  {
     myservo.write(160);   // default position
    }
  // servo code ends now
  // RFID code will run now


  
  //look for new card , if card is not detected , code will return to loop start
   if ( ! mfrc522.PICC_IsNewCardPresent()) {
  return;//got to start of loop if there is no card present
 }
 // Select one of the cards // if card serial returns 0 then it will return to start of the loop
 if ( ! mfrc522.PICC_ReadCardSerial()) {
  return;//if read card serial(0) returns 1, the uid struct contians the ID of the read card.
 }

 for (byte i = 0; i < mfrc522.uid.size; i++) { // for running the loop equal to the card id 
     card_ID += mfrc522.uid.uidByte[i]; // getting the card id
 }
 
      Serial.println(card_ID); //Uncomment this line to scan the card ID and appear it on Serial monitor.

       if(card_ID==Name1){
       Name="Dhruv Patel";//user name
       Number=1;//user number
       j=0;//incresd by one for every user you add
       s=0;//++1
      }
      else if(card_ID==Name2){
       Name="Maharshi solanki ";//user name
       Number=2;//user number
       j=1;//++1
       s=1;//++1
      }
      else if(card_ID==Name3){
       Name="cido3";//user name
       Number=789101;//user number
       j=2;//++1
       s=2;//++1
      }
      else if(card_ID==Name4){
       Name="cido4";//user name
       Number=789101;//user number
       j=3;//++1
       s=3;//++1
      }
      else if(card_ID==Name5){
       Name="cido5";//user name
       Number=789101;//user number
       j=4;//++1
       s=4;//++1
      }
      else if(card_ID==Name6){
       Name="cido6";//user name
       Number=789101;//user number
       j=5;//incresd by one for every user you add
       s=5;//++1
      }
      else{ // code will jump below two loops is no conditions is fullfilled , suppose user is new or forgot to register
          goto cont;
     }
    

      if(NumbCard[j] == 1 && statu[s] == 0){
      statu[s]=1;
      NumbCard[j] = 0;
      Serial.print("DATA,");//send the Name to excel
      Serial.print(ID); // local ID
      Serial.print(",");
      Serial.print("DATE");
      Serial.print(",");
      Serial.print(Name); // Name of User
      Serial.print(",");
      Serial.print(Number); //send the Number to excel
      Serial.print(",");
      Serial.print(card_ID); //send the card ID to excel
      Serial.print(",");
      Serial.print("TIME");
      Serial.print(",");
      Serial.println("");
      ID=ID+1;
      n++;//(optional)
      }
      else if(NumbCard[j] == 0){
      NumbCard[j] = 1;
      statu[s]=0;
 
      Serial.print("DATA,");//send the Name to excel
      Serial.print(ID);
      Serial.print(",");
      Serial.print("DATE");
      Serial.print(",");
      Serial.print(Name);
      Serial.print(",");
      Serial.print(Number); //send the Number to excel
      Serial.print(",");
      Serial.print(card_ID); //send the card ID to excel
      Serial.print(",");
      Serial.print("TIME");
      Serial.print(",");
      Serial.println("");
      delay(30);
      ID=ID+1;
      }
      delay(1000);

cont:
delay(1000);
card_ID="";




//if you want to close the Excel when all card had detected and save Excel file in Names Folder. (optional)
//
//if(n==4){
//    ExcelName +=L;
//    L++;
//    Serial.print("SAVEWORKBOOKAS,");
//    Serial.print("Names/");
//    Serial.println(ExcelName);
//    //Serial.println("FORCEEXCELQUIT");
//    Serial.println("CLEARDATA");
//    n=0;
//    ID=1;
//    ExcelName="Logs";
//    }


delay(5000); // system will be freeze work for 5 sec


}
