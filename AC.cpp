#include "AC.h"

AC::AC():temp(0),mode('\0')
{
}
AC::AC(MyStr _name, bool _isON):Device(_name,_isON),temp(0), mode('\0')
{

}
AC::AC(const AC& other):Device(other)
{
	this->mode = other.mode;
	this->temp = other.temp;
}
AC& AC::operator=(const AC& other)
{
	if (this != &other)
	{
		Device::operator=(other);
		this->temp = other.temp;
		this->mode = other.mode;
	}
	return *this;
}

void AC::turnOn()
{
	this->turnOn();
}
void AC::turnOff()
{
	this->turnOff();

}
void AC::SetSetting()
{
	cout << "Do you want to set Mode or Temp (M/T):: ";
	char ch;
	cin >> ch;
	if (ch == 'M')
	{
		cout << "Select Mode :: \nC.Cool\nT.Turbo\nS.Sleep\n";
		cin >> this->mode;
	}
	else if (ch == 'T')
	{
		cout << "Enter Temperature :: ";
		cin >> this->temp;
	}
	else
	{
		cout << "\nNo Such Options\n";
	}

}
