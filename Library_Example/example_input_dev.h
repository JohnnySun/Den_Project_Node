 

#ifndef nobject_h
#define nobject_h

#if defined(ARDUINO) && (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#define NOBJECT_VERSION "0.0.1"

class nobject
{
public:
	virtual int read(int pin);
	virtual int write(int pin);
};
#endif
//
// END OF FILE
//
