#ifndef sendpackage_h
#define sendpackage_h
#define NODE_NAME "node1"
#if defined(ARDUINO) && (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#define SENDPACKAGE_VERSION "0.0.1"

class spackage
{
		public:
				int write(char *, int *);
				int write(char *, float *);
				int write(char *, char *);
				int init();
				int send();
		private:
				String buffer;
};
#endif
