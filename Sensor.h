#ifndef SENSOR_H
#define SENSOR_H
#include "Device.h"
class Sensor :public Device
{
public:
	Sensor();
	Sensor(int _id,MyStr _name, bool _isON);
	Sensor(const Sensor& other);
	Sensor& operator=(const Sensor& other);
	void turnOn() override;
	void turnOff() override;
	void SetSetting() override;
};
#endif // !Sensor_H
