#ifndef ADULTUSER_H
#define ADULTUSER_H
#include <iostream>
#include "MyStr.h"
#include "User.h"
class AdultUser:public User
{
	
public:
	AdultUser();
	AdultUser(MyStr _name);
	AdultUser(const User& other);
	AdultUser& operator=(const User& other);
	bool CanChangeSetting()override;
	bool CanToggleDevice()override;
	~AdultUser();
};
#endif // !ADULTUSER_H
