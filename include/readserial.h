/*	A part of node
	Den Project
	Copyright 2007-2014 BMY-Soft

	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
*/

#ifndef readserial_h
#define readserial_h

#if defined(ARDUINO) && (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#define READ_SERIAL_VERSION "0.0.5"

#include "include/kernel/io.h"

class readserial : public io
{
		public:
				int readin(int *, char *);
				int read();
				int savedata(int *, String *);
				int check_sign(char *);
		private:
				String temp_data;
				int counter;
};
#endif
//
// END OF FILE
//
