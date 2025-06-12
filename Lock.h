#ifndef LOCK_H
#define LOCK_H
#include "Device.h"
class Lock :public Device
{
	MyStr password;
public:
	Lock();
	Lock(int _id,MyStr _name, bool _isON);
	Lock(const Lock& other);
	Lock& operator=(const Lock& other);
	void turnOn() override;
	void turnOff() override;
	void SetSetting() override;
};
#endif // !LOCK_H

