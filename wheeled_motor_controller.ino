/*
 * Generic Serial Motor Controller
 *
 * Copyright 2012 Joe Bowser
 * <bowserj@gmail.com>
 */
 
 #include <AFMotor.h>
 
 AF_DCMotor left_motor(3);
 AF_DCMotor right_motor(4);
 
 String inputString = "";
 boolean stringComplete;
 
 void setup()
 {
   Serial.begin(57600);
   Serial.println("Motor Controller Start");
   // reserve 200 bytes for the inputString:
   inputString.reserve(200);
 }
 
 void loop()
 {
   
 }
 
 /*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      if(inputString.startsWith('left', 0))
      {
        //Set the directions
        left_motor.run(FORWARD);
        right_motor.run(BACKWARD);    
      }
      else if(inputString.startsWith('right', 0))
      {
        //Set the directions
        left_motor.run(FORWARD);
        right_motor.run(BACKWARD);    
      }
      else if(inputString.startsWith('fwd', 0))
      {
        //Set the directions
        left_motor.run(FORWARD);
        right_motor.run(FORWARD);        
      }
      else if(inputString.startsWith('back', 0))
      {
        //Set the directions
        left_motor.run(FORWARD);
        right_motor.run(FORWARD);
      } 
    } 
  }
}

