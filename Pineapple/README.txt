This library was made by Qtechknow (Quin).  This drives a 7 segment LED with a 74HC595 shift register.  Credits go to Qtechknow (Quin), Adam Meyer of Bildr, and Arduino Forum member lloyddean.  If you have any problems, contact quin@qtechknow.com.  Here are the main functions of the library:

Pineapple pineapple
	Initiates the library.

pineapple.registerPins(int serialPin, int registerClockPin, int serialClockPin, int 		numberofRegisters)
		Defines the pins of the shift register pins.

pineapple.update()
	Updates the display.  You will not need to use this for it will be done automatically in the library.

pineapple.setPin(int index, boolean value)
	This will set an individual pin high or low, not a number on the display.

pineapple.setAll(boolean value)
	Sets all of the pins high or low.  Watch out on the common anode or the common cathode, because that might be how you're messing up.

pineapple.clear()
	Clears the display.

pineapple.segmentPins(int a, int b, int c, int d, int e, int f, int g, int dp, boolean  	common)
		Declares the segment pins and the common anode or the common cathode.  Set the boolean common HIGH for a common anode display and LOW for a common cathode display.  For the segment pin numbers, set to 0 - 7 for the first shift register, 8-15 for the next, and so on.

pineapple.flicker()
	Flickers the display.  I used this function in the example dice sketch to flicker before displaying the random number.

pineapple.write(int number)
	Displays int number.  Can be used in for loops, so no more repetition.  