#include "ChildUser.h"

ChildUser::ChildUser()
{
}
ChildUser::ChildUser(MyStr _name) :User(_name)
{

}
ChildUser::ChildUser(const User& other) :User(other)
{}
ChildUser& ChildUser::operator=(const User& other)
{
	if (this != &other)
	{
		User:: operator=(other);
	}
	return *this;
}

bool ChildUser::CanChangeSetting()
{
	throw MyStr("\nWARNING!\nChild Cannot Change Setting.\n");
	return false;
}

bool ChildUser::CanToggleDevice()
{
	throw MyStr("\nWARNING!\nChild Cannot Toggle.\n");


	return false;
}

ChildUser::~ChildUser()
{
}

void ChildUser::Display()
{
	this->print();
}

bool ChildUser::AddDevice()
{
	throw MyStr("Child Cannot Add Device!");
}


