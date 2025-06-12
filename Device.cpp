#include "Device.h"

Device::Device():id('\0'),isOn(false)
{
}

Device::Device(int _id,MyStr _name, bool _isOn):id(_id),name(_name),isOn(_isOn)
{
}

Device::Device(const Device& other):id(other.id),name(other.name),isOn(other.isOn)
{
}

Device& Device::operator=(const Device& other)
{
	if (this != &other)
	{
		this->id = other.id;
		this->name = other.name;
		this->isOn = other.isOn;
	}
	return *this;


}

void Device::turnOn()
{
	if (this->isOn == false)
		this->isOn = true;
	else
		cout << "\nAlready On.";
}

void Device::turnOff()
{
	if (this->isOn == true)
		this->isOn = false;
	else
		cout << "\nAlready Off.";
}

void Device::SetSetting()
{
}

MyStr Device::getname()
{
	return this->name;
}
