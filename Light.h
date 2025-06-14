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
	void turnOn() ;
	void turnOff();
	void SetSetting() override;
	void EnergyUsed()override;
	void serialize(fstream& f)override;
	void deserialize(fstream& f)override;
	~Light();
	void Display()override;
};
#endif // !LIGHT_H
