#ifndef Pineapple_h
#define Pineapple_h

#if ARDUINO >= 100     // Arduino 1.0 and 0023 compatible!
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class Pineapple
{
public:
    uint8_t registerPins(int SER_Pin, int RCLK_Pin, int SRCLK_Pin, int Number_of_Registers);
    uint8_t segmentPins(int a, int b, int c, int d, int e, int f, int g, int dp, boolean common);
    void write(int number);
    void clear();
    void setAll(boolean val);
    void setPin(int index, boolean val);
    void update();
    void flicker();
    void setDecimalPoint(int digit, boolean decimalState);
    
private:
    int _a, _b, _c, _d, _e, _f, _g, _dp, _number;
    int _SER_Pin, _RCLK_Pin, _SRCLK_Pin, _Number_of_Registers;
    byte numeral[10];
    byte numeralb[10];
    byte numeralc[10];
    byte numerald[10];
    byte numerale[10];
    byte numeralf[10];
    int segmentpins[8];
    int segmentpinsa[8];
    int segmentpinsb[8];
    boolean _common;
    boolean _commona;
    boolean _commonb;
    byte _shiftRegisters[25];
    boolean _val;
    boolean _decimalState;
    int _digit;
};

#endif