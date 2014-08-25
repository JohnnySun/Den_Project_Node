/* 请继承nobject类，在进行新类的开发时，保证类的标准性，方便Den Project的统一管理 */

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
	virtual int read(int pin){return 0;}
	virtual int write(int pin){return 0;}
};
#endif
//
// END OF FILE
//
