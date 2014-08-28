/*	A part of node
	Den Project
	Copyright 2007-2014 BMY-Soft

	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
*/

#ifndef sendpackage_h
#define sendpackage_h
#if defined(ARDUINO) && (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#define SENDPACKAGE_VERSION "0.0.2"

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
