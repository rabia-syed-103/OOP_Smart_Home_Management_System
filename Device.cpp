#include "Device.h"
#include <fstream>
Device::Device():isOn(false),powerRating(0),totalEnergyUsed(0)
{
	cout << "Enter ID :: ";
	cin >> this->id;
	cout << "Enter Name :: ";
	cin >> this->name;
}

Device::Device(int _id,MyStr _name, bool _isOn, float _power):id(_id),name(_name),isOn(_isOn),powerRating(_power),totalEnergyUsed(0)
{
}

Device::Device(const Device& other):id(other.id),name(other.name),isOn(other.isOn), powerRating(other.powerRating),totalEnergyUsed(0)
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
}

void Device::turnOff()
{
}

void Device::_turnOn()
{
	if (this->isOn == false)
	{
		this->isOn = true;
		this->lastOnTimestamp = time(nullptr);
		cout << endl<<this->name << " turned On\n";
	}
	else
		cout << "\nAlready On.\n";
}

void Device::_turnOff()
{
	if (this->isOn == true)
	{
		this->isOn = false;
		cout << endl << this->name << " turned Off\n";
		time_t now = time(nullptr);

	
		double durationHours = difftime(now, lastOnTimestamp) / 3600.0;
		totalEnergyUsed = totalEnergyUsed + (powerRating / 1000.0) * durationHours;
	}
	else
		cout << "\nAlready Off.\n";
}

void Device::SetSetting()
{
}
void Device::EnergyUsed()
{
}
MyStr Device::energyused()
{
	MyStr mess = mess.itos(this->totalEnergyUsed);

	return mess;
}

MyStr Device::getname()
{
	return this->name;
}

int Device:: getid()
{
	return this->id;
}

bool Device::isitOn()
{
	return this->isOn;
}

void Device::_serialize(fstream& f)
{
	f.write((char*)&id, sizeof(id));
	const char* newname = this->name.c_str();
	int len = this->name.get_length(newname);
	f.write((char*)&len, sizeof(len));
	f.write(newname, len);
	f.write((char*)&isOn, sizeof(isOn));
	f.write((char*)&powerRating, sizeof(powerRating));
}
void Device::_deserialize(fstream& f)
{
	f.read((char*)&id, sizeof(id));
	int len;
	f.read((char*)&len, sizeof(len));
	char* newname = new char[len + 1];
	f.read(newname, len);
	newname[len] = '\0';
	this->name.cpy(newname);
	f.read((char*)&isOn, sizeof(isOn));
	f.read((char*)&powerRating, sizeof(powerRating));
}

void Device::serialize(fstream& f)
{
}

void Device::deserialize(fstream& f)
{
}

Device::~Device()
{
}

void Device::print()
{
	cout << "Device ID :: " << this->id;
	cout << "\nDevice Name :: " << this->name;
	cout << "\nPower Rating :: " << this->powerRating;
	cout << "\nStatus :: " << this->isOn;
	cout << "\nTotal Energy Used :: " << this->totalEnergyUsed;
}

void Device::Display()
{
}

void Device::RemoveDevice()
{
}

void Device::setPower(float pow)
{
	this->powerRating = pow;
}

