This library was made by Quin, the head engineer at Qtechknow.  I made this specifically for using with 7-segment displays.  Share, distribute, and edit for your specific uses.  This is an open-source library.

Functions:

Soda soda;
  Initiates the library.

soda.pins(int a, int b, int c, int d, int e, int f, int g, int dp);
	Declares and sets up the pins.

soda.write(int number);
	Lights up int number on the 7-Segment display.

soda.setDecimalPoint(int digit, boolean decimalState);
	Sets the decimal point of int digit to boolean decimalState.