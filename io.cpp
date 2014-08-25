#include "io.h"

io::io()
{
		p_name = NULL;
		p_type = NULL;
		i_data = 0;
		c_data = 0;
		f_data = 0;
}

int io::readserial()
{
		if(Serial.available() == 0){
				return 0;
		}else{
				while(c = Serial.read())
				{
						if(c != '#'){
								p_name += c;
						}else{
								char buffer[3];
								Serial.readBytes(buffer, 3);
								if(buffer[0] == 'e' && buffer[1] == 'n' && buffer[2] == 'd'){
										break;
								}
						}
				}
				Serial.println(p_name);
				p_name = NULL;
				return 1;
		}
}
