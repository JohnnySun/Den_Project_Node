#ifndef dht11_h
#define dht11_h

#if defined(ARDUINO) && (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#define DHT11LIB_VERSION "0.4.1"

#define DHTLIB_OK				0
#define DHTLIB_ERROR_CHECKSUM	-1
#define DHTLIB_ERROR_TIMEOUT	-2

#include <include/kernel/io.h> 

class dht11 : public io
{
		public:
				int read(int pin);
				int humidity;
				int temperature;

				double Fahrenheit(double);
				double Kelvin(double);
				double dewPoint(double, double);
				double dewPointFast(double, double);
};
#endif
//
// END OF FILE
//
