#include "User.h"

User::User()
{
}
User::User(MyStr _name) :name(_name)
{

}
User::User(const User& other):name(other.name)
{}
User& User::operator=(const User& other)
{
	if (this != &other)
	{
		this->name = other.name;
	}
	return *this;
}

MyStr User::getname()
{
	return this->name;
}
