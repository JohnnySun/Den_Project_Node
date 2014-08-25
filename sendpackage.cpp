#include "sendpackage.h"

int spackage::init(String name)
{
		p_name = name;
		p_name += "#end";
		return 0;
}

int spackage::write(int *data) {
		p_type = "int";
		i_data = *data;
		return 0;
}

int spackage::write(float *data) {
		p_type = "float";
		f_data = *data;
		return 0;
}

int spackage::write(char *data) {
		p_type = "char";
		c_data = *data;
		return 0;
}

int spackage::send() {
		Serial.print(NODE_NAME);
		Serial.println();
		Serial.print(p_type);
		Serial.println();
		Serial.print(p_name);
		Serial.println();
		if(p_type.equals("int"))
						Serial.print(i_data);
		if(p_type.equals("char"))
						Serial.print(c_data);
		if(p_type.equals("float"))
						Serial.print(f_data);
		Serial.println();
		Serial.print("#EOF");
		Serial.println();
		return 0;
}
