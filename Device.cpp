#include "Device.h"

Device::Device():isOn(false)
{
}

Device::Device(MyStr _name, bool _isOn):name(_name),isOn(_isOn)
{
}

Device::Device(const Device& other):name(other.name),isOn(other.isOn)
{
}

Device& Device::operator=(const Device& other)
{
	if (this != &other)
	{
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
