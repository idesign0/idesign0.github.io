int led=2;
int button=3;

void setup(){
pinMode(led,OUTPUT);
pinMode(button, INPUT);
}



void loop(){
  if( digitalRead(button) == LOW){
  digitalWrite(led,HIGH);
  delay(100);
  digitalWrite(led,LOW);
  delay(100);
}
else{
   digitalWrite(led,HIGH);
  delay(800);
  digitalWrite(led,LOW);
  delay(800);
}
}
