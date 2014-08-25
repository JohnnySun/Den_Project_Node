/*Den Project Kernel Library*/

#ifndef readserial_h
#define readserial_h

#if defined(ARDUINO) && (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#define READ_SERIAL_VERSION "0.0.1"

#include "include/kernel/io.h"

class readserial : public io
{
		public:
				int read();
				int readin(int *, char *);
};
#endif
//
// END OF FILE
//
