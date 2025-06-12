#include "Sensor.h"

Sensor::Sensor()
{
}
Sensor::Sensor(int _id,MyStr _name, bool _isON) :Device(_id,_name, _isON)
{

}
Sensor::Sensor(const Sensor& other) :Device(other)
{
}
Sensor& Sensor::operator=(const Sensor& other)
{
	if (this != &other)
	{
		Device::operator=(other);

	}
	return *this;
}

void Sensor::turnOn()
{
	throw MyStr("Sensor cannot be turned on manually.");
}

void Sensor::turnOff()
{
	throw MyStr("Sensor cannot be turned off manually.");

}
void Sensor::SetSetting()
{
	throw MyStr("Settings of Sensor cannot be changed.");

}
