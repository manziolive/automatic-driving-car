# automatic-driving-car
self driven by motor driver with ultrasonic sensor
#include <Servo.h>          //standard library for the servo
#include <NewPing.h>        //for the Ultrasonic sensor function library.

//L298N motor control pins
const int LeftMotorForward = 9;
const int LeftMotorBackward = 11;
const int RightMotorForward = 10;
const int RightMotorBackward = 8;

//sensor pins
#define trig_pin A5 //analog input 1
#define echo_pin A6 //analog input 2

#define maximum_distance 200
boolean goesForward = false;
int distance = 100;

NewPing sonar(trig_pin, echo_pin, maximum_distance); //sensor function
Servo servo_motor;

void setup() {

  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  Serial.begin(9600);

  servo_motor.attach(7); //our servo pin

  servo_motor.write(51);
  moveStop();
  delay(2000);
  distance = readPing();
  delay(100); 
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop() {

  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);
  Serial.println(distance);

  if (distance <= 20) {

    moveStop();
    delay(500);
    moveBackward();
    delay(500);
    moveStop();
    delay(500);
    distanceRight = lookRight();
    delay(50);
    distanceLeft = lookLeft();
    delay(50);

    if (distance >= distanceLeft) {
      turnRight();
      moveStop();
    }
    else {
      turnLeft();
      moveStop();
    }
  }
  else {
    moveForward();
  }
  distance = readPing();
}

int lookRight() {
  servo_motor.write(0);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(51);
  return distance;
}

int lookLeft() {
  servo_motor.write(140);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(51);
  return distance;
  delay(100);
}

int readPing() {
  delay(70);
  int cm = sonar.ping_cm();
  if (cm == 0) {
    cm = 100;
  }
  return cm;
}

void moveStop() {

  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

void moveForward() {

  if (!goesForward) {

    goesForward = true;

    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);

    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW);
  }
}

void moveBackward() {

  goesForward = false;

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);

  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);

}

void turnRight() {
  digitalWrite(RightMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  delay(380);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
}

void turnLeft() {
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, HIGH);
  delay(380);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}
