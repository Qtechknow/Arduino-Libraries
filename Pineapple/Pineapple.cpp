#include "Pineapple.h"

#if ARDUINO >= 100     // Arduino 1.0 and 0023 compatible!
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

uint8_t Pineapple::registerPins(int SER_Pin, int RCLK_Pin, int SRCLK_Pin, int Number_of_Registers) {
    _SER_Pin = SER_Pin;
    _RCLK_Pin = RCLK_Pin;
    _SRCLK_Pin = SRCLK_Pin;
    
    _Number_of_Registers = Number_of_Registers;
	
	pinMode(_SER_Pin, OUTPUT);
	pinMode(_RCLK_Pin, OUTPUT);
	pinMode(_SRCLK_Pin, OUTPUT);
	
	clear(); //reset all register pins
	update();
}

void Pineapple::update(){
	//Set and display registers
	//Only call AFTER all values are set how you would like (slow otherwise)
    
    digitalWrite(_RCLK_Pin, LOW);
    
    //iterate through the registers
    for(int i = _Number_of_Registers - 1; i >=  0; i--){
        
        //iterate through the bits in each registers
        for(int j = 8 - 1; j >=  0; j--){
            
            digitalWrite(_SRCLK_Pin, LOW);
            
            int val = _shiftRegisters[i] & (1 << j);
            
            digitalWrite(_SER_Pin, val);
            digitalWrite(_SRCLK_Pin, HIGH);
            
        }
        
    }
    
    digitalWrite(_RCLK_Pin, HIGH);
}

void Pineapple::setPin(int index, boolean val){
	int byteIndex = index/8;
	int bitIndex = index % 8;
	
	byte current = _shiftRegisters[byteIndex];
	
	current &= ~(1 << bitIndex); //clear the bit
	current |= val << bitIndex; //set the bit
	
	_shiftRegisters[byteIndex] = current; //set the value
}

void Pineapple::setAll(boolean val){
    //set all register pins to LOW
    for(int i = _Number_of_Registers * 8 - 1; i >=  0; i--){
        setPin(i, val);
    }
}

void Pineapple::clear(){
    //set all register pins to LOW
    for(int i = _Number_of_Registers * 8 - 1; i >=  0; i--){
        setPin(i, _common);
    }
}

uint8_t Pineapple::segmentPins(int a, int b, int c, int d, int e, int f, int g, int dp, boolean common) {
    
    _a=a;
    _b=b;
    _c=c;
    _d=d;
    _e=e;
    _f=f;
    _g=g;
    _dp=dp;
    _common=common;
    
    segmentpinsb[0] = _dp;
    segmentpinsb[1] = _g;
    segmentpinsb[2] = _f;
    segmentpinsb[3] = _e;
    segmentpinsb[4] = _d;
    segmentpinsb[5] = _c;
    segmentpinsb[6] = _b;
    segmentpinsb[7] = _a;
    
    for(int i=0; i < 8; i++) {
        
        pinMode(segmentpinsb[i], OUTPUT);
    }
    
    if (_common == HIGH) {
        setPin(_dp, HIGH);
        update();
    }
    if (_common == LOW) {
        setPin(_dp, LOW);
        update();
    }
}

void Pineapple::flicker() {
    
    write(0);
    delay(50);
    write(4);
    delay(50);
    write(6);
    delay(50);
    write(1);
    delay(50);
    write(6);
    delay(50);
    write(1);
    delay(50);
    write(3);
    delay(50);
    write(4);
    delay(100);
    write(1);
    delay(100);
    write(0);
    delay(100);
    write(3);
    delay(100);
    write(2);
    delay(100);
    write(5);
    delay(100);
    write(6);
    delay(100);
    write(3);
    delay(200);
    write(5);
    delay(300);
}

void Pineapple::write(int number) {
    _number=number;
    
    boolean isBitSet;
    // G, F, E, D, C, B, A, DP
    numeral[0] = B11111100;  // 0
    numeral[1] = B01100000;  // 1
    numeral[2] = B11011010;  // 2
    numeral[3] = B11110010;  // 3
    numeral[4] = B01100110;  // 4
    numeral[5] = B10110110;  // 5
    numeral[6] = B10111110;  // 6
    numeral[7] = B11100000;  // 7
    numeral[8] = B11111110;  // 8
    numeral[9] = B11100110;  // 9
    
    if (_common == HIGH) {
        
        for(int segment=1; segment < 8; segment++) {
            if(number < 0 || number > 9) {
                isBitSet = 0;
            }else{
                isBitSet = bitRead(numeral[number], segment);
            }
            isBitSet = ! isBitSet;
            setPin(segmentpins[segment], isBitSet);
        }
    }else{
        for(int segment=1; segment < 8; segment++) {
            if(number < 0 || number > 9) {
                isBitSet = 0;
            }else{
                isBitSet = bitRead(numeral[number], segment);
            }
            setPin(segmentpins[segment], isBitSet);
        }
    }
}

void Pineapple::setDecimalPoint(int digit, boolean decimalState) {
    
    _digit=digit;
    _decimalState=decimalState;
    
    if(_digit == 1) {
        
        if (_decimalState == HIGH && _common == HIGH) {
            setPin(_dp, LOW);
            update();
        }
        if (_decimalState == HIGH && _common == LOW) {
            setPin(_dp, HIGH);
            update();
        }
        if (_decimalState == LOW && _common == HIGH) {
            setPin(_dp, HIGH);
            update();
        }
        if (_decimalState == LOW && _common == LOW) {
            setPin(_dp, LOW);
            update();
        }
    }
}