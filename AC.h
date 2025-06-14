#ifndef AC_H
#define AC_H
#include "Device.h"
class Device;
class AC :public Device
{
	int temp;
	char mode;
public:
	AC();
	AC(int _id,MyStr _name, bool _isON);
	AC(const AC& other);
	AC& operator=(const AC& other);
	void turnOn();
	void turnOff();
	void SetSetting() override;
	void EnergyUsed()override;
	~AC();
	void serialize(fstream& f);
	void deserialize(fstream& f);
	void Display()override;
};
#endif // !AC_H
