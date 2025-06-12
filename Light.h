#ifndef LIGHT_H
#define LIGHT_H
#include "Device.h"
class Light :public Device
{
	int brightness;
	
public:
	Light();
	Light(int _id,MyStr _name, bool _isON);
	Light(const Light& other);
	Light& operator=(const Light& other);
	void turnOn() override;
	void turnOff() override;
	void SetSetting() override;
};
#endif // !LIGHT_H
