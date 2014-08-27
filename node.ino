#include <den.h>
#include <include/dht11.h>
#include "include/sendpackage.h"
#include "include/readserial.h"
#include "include/ptthread/pt.h"

dht11 DHT11;
spackage pack;
readserial reads;



/*########################################*/
/*############thread##########################*/
static int counter1, counter2 = 0;
static int send_to_user(struct pt *pt)
{
		PT_BEGIN(pt);
		while(1)
		{
				PT_WAIT_UNTIL(pt, counter1==5);
				counter1 = 0;
				Serial.println("\n");

				int chk = DHT11.read(DHT11PIN);

				pack.init("Humidity");
				pack.write(&DHT11.humidity);
				pack.send();

				pack.init("Temperature");
				pack.write(&DHT11.temperature);
				pack.send();

				float temp = DHT11.dewPointFast(DHT11.temperature, DHT11.humidity);
				pack.init("Dew PointFast");
				pack.write(&temp);
				pack.send();

		}
		PT_END(pt);
}

static int serialread(struct pt *pt)
{
		static char read;
		PT_BEGIN(pt);
		while(1)
		{
				PT_WAIT_UNTIL(pt, reads.read());
				//read = Serial.read();
				//Serial.println(read);
				Serial.println(" thread2\n");
				//counter2 = 0;
		}
		PT_END(pt);
}

static struct pt pt1, pt2;
/*########################################*/

void setup()
{
		Serial.begin(9600);
		PT_INIT(&pt1);
		PT_INIT(&pt2);
}

void loop()
{ 
		send_to_user(&pt1);
		serialread(&pt2);
		delay(1000);
		counter1++;
		//counter2++;
}

