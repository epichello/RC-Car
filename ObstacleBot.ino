#include <AFMotor.h>  //Library for simplifying motor controls for arduino shields
#include <IRremote.h>

#define IR_RECIEVE_PIN 9  //macro, defines and replaces anything with name ir_receive_pin to 9 if any

// AF_DCMotor front_left(4); //Numbers corresponds to M1, M2 etc. on the shield
// AF_DCMotor front_right(3);  //AF_DCMotor type for variables
// AF_DCMotor back_left(1);  
// AF_DCMotor back_right(2);

void setup() {
  Serial.begin(9600); //Opens communication to computer's serial monitor
  IrReceiver.begin(IR_RECIEVE_PIN, ENABLE_LED_FEEDBACK); //starts the receiver on pin 9, LED feedback makes uno blink everytime a signal is receive

  // front_left.setSpeed(200); //max 255
  // front_right.setSpeed(200);
  // back_left.setSpeed(200);
  // back_right.setSpeed(200);

  // front_left.run(RELEASE);  //Sets motors to a stationary state
  // front_right.run(RELEASE);
  // back_left.run(RELEASE);
  // back_right.run(RELEASE);

  // front_right.run(FORWARD);
  // front_left.run(FORWARD);
  // back_left.run(FORWARD);
  // back_right.run(FORWARD);
  // delay(15000);
  // front_right.run(RELEASE);
  // front_left.run(RELEASE);
  // back_left.run(RELEASE);
  // back_right.run(RELEASE);
}

void loop() {
if (IrReceiver.decode())  //checks for ir signal 
{   
  Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); //print line convers to hex_decimal something like "FF629D"
  IrReceiver.printIRResultShort(&Serial); //Protocol e.g sony or samsung
  IrReceiver.printIRSendUsage(&Serial); //gives line of code if you wanted an arduino to output the same ir
  IrReceiver.resume(); // Receive the next value
}
//variable.run(FORWARD); 
//variable.run(RELEASE);
//variable.run(BACKWARD);
//delay(1000); / 1000 ms = 1s
}
