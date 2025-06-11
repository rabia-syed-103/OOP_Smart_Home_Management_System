#ifndef GUESTUSER_H
#define GUESTUSER_H
#include <iostream>
#include "MyStr.h"
#include "User.h"
class GuestUser :public User
{

public:
	GuestUser();
	GuestUser(MyStr _name);
	GuestUser(const User& other);
	GuestUser& operator=(const User& other);
	bool CanChangeSetting()override;
	bool CanToggleDevice()override;
};
#endif // !GUESTUSER_H
