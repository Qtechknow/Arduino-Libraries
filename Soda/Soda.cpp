#include "Arduino.h"
#include "Soda.h"

void Soda::pins(int a, int b, int c, int d, int e, int f, int g, int dp, boolean common) {
    
    _a=a;
    _b=b;
    _c=c;
    _d=d;
    _e=e;
    _f=f;
    _g=g;
    _dp=dp;
    _common=common;
    
    segmentPins[0] = _dp;
    segmentPins[1] = _g;
    segmentPins[2] = _f;
    segmentPins[3] = _e;
    segmentPins[4] = _d;
    segmentPins[5] = _c;
    segmentPins[6] = _b;
    segmentPins[7] = _a;
    
    for(int i=0; i < 8; i++) {
        
        pinMode(segmentPins[i], OUTPUT);
    }
}

void Soda::write(int number) {
    
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

void Soda::setDecimalPoint(int digit, boolean decimalState) {
    
    _digit=digit;
    _decimalState=decimalState;

    if(_digit == 1) {
        
        if (_decimalState == HIGH && _common == HIGH) {
            write(_dp, LOW);
        }
        if (_decimalState == HIGH && _common == LOW) {
            write(_dp, HIGH);
        }
        if (_decimalState == LOW && _common == HIGH) {
            write(_dp, HIGH);
        }
        if (_decimalState == LOW && _common == LOW) {
            write(_dp, LOW);
        }  
    }
}