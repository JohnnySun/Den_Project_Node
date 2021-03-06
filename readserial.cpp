/*	A part of node
	Den Project
	Copyright 2007-2014 BMY-Soft

	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 */

#include "den.h"
#include "include/readserial.h"

int readserial::read()
{
		counter = 0;
		int transfer_speed = TRANS_SPEED;
		if(Serial.available() == 0){
				return 0;
		}else{
				while(byte = Serial.read())
				{
						if(byte != '#'){
								readin(&counter, &byte);
								delayMicroseconds(transfer_speed * 10 + 25);
//+25 used to offset deviation
						}else{
								delayMicroseconds(transfer_speed * 30 + 25);
								char buffer[3];
								Serial.readBytes(buffer, 3);
								//countinue - 0
								//break -1
								if(check_sign(buffer)){
										continue;
								}else{
										break;
								}
						}
				}
				//Debug
				Serial.println("Debug:");
				Serial.println(node_name);
				Serial.println(p_type);
				Serial.println(temp_data);
				node_name = NULL;
				//p_name = NULL;
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
						if(*byte == 48){
								p_type = 0;
						}else if(*byte == 49){
								p_type = 1;
						}else if(*byte == 50){
								p_type = 2;
						}
						//p_type += *byte;
						break;
				case 2:
						p_name += *byte;
						break;
				case 3:
						temp_data += *byte;
						break;
				case 4:
						//BREAK，因为counter==4意味着后面是EOF,之所以写，是为了防止#END与#EOF之间出现空格
						break;
				case 5:
						break;
		}
}
int readserial::savedata(int *p_type, String *data)
{
		int i = data->length();
		char ch_data[i];
		switch(*p_type){
				case 0:
						i_data = atoi(ch_data);
						break;
				case 1:
						c_data = ch_data[0];
						break;
				case 2:
						f_data = atof(ch_data);
						break;
		}
		return i;
}

int readserial::check_sign(char *buffer)
{
		if(buffer[0] == 'E' && buffer[1] == 'N' && buffer[2] == 'D'){
				//数据全部录入temp_data后进行数据转存
				if(counter++ == 4){
						savedata(&p_type, &temp_data);
				}
				//countinue - 1
				//break -0
				return 1;
		}else if(buffer[0] == 'E' && buffer[1] == 'O' && buffer[2] == 'F'){
				return 0;
				//Emergency Event
		}else if(buffer[0] == 'E' && buffer[1] == 'M' && buffer[2] == 'E'){
				emergency = 1;
				//0 is false
				//1 is true
				return 1;

		}else{
				node_name = NULL;
				//This is Debug massaage, change it when this module complete.
				Serial.println("Data Transfer ERROR");
				return 0;
		}
		return 0;
}
