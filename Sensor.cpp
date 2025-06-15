#include "Sensor.h"

Sensor::Sensor()
{
	this->setPower(20);
}

Sensor::Sensor(int _id,MyStr _name) :Device(_id,_name, true,20)
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

void Sensor::EnergyUsed()
{
	throw("Energy of sensor cannot be monitored!");
}

void Sensor::serialize(fstream& f)
{
	this->_serialize(f);

}

void Sensor::deserialize(fstream& f)
{
	this->_deserialize(f);

}

Sensor::~Sensor()
{
}

void Sensor::Display()
{
	this->print();
	cout << endl << endl;

}
void Sensor::RemoveDevice()
{
	throw MyStr("\nSensor Can't be Removed!\n");
}
void Sensor:: detectEvent() {
	MyStr message = "Sensor ";
	message = message.append(this->getname()).append(" triggered in ");

	throw MyStr (message);	
}


