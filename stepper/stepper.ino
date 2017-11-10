#include <AccelStepper.h>


// Define a stepper motor 1 for arduino 
// direction Digital 10 (CW), pulses Digital 8 (CLK)
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
AccelStepper stepper(1, 8, 10);
void setup()
{  
  // Change these to suit your stepper if you want
  stepper.setMaxSpeed(600);//1100
  stepper.setAcceleration(1100);
  myservo.attach(9);  // attaches the servo on pin 11 to the servo object
}

void loop()
{
    ascend(myservo);
    descend(myservo);
    fill(stepper);
    ascend(myservo);
    descend(myservo);
    empty(stepper);
}
void descend(Servo myServo){
  for (pos = 10; pos <= 170; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(2000);
}
void ascend(Servo myServo){
  for (pos = 170; pos >= 10; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(2000);
}
void fill(AccelStepper myStepper){
  myStepper.moveTo(stepper.currentPosition() + 20);
  while(myStepper.distanceToGo() != 0){
    myStepper.run();
  }
}
void empty(AccelStepper myStepper){
  myStepper.moveTo(stepper.currentPosition() - 100);
  while(myStepper.distanceToGo() != 0){
    myStepper.run();
  }
}

