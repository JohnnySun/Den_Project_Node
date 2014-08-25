 

#ifndef example_output_h
#define example_output_h

#if defined(ARDUINO) && (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#define EXAMPLELIB_VERSION "0.0.1"

class example_output
{
public:
	int read(int pin);
	int write(int pin);
};
#endif
//
// END OF FILE
//
