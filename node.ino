/*
   规定数据包格式
   NodeName 
   Data Types 
   Data Name
   Data
   (EOF)
 */
#include <dht11.h>
#include "sendpackage.h"
#include "io.h"
#include "ptthread/pt.h"

dht11 DHT11;
spackage pack;
io reads;

#define DHT11PIN 2
double Fahrenheit(double celsius) 
{
		return 1.8 * celsius + 32;
}    //摄氏温度度转化为华氏温度

double Kelvin(double celsius)
{
		return celsius + 273.15;
}     //摄氏温度转化为开氏温度

// 露点（点在此温度时，空气饱和并产生露珠）
// 参考: http://wahiduddin.net/calc/density_algorithms.htm 
double dewPoint(double celsius, double humidity)
{
		double A0= 373.15/(273.15 + celsius);
		double SUM = -7.90298 * (A0-1);
		SUM += 5.02808 * log10(A0);
		SUM += -1.3816e-7 * (pow(10, (11.344*(1-1/A0)))-1) ;
		SUM += 8.1328e-3 * (pow(10,(-3.49149*(A0-1)))-1) ;
		SUM += log10(1013.246);
		double VP = pow(10, SUM-3) * humidity;
		double T = log(VP/0.61078);   // temp var
		return (241.88 * T) / (17.558-T);
}

// 快速计算露点，速度是5倍dewPoint()
// 参考: http://en.wikipedia.org/wiki/Dew_point
double dewPointFast(double celsius, double humidity)
{
		double a = 17.271;
		double b = 237.7;
		double temp = (a * celsius) / (b + celsius) + log(humidity/100);
		double Td = (b * temp) / (a - temp);
		return Td;
}

/*以上部分回头整合到DH11 lib中，进行模块标准化*/

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

				float temp = dewPointFast(DHT11.temperature, DHT11.humidity);
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
				PT_WAIT_UNTIL(pt, reads.readserial());
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

