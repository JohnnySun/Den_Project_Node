/*Den Project Kernel Library*/

#ifndef io_h
#define io_h

#if defined(ARDUINO) && (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#define IO_VERSION "0.0.1"


class io
{
		public:
				
				String node_name;
				char byte;
				String p_name;
				String p_type;
				int i_data;
				char c_data;
				float f_data;

				enum type{int_t, char_t, float_t};
				
};
#endif
//
// END OF FILE
//
