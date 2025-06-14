#include "AC.h"
#include <fstream>
AC::AC():temp(16), mode('C')
{
}
AC::AC(int _id,MyStr _name, bool _isON):Device(_id,_name,_isON,15),temp(16), mode('C')
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
	this->_turnOn();
}
void AC::turnOff()
{
	this->_turnOff();

}
void AC::SetSetting()
{
	if (this->isitOn())
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
	else
		throw MyStr("\n Settings cannot be changed unless the device is On!\n");

}
void AC::EnergyUsed()
{
	if (this->energyused().is_equal('\0'))
	{
		throw MyStr("\nTime too less to calculate!\n");
	}
	MyStr energy = "Device Name : ";
	energy = energy.append(this->getname()).append("  EnergyUsed : ").append(this->energyused());
	throw(energy);
}
AC:: ~AC()
{}

void AC::serialize(fstream & f)
{
	this->_serialize(f);
	f.write((char*)&mode, sizeof(mode));
	f.write((char*)&temp, sizeof(temp));
}

void AC::deserialize(fstream& f)
{
	this->_deserialize(f);
	f.read((char*)&mode, sizeof(mode));
	f.read((char*)&temp, sizeof(temp));
}

void AC::Display()
{
	this->print();
	if (this->isitOn() == true)
	{
		cout << endl << "Mode :: " << this->mode;
		cout << endl << "Temp :: " << this->temp;
	}
	cout << endl << endl;
}
