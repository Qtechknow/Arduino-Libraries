#include "Arduino.h"
#include "Soda.h"

void Soda.pins(int a, int b, int c, int d, int e, int f, int g, int dp) {
    
    const byte numeral[10] = {
        B11111100,  // 0
        B01100000,  // 1
        B11011010,  // 2
        B11110010,  // 3
        B01100110,  // 4
        B10110110,  // 5
        B10111110,  // 6
        B11100000,  // 7
        B11111110,  // 8
        B11100110,
    };
    
    const int segmentPins[8] = { dp, g, f, e, d, c, b, a };
    
}

void Soda.setup()  {
    
    for(int i=0; i < 8; i++) {
        
        pinMode(segmentPins[i], OUTPUT);
    }
}

void Soda.write(int number) {
    boolean isBitSet;
    
    for(int segment=1; segment < 8; segment++) {
        if(number < 0 || number > 9) {
            isBitSet = 0;
        }
        else{
            isBitSet = bitRead(numberal[number], segment);
        }
        isBitSet = ! isBitSet;
        digitalWrite(segmentPins[segment], isBitSet);
    }
}