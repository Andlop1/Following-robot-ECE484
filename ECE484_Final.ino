const int LWhFwdPin = 6;   // Left Wheel forward pin
const int LWhBwdPin = 5;  // Left Wheel backward pin
const int LWhPWMPin = A2;  // Left Wheel power pin
const int RWhFwdPin = 2;  // Right Wheel forward pin
const int RWhBwdPin = 4;  // Right Wheel backward pin
const int RWhPWMPin = A3;  // Right Wheel power pin
const int ultraTrigPin = 3; // Ultrasonic sensor trigger pin
const int ultraEchoPin = 7; // Ultrasonic sensor echo pin

int distance = 0;

void setup() {
  pinMode(LWhFwdPin, OUTPUT);
  pinMode(LWhBwdPin, OUTPUT);
  pinMode(LWhPWMPin, OUTPUT);
  pinMode(RWhFwdPin, OUTPUT);
  pinMode(RWhBwdPin, OUTPUT);
  pinMode(RWhPWMPin, OUTPUT);
  pinMode(ultraTrigPin, OUTPUT);
  pinMode(ultraEchoPin, INPUT);
  
  digitalWrite(LWhFwdPin, LOW);
  digitalWrite(LWhBwdPin, LOW);
  digitalWrite(RWhFwdPin, LOW);
  digitalWrite(RWhBwdPin, LOW);
}

void loop() {
  distance = getDistance();
  
  if (distance > 10) {
    moveForward();
  } else {
    stopMoving();
  }
}

void moveForward() {
  digitalWrite(LWhFwdPin, HIGH);
  digitalWrite(LWhBwdPin, LOW);
  digitalWrite(RWhFwdPin, HIGH);
  digitalWrite(RWhBwdPin, LOW);
  analogWrite(LWhPWMPin, 255);
  analogWrite(RWhPWMPin, 255);
}

void stopMoving() {
  digitalWrite(LWhFwdPin, LOW);
  digitalWrite(LWhBwdPin, LOW);
  digitalWrite(RWhFwdPin, LOW);
  digitalWrite(RWhBwdPin, LOW);
  analogWrite(LWhPWMPin, 0);
  analogWrite(RWhPWMPin, 0);
}

int getDistance() {
  digitalWrite(ultraTrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(ultraTrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultraTrigPin, LOW);
  
  int duration = pulseIn(ultraEchoPin, HIGH);
  int distance = duration * 0.034 / 2; // distance in centimeters
  
  return distance;
}

