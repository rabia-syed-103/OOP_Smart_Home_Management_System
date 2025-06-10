#include "Lock.h"

Lock::Lock()
{
}
Lock::Lock(MyStr _name, bool _isON) :Device(_name, _isON)
{

}
Lock::Lock(const Lock& other) :Device(other)
{
	this->password = other.password;
}
Lock& Lock::operator=(const Lock& other)
{
	if (this != &other)
	{
		Device::operator=(other);
		this->password = other.password;
		
	}
	return *this;
}

void Lock::turnOn()
{
	cout << "Enter Password to turn on the lock :: ";
	MyStr pass;
	cin >> pass;
	if (pass.is_equal(this->password))
		this->turnOn();
	else
		throw MyStr("\n~Unauthorized Access!");
}

void Lock::turnOff()
{
	cout << "Enter Password to turn Off the lock :: ";
	MyStr pass;
	cin >> pass;
	if (pass.is_equal(this->password))
		this->turnOff();
	else
		throw MyStr("\n~Unauthorized Access!");


}
void Lock::SetSetting()
{
}
