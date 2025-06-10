#ifndef FAN_H
#define FAN_H
#include "Device.h"
class Fan :public Device
{
	int speed;

public:
	Fan();
	Fan(MyStr _name, bool _isON);
	Fan(const Fan& other);
	Fan& operator=(const Fan& other);
	void turnOn() override;
	void turnOff() override;
	void SetSetting() override;
};
#endif // !FAN_H
