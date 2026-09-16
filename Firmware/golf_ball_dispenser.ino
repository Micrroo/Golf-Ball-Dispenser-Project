#include <Servo.h>


int trigPin = 9;
int echoPin=8;
int servoPin=10;

long time;
float distance;
bool clubPresent = false;
unsigned long clubTime; // unsigned long because int cause negative overflow error after 32 seconds
unsigned long startTime; // unsigned long because value must match millis() value type



Servo myServo;


void setup() {
 Serial.begin(9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 myServo.attach(servoPin);
 myServo.write(0);
 

}

void loop() {
  

  Serial.print("Ready to Dispense");
  Serial.print('\n');

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  time = pulseIn(echoPin, HIGH);

  distance = (time *0.034) / 2; 


  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print('\n');

  

  
  if(distance < 10 ) {

    if (!clubPresent) {
      //club within threshold of 10 cm
      clubPresent = true;      
      startTime = millis(); // Starts timer for when club is within distance threshold
    }

   clubTime = millis() - startTime; // How long club has been countinously present within distance threshold 



    // Checks to see if club has been at distance threshold for longer than 2 seconds
    if(clubTime >= 2000) { 
    
      myServo.write(180);
      delay(500);
      myServo.write(0);

      Serial.print("Time Present: ");
      Serial.print(clubTime);
      Serial.print('\n');
      Serial.print("Ball Dispensing");
      Serial.print('\n'); 

      clubPresent = false;
      startTime = 0;
      } 


    else {
      Serial.print("Time Present: ");
      Serial.print(clubTime);
      Serial.print('\n');
      Serial.print("Longer Detection Needed");
      Serial.print('\n');

    } 
    
  }  
  else {

    clubPresent = false; 
    startTime = 0;
    Serial.print("Too Far Away");
    Serial.print('\n');


    }
  
  
  delay(500); // lets ultrasonic signals settle before next detection
