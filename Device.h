#ifndef DEVICE_H
#define DEVICE_H
#include "MyStr.h"
#include <time.h>
#include <string.h>
class Device
{
private:
	int id;
	MyStr name;
	bool isOn;
	float powerRating; 
	time_t lastOnTimestamp; 
	int totalEnergyUsed; 
public:
	Device();
	Device(int _id,MyStr _name, bool _isOn,float _power);
	Device(const Device& other);
	Device& operator=(const Device& other);
	virtual void turnOn();
	virtual void turnOff();
	void _turnOn();
	void _turnOff();
	virtual void SetSetting();
	virtual void EnergyUsed();
	MyStr energyused();
	MyStr getname();
	int getid();
	bool isitOn();
	void _serialize(fstream& f);
	void _deserialize(fstream& f);
	virtual void serialize(fstream& f);
	virtual void deserialize(fstream& f);
	virtual ~Device();
	void print();
	virtual void Display();
	virtual void RemoveDevice();
	void setPower(float pow);
};
#endif 
