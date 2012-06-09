/*  PineappleSerial

When you type in a number between 0 and 9 on the serial monitor, the 7-segment
display, driven by the Pineapple library, will light up correspondingly. 
Credits go to Qtechknow (Quin), Adam Meyer of Bildr, and Arduino Forum member
lloyddean.

created 08 May 2012
made by Qtechknow (Quin)
*/

#include "Pineapple.h"

Pineapple pineapple;      // initialize the library

int serial = 4;              // serial pin
int registerClock = 3;       // register clock pin
int serialClock = 2;         // serial clock pin

int numberofRegisters = 1;   // just one register

void setup() {
// Segments A, B, C, D, E, F, G, DP pin numbers on the shift register
  pineapple.segmentPins(0, 1, 2, 3, 4, 5, 6, 7, HIGH);  // set high for common anode, and
  pineapple.registerPins(serial, registerClock, serialClock, numberofRegisters);    // low for common cathode display
  Serial.begin(9600);     // begin serial communication
} 

void loop() {
  
  pineapple.clear();
  
  if(Serial.available() > 0) {    // is there anything on the serial monitor?
    char ch = Serial.read();

    switch (ch) {        // start the switch case statement
     
      case '0':            // if we receive a 0, print a 0
      pineapple.write(0);
      break;
      
      case '1':
      pineapple.write(1);  // if we receive a 1, print a 1
      break;
      
      case '2':            // if we receive a 2, print a 2 and so on.
      pineapple.write(2);
      break;
      
      case '3':
      pineapple.write(3);
      break;
      
      case '4':
      pineapple.write(4);
      break;
      
      case '5':
      pineapple.write(5);
      break;
      
      case '6':
      pineapple.write(6);
      break;
      
      case '7':
      pineapple.write(7);
      break;
      
      case '8':
      pineapple.write(8);
      break;
      
      case '9':
      pineapple.write(9);
      break;
      
      default:             // default is to clear the display
      pineapple.clear();
    }
  }
  delay(1000);       // don't go too fast!
}
