#include "Fan.h"
#include <fstream>
Fan::Fan() :speed(1)
{
}
Fan::Fan(int _id,MyStr _name, bool _isON) :Device(_id,_name, _isON,10), speed(1)
{

}
Fan::Fan(const Fan& other) :Device(other)
{
	this->speed = other.speed;
}
Fan& Fan::operator=(const Fan& other)
{
	if (this != &other)
	{
		Device::operator=(other);
		this->speed = other.speed;
	}
	return *this;
}

void Fan::turnOn()
{
	this->_turnOn();
}
void Fan::turnOff()
{
	this->_turnOff();

}
void Fan::SetSetting()
{
	if(!(this->isitOn()))
			throw MyStr("\n Settings cannot be changed unless the device is On!\n");
	cout << "Select speed 1-5 :: ";
	cin >> this->speed;
	if (this->speed > 5)
	{
		cout << "\nNot Allowed! Setting speed to zero.";
		this->speed = 0;
	}

}

void Fan::EnergyUsed()
{
	if (this->energyused().is_equal('\0'))
	{
		throw MyStr("\nTime too less to calculate!\n");
	}
	MyStr energy = "Device Name : ";
	energy = energy.append(this->getname()).append("  EnergyUsed : ").append(this->energyused());
	throw(energy);
}

void Fan::serialize(fstream& f)
{
	this->_serialize(f);

	f.write((char*)&speed, sizeof(speed));
}

void Fan::deserialize(fstream& f)
{
	this->_deserialize(f);

	f.read((char*)&speed, sizeof(speed));
}

Fan::~Fan()
{
}

void Fan::Display()
{
	this->print();
	if (this->isitOn() == true)
	{
		cout << endl << "Speed :: " << this->speed;
	}
	cout << endl << endl;

}
