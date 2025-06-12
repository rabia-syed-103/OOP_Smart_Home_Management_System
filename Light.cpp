#include "Light.h"

Light::Light():brightness(0)
{
}
Light::Light(int _id,MyStr _name, bool _isON) :Device(_id,_name, _isON),brightness(0)
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
	this->turnOn();
}
void Light::turnOff()
{
	this->turnOff();

}
void Light::SetSetting()
{
	cout << "Enter Brightness :: ";
	cin >> this->brightness;
}

