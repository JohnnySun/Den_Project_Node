/*	A part of node
	Den Project
	Copyright 2007-2014 BMY-Soft

	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
*/

#include "include/readserial.h"

int readserial::read()
{
		int counter = 0;
		if(Serial.available() == 0){
				return 0;
		}else{
				while(byte = Serial.read())
				{
						if(byte != '#'){
							readin(&counter, &byte);
						}else{
								char buffer[3];
								Serial.readBytes(buffer, 3);
								if(buffer[0] == 'E' && buffer[1] == 'N' && buffer[2] == 'D'){
										counter++;
										break;
								}else{
										node_name = NULL;
										Serial.println("Data Transfer ERROR");
										break;
								}
						}
				}
				Serial.println(node_name);
				p_name = NULL;
				return 1;
		}
}

int readserial::readin(int *counter, char *byte)
{
		switch(*counter){
				case 0:
						node_name += *byte;
						break;
				case 1:
						p_name += *byte;
						break;
				case 2:
						p_type += *byte;
						break;

		}
}
