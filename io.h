#ifndef io_h
#define io_h

#define NODE_NAME "node1"
#if defined(ARDUINO) && (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#define IO_VERSION "0.0.1"

#include <nobject.h>

class io : public nobject
{
		public:
				io();
				//int read(int pin);
				int readserial();
				//int wirte(int pin,);
		private:
				char c;
				String p_name;
				String p_type;
				int i_data;
				char c_data;
				float f_data;
};
#endif
//
// END OF FILE
//
