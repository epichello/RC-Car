#include <AFMotor.h>  //Library for simplifying motor controls for arduino shields


AF_DCMotor front_left(4); //Numbers corresponds to M1, M2 etc. on the shield
AF_DCMotor front_right(3);  //AF_DCMotor type for variables
AF_DCMotor back_left(1);  
AF_DCMotor back_right(2);

void setup() {
  front_left.setSpeed(200); //max 255
  front_right.setSpeed(200);
  front_left.setSpeed(200);
  front_right.setSpeed(200);

  front_left.run(RELEASE);  //Sets motors to a stationary state
  front_right.run(RELEASE);
  front_left.run(RELEASE);
  front_right.run(RELEASE);
}

void loop() {

//variable.run(FORWARD); 
//variable.run(RELEASE);
//variable.run(BACKWARD);
//delay(1000); / 1000 ms = 1s
front_left.run(RELEASE);
}
