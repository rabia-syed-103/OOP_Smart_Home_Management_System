#ifndef SENSOR_H
#define SENSOR_H
#include "Device.h"
class Sensor :public Device
{
public:
	Sensor();
	Sensor(int _id,MyStr _name);
	Sensor(const Sensor& other);
	Sensor& operator=(const Sensor& other);
	void turnOn();
	void turnOff();
	void SetSetting() override;
	void EnergyUsed()override;
	void serialize(fstream& f)override;
	void deserialize(fstream& f)override;
	void detectEvent();
	~Sensor();
	void Display()override;
	void RemoveDevice()override;
};
#endif // !Sensor_H
