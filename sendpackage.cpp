#include "sendpackage.h"

int spackage::init(String name)
{
		p_name = name;
		p_name += "#end";
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
