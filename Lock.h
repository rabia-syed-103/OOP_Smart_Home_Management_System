#ifndef LOCK_H
#define LOCK_H
#include "Device.h"
class Lock :public Device
{
	MyStr password;
public:
	Lock();
	Lock(int _id,MyStr _name, bool _isON,MyStr _pass);
	Lock(const Lock& other);
	Lock& operator=(const Lock& other);
	void turnOn();
	void turnOff();
	void SetSetting() override;
	void EnergyUsed()override;
	void serialize(fstream& f)override;
	void deserialize(fstream& f)override;
	~Lock();
	void Display()override;
};
#endif // !LOCK_H
