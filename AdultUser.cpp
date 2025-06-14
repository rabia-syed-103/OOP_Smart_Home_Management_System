#include "AdultUser.h"

AdultUser::AdultUser()
{
}
AdultUser::AdultUser(MyStr _name) :User(_name)
{

}
AdultUser::AdultUser(const User& other) :User(other)
{}
AdultUser& AdultUser::operator=(const User& other)
{
	if (this != &other)
	{
		User:: operator=(other);
	}
	return *this;
}

bool AdultUser::CanChangeSetting()
{

	return true;
}

bool AdultUser::CanToggleDevice()
{
	return true;
}
AdultUser:: ~AdultUser()
{}

void AdultUser::Display()
{
	this->print();
}

bool AdultUser::AddDevice()
{
	return true;
}


