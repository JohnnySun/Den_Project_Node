#ifndef input_h
#define input_h

#if defined(ARDUINO) && (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#define DHT11LIB_VERSION "0.4.1"
#define DHTLIB_OK				0
#define DHTLIB_ERROR_CHECKSUM	-1
#define DHTLIB_ERROR_TIMEOUT	-2

#include <nobject.h>

class input : public nobject
{
		write(int pin);
};
#endif

