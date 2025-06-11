#ifndef CHILDUSER_H
#define CHILDUSER_H
#include <iostream>
#include "MyStr.h"
#include "User.h"
class ChildUser :public User
{

public:
	ChildUser();
	ChildUser(MyStr _name);
	ChildUser(const User& other);
	ChildUser& operator=(const User& other);
	bool CanChangeSetting()override;
	bool CanToggleDevice()override;
};
#endif // !CHILDUSER_H
