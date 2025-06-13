#include "User.h"
#include <fstream>
User::User()
{
}
User::User(MyStr _name) :name(_name)
{

}
User::User(const User& other) :name(other.name)
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

void User::serialize(fstream& f)
{
	const char* newname = this->name.c_str();
	int len = this->name.get_length(newname);
	f.write((char*)&len, sizeof(len));
	f.write(newname, len);
}

void User::deserialize(fstream& f)
{
	int len;
	f.read((char*)&len, sizeof(len));
	char* newname = new char[len + 1];
	f.read(newname, len);
	newname[len] = '\0';
	this->name.cpy(newname);
	
}

