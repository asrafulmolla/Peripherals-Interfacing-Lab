#include <Servo.h>

Servo myservo;

const int trigPin = 9;
const int echoPin = 10;
const int lightPin = 13;

long duration;
int distance;
int threshold = 20; 

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(lightPin, OUTPUT);

  myservo.attach(11);
  myservo.write(0); 
}

void loop() {
  // Trigger ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);


  duration = pulseIn(echoPin, HIGH);


  distance = duration * 0.034 / 2;

  // Check distance
  if (distance > 0 && distance <= threshold) {
    digitalWrite(lightPin, HIGH);   
    myservo.write(90);           
    delay(2000);                    
    myservo.write(0);              
    digitalWrite(lightPin, LOW);    
    delay(500);                    
  } else {
    digitalWrite(lightPin, LOW);
  }

  delay(200);
}

