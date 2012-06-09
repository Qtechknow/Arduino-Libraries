/*  SodaSerial

When you type in a number between 0 and 9 on the serial monitor, the 7-segment
display, driven by the Soda library, will light up correspondingly. 

created 07 May 2012
made by Qtechknow (Quin)
*/

#include "Soda.h"

Soda Soda;      // initialize the library

void setup() {
// Segments A, B, C, D, E, F, G, DP pin numbers
  Soda.pins(0, 1, 2, 3, 4, 5, 6, 7, HIGH);    // set high for common anode, and
                                              // low for common cathode display
  Serial.begin(9600);   // start serial communication
}

void loop() {
  if(Serial.available() > 0) {    // is there anything on the serial monitor?
    char ch = Serial.read();
    
    switch  (ch) {      // start the switch case statement
     
      case '0':         // if we receive a 0, print a 0
      Soda.write(0);
      break;
      
      case '1':         // if we receive a 1, print a 1 and so on
      Soda.write(1);
      break;
      
      case '2':
      Soda.write(2);
      break;
      
      case '3':
      Soda.write(3);
      break;
      
      case '4':
      Soda.write(4);
      break;
      
      case '5':
      Soda.write(5);
      break;
      
      case '6':
      Soda.write(6);
      break;
      
      case '7':
      Soda.write(7);
      break;
      
      case '8':
      Soda.write(8);
      break;
      
      case '9':
      Soda.write(9);
      break;
      
      default:          // default is to clear the display
      Soda.clear();
    }
  }
  delay(1000);      // don't go too fast
}
