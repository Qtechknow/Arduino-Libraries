/* Pineapple Demo

Demonstrates the use of the Pineapple library with a 74HC595 shift register and 
a 7-Segment display.  Credits for the library go to Quin, or Qtechknow, Adam 
Meyer of Bildr, and Arduino forum member lloyddean.

created on 18 Apr 2012
made by Qtechknow (Quin)
*/

#include "Pineapple.h"

int serial = 4;  // shifte register, serial pin
int registerClock = 3;  // shift register, register clock
int serialClock = 2;  // shift register, clock

int numberofRegisters = 1;    // how many registers?

Pineapple pineapple;     // initialize the library

void setup() {
  pineapple.segmentPins(0, 1, 2, 3, 4, 5, 6, 7, HIGH);  // set high for common anode, and low for common cathode
  pineapple.registerPins(serial, registerClock, serialClock, numberofRegisters);
}

void loop() {
  for(int i=0; i<10; i++) {
  pineapple.write(i);
  delay(500);
  }
}
