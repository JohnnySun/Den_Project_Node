/*	A part of node
	Den Project
	Copyright 2007-2014 BMY-Soft

	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
*/

/*Den Project Kernel Library*/

#ifndef io_h
#define io_h

#if defined(ARDUINO) && (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#define IO_VERSION "0.0.2"


class io
{
		public:
				io(){emergency = 0;}
				virtual int read(){return 0;}
				virtual int read(int){return 0;}
				virtual int write(int){return 0;}				

				String node_name;
				char byte;
				String p_name;
				int p_type;
				int i_data;
				char c_data;
				float f_data;
				enum type{int_t, char_t, float_t};

				int emergency;
				
};
#endif
//
// END OF FILE
//
