/*	A part of node
	Den Project
	Copyright 2007-2014 BMY-Soft

	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
*/

/*
   规定数据包格式
   (NodeName)#END(Data Types)#END(Data Name)#END(Data)#END#EOF
 */
#include <den.h>
#include <include/sendpackage.h>

int spackage::init(String name)
{
		p_name = name;
		return 0;
}

int spackage::write(int *data) {
		p_type = int_t;
		i_data = *data;
		return 0;
}

int spackage::write(float *data) {
		p_type = float_t;
		f_data = *data;
		return 0;
}

int spackage::write(char *data) {
		p_type = char_t;
		c_data = *data;
		return 0;
}

int spackage::send() {
		Serial.print(NODE_NAME);
		Serial.print("#END");
		Serial.print(p_type);
		Serial.print("#END");
		Serial.print(p_name);
		Serial.print("#END");
		switch(p_type){
				case 0:
						Serial.print(i_data);
						break;
				case 1:
						Serial.print(c_data);
						break;
				case 2:
						Serial.print(f_data);
						break;
		}
		Serial.print("#END");
		Serial.print("#EOF");
		Serial.println();
		return 0;
}
