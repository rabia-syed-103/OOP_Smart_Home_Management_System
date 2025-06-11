#include "GuestUser.h"

GuestUser::GuestUser()
{
}
GuestUser::GuestUser(MyStr _name) :User(_name)
{

}
GuestUser::GuestUser(const User& other) :User(other)
{}
GuestUser& GuestUser::operator=(const User& other)
{
	if (this != &other)
	{
		User:: operator=(other);
	}
	return *this;
}

bool GuestUser::CanChangeSetting()
{
	throw MyStr("\nWARNING!\nGuest Cannot Change Setting.");
	return false;
}

bool GuestUser::CanToggleDevice()
{
	return true;
}
