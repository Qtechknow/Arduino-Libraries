#ifndef Soda_h
#define Soda_h

#if ARDUINO >= 100     // Arduino 1.0 and 0023 compatible!
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class Soda_h
{
public:
    void pins(int a, int b, int c, int d, int e, int f, int g, int dp);
    void write(int number);
    void setDecimalPoint(int digit, boolean decimalState);

private:
    int _a, _b, _c, _d, _e, _f, _g, _dp, _common;
    int _number;
    int _digit, boolean _decimalState;
};

#endif