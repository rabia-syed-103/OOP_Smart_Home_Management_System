#ifndef USER_H
#define USER_H
#include <iostream>
#include "MyStr.h"
class User
{
	MyStr name;
public:
	User();
	User(MyStr _name);
	User(const User& other);
	User& operator=(const User& other);
	virtual bool CanChangeSetting() = 0;
	virtual bool CanToggleDevice() = 0;
	MyStr getname();
	void serialize(fstream& f);
	void deserialize(fstream& f);
};
#endif // !USER_H
