#ifndef sendpackage_h
#define sendpackage_h
#if defined(ARDUINO) && (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#define SENDPACKAGE_VERSION "0.0.1"

#include "include/kernel/io.h"

class spackage : private io
{
		public:
				int write(int *);
				int write(float *);
				int write(char *);
				int init(String);
				int send();
};
#endif
