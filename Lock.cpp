#include "Lock.h"
#include <fstream>
Lock::Lock()
{
	cout << "Set Password :: ";
	cin >> this->password;
}

Lock::Lock(int _id,MyStr _name, bool _isON,MyStr _pass) :Device(_id,_name, _isON,3),password(_pass)
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
		this->_turnOn();
	else
		throw MyStr("\n~Unauthorized Access!\n");
}

void Lock::turnOff()
{
	cout << "Enter Password to turn Off the lock :: ";
	MyStr pass;
	cin >> pass;
	if (pass.is_equal(this->password))
		this->_turnOff();
	else
		throw MyStr("\n~Unauthorized Access!\n");


}

void Lock::SetSetting()
{
	throw MyStr("\nNo Seetings of Lock can be Changed!\n");
}

void Lock::EnergyUsed()
{
	if (this->energyused().is_equal('\0'))
	{
		throw MyStr("\nTime too less to calculate!\n");
	}
	MyStr energy = "Device Name : ";
	energy = energy.append(this->getname()).append("  EnergyUsed : ").append(this->energyused());
	throw(energy);
}

void Lock::serialize(fstream& f)
{
	this->_serialize(f);
	const char* newname = this->password.c_str();
	int len = this->password.get_length(newname);
	f.write((char*)&len, sizeof(len));
	f.write(newname, len);
}

void Lock::deserialize(fstream& f)
{
	this->_deserialize(f);
	int len;
	f.read((char*)&len, sizeof(len));
	char* newname = new char[len + 1];
	f.read(newname, len);
	newname[len] = '\0';
	this->password.cpy(newname);
}

Lock::~Lock()
{
}

void Lock::Display()
{
	this->print();
	cout << endl << "Password is Confidential!";
	cout << endl << endl;

}

