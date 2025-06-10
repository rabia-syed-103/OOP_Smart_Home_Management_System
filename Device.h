#ifndef DEVICE_H
#define DEVICE_H
#include "MyStr.h"

class Device
{
private:
	MyStr name;
	bool isOn;
public:
	void turnOn();
	void turnOff();
	void SetSetting();
	MyStr getname();

};
#endif 
