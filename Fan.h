#ifndef FAN_H
#define FAN_H
#include "Device.h"
class Fan :public Device
{
	int speed;

public:
	Fan();
	Fan(int _id,MyStr _name, bool _isON);
	Fan(const Fan& other);
	Fan& operator=(const Fan& other);
	void turnOn();
	void turnOff();
	void SetSetting() override;
	void EnergyUsed()override;
	void serialize(fstream& f)override;
	void deserialize(fstream& f)override;
	~Fan();
	void Display()override;
};
#endif // !FAN_H
