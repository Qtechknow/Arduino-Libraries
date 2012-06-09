/* Dice Sketch

Uses the Soda library to drive a 7-segment display.  When you press the button
on D5, the 7-segment display flickers and then displays a random number.
Credits go to Qtechknow (Quin), Adam Meyer of Bildr, and Arduino Forum member
lloyddean.

created 07 May 2012
made by Qtechknow (Quin)
*/

#include "Pineapple.h"

Pineapple pineapple;      // initialize the library

int buttonVal;            // variable to store our button state

int randomNumber;         // random number variable
int serial = 4;           // serial pin
int registerClock = 3;    // register clock pin
int serialClock = 2;      // serial clock pin

int numberofRegisters = 1;   // how many registers are on the chain?

void setup() {
            // Segments A, B, C, D, E, F, G, DP pin numbers
  pineapple.segmentPins(0, 1, 2, 3, 4, 5, 6, 7, HIGH);  // set high for common anode, and 
  pineapple.registerPins(serial, registerClock, serialClock, numberofRegisters);                                          // low for common cathode display

  randomSeed(analogRead(1));   // float the random value
}

void loop() {
  buttonVal=analogRead(0);     // assign the integer
  pineapple.clear();           // clear the display before writing
  
  if(buttonVal >= HIGH) {      // if the button is pressed,
     
     pineapple.flicker();    // flicker the display
     
     randomNumber = random(1, 7);    // assign a random number inbetween 1 and 6
     pineapple.write(randomNumber);  // write the number
     delay(100);
  }
}
