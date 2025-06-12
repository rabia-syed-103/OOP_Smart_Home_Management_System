#ifndef DEVICE_H
#define DEVICE_H
#include "MyStr.h"

class Device
{
private:
	int id;
	MyStr name;
	bool isOn;
public:
	Device();
	Device(int _id,MyStr _name, bool _isOn);
	Device(const Device& other);
	Device& operator=(const Device& other);
	virtual void turnOn();
	virtual void turnOff();
	virtual void SetSetting();
	MyStr getname();

};
#endif 

