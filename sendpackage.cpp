#include "sendpackage.h"

int spackage::init()
{
		buffer = "0A_START";
		buffer = buffer + NODE_NAME;
		buffer = buffer + "0A_END";
		return 0;
}

int spackage::write(char *name, int *data) {
		String temp = String(*data);
		buffer = buffer + "0B_START";
		buffer = buffer + "int";
		buffer = buffer + "0C_START";
		buffer = buffer + name;
		buffer = buffer + "0D_Start";
		buffer = buffer + temp;
		buffer = buffer + "0F0F";
		return 0;
}

int spackage::write(char *name, float *data) {
		String temp = String((int)*data);
		buffer = buffer + "0B_START";
		buffer = buffer + "float";
		buffer = buffer + "0C_START";
		buffer = buffer + name;
		buffer = buffer + "0D_Start";
		buffer = buffer + temp;
		buffer = buffer + "0F0F";
		return 0;
}

int spackage::write(char *name, char *data) {
		buffer = buffer + "0B_START";
		buffer = buffer + "string";
		buffer = buffer + "0C_START";
		buffer = buffer + name;
		buffer = buffer + "0D_Start";
		buffer = buffer + data;
		buffer = buffer + "0F0F";
		return 0;
}

int spackage::send() {
		Serial.print(buffer);
		Serial.println();
		return 0;
}
