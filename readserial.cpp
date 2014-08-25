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
