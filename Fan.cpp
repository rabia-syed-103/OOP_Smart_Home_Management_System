#include "Fan.h"

Fan::Fan() :speed(0)
{
}
Fan::Fan(MyStr _name, bool _isON) :Device(_name, _isON), speed(0)
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
	this->turnOn();
}
void Fan::turnOff()
{
	this->turnOff();

}
void Fan::SetSetting()
{
	cout << "Select speed 1-5 :: ";
	cin >> this->speed;
	if (this->speed > 5)
	{
		cout << "\nNot Allowed! Setting speed to zero.";
		this->speed = 0;
	}

}
