#include "Light.h"
#include <fstream>
Light::Light():brightness(1)
{
}
Light::Light(int _id,MyStr _name, bool _isON) :Device(_id,_name, _isON,5),brightness(1)
{
	
}
Light::Light(const Light& other) :Device(other)
{
	this->brightness = other.brightness;
}
Light&Light::operator=(const Light& other)
{
	if (this != &other)
	{
		Device::operator=(other);
		this->brightness = other.brightness;
	}
	return *this;
}

void Light::turnOn()
{
	this->_turnOn();
}
void Light::turnOff()
{
	this->_turnOff();

}
void Light::SetSetting()
{
	if (!(this->isitOn()))
		throw MyStr("\n Settings cannot be changed unless the device is On!\n");

	cout << "Enter Brightness :: ";
	cin >> this->brightness;
}

void Light::EnergyUsed()
{
	if (this->energyused().is_equal('\0'))
	{
		throw MyStr("\nTime too less to calculate!\n");
	}
	MyStr energy = "Device Name : ";
	cout << "Hello";
	cout << this->energyused();
	energy = energy.append(this->getname()).append("  EnergyUsed : ").append(this->energyused());
	throw(energy);
}

void Light::serialize(fstream& f)
{
	this->_serialize(f);
	f.write((char*)&brightness, sizeof(brightness));
}

void Light::deserialize(fstream& f)
{
	this->_deserialize(f);
	f.read((char*)&brightness, sizeof(brightness));
}

Light::~Light()
{
}

void Light::Display()
{
	this->print();
	if (this->isitOn() == true)
	{
		cout << endl << "Brightness :: " << this->brightness;
	}
	cout << endl << endl;

}
