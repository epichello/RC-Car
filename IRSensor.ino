#include <AFMotor.h>  //Library for simplifying motor controls for arduino shields
#include <IRremote.h>

#define IR_RECIEVE_PIN 9  //macro, defines and replaces anything with name ir_receive_pin to 9 if any

AF_DCMotor left_side(4); //Numbers corresponds to M1, M2 etc. on the shield
AF_DCMotor right_side(3);  //AF_DCMotor type for variables

enum directions : unsigned long
{
  IR_NONE = 0, //nothing state to control movement
  IR_OFF = 4244768519,
  IR_LEFT = 2590312199,
  IR_FORWARD = 2673870599,
  IR_RIGHT = 2640447239,
  IR_BACKWARD = 2657158919,
  IR_STOP = 2540177159
};

directions ir_sensor_data(directions &data)
{
  if (IrReceiver.decode())  //checks for ir signal 
  {   
    Serial.println(IrReceiver.decodedIRData.decodedRawData); //print line convers to hex_decimal something like "FF629D"
    // IrReceiver.printIRResultShort(&Serial); //Protocol e.g sony or samsung
    // IrReceiver.printIRSendUsage(&Serial); //gives line of code if you wanted an arduino to output the same ir
    data = IrReceiver.decodedIRData.decodedRawData;
    IrReceiver.resume(); // Receive the next value
    return directions(data);
  }
}

void setup() {
  Serial.begin(9600); //Opens communication to computer's serial monitor
  IrReceiver.begin(IR_RECIEVE_PIN, ENABLE_LED_FEEDBACK); //starts the receiver on pin 9, LED feedback makes uno blink everytime a signal is receive
  
  left_side.setSpeed(255); //max 255
  right_side.setSpeed(255);
}

void loop() {
  directions ir_data;
  do{
    ir_sensor_data(ir_data);
    switch(ir_data)
    {
      case IR_RIGHT:
      {
        left_side.run(FORWARD);
        right_side.run(BACKWARD);
        // delay(100);
        ir_data = IR_NONE; 
        // left_side.run(RELEASE);
        // right_side.run(RELEASE);
        break;
      }
      case IR_LEFT:
      {
        left_side.run(BACKWARD);
        right_side.run(FORWARD);
        // delay(100);
        ir_data = IR_NONE; 
        // left_side.run(RELEASE);
        // right_side.run(RELEASE);
        ir_data = IR_NONE;
        break;
      }
      case IR_FORWARD:
      {
        left_side.run(FORWARD);
        right_side.run(FORWARD);
        // delay(100);
        ir_data = IR_NONE; 
        //left_side.run(RELEASE);
        //right_side.run(RELEASE);
        ir_data = IR_NONE;
        break;
      }
      case IR_BACKWARD:
      {
        left_side.run(BACKWARD);
        right_side.run(BACKWARD);
        // delay(100);
        ir_data = IR_NONE; 
        // left_side.run(RELEASE);
        // right_side.run(RELEASE);
        break;
      }
      case IR_STOP:
      {
        left_side.run(RELEASE);
        right_side.run(RELEASE);
        ir_data = IR_NONE;
      }
    }
  }while(ir_data != IR_OFF);
  Serial.println("Control disconnected; press reset to restart");
}
