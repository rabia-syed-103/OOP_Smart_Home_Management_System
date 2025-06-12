#ifndef AC_H
#define AC_H
#include "Device.h"
class AC :public Device
{
	int temp;
	char mode;
public:
	AC();
	AC(int _id,MyStr _name, bool _isON);
	AC(const AC& other);
	AC& operator=(const AC& other);
	void turnOn() override;
	void turnOff() override;
	void SetSetting() override;
	~AC();

};
#endif // !AC_H

