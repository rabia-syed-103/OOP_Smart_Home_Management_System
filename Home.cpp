#include "Home.h"

Home::Home(const MyStr& _name, const string& filename):name(_name)
{
	this->eventlog.initialize(filename);
}

Home* Home::getinstance(const MyStr& _name, const string& filename)
{
	if (Main == nullptr)
	{
		Main = new Home(_name,filename);
	}
	return Main;
}

void Home::AddUser(User* _user)
{
	this->users.push(_user);
}

void Home::AddRoom(Room* _room)
{
	this->rooms.push(_room);
}

void Home::AddDeviceToRoom(int _roomid, Device* _device)
{
	try
	{
		int i = TempleFind(_roomid, this->rooms);
		this->rooms[i]->AddDevice(_device);
	}
	catch (const MyStr& error)
	{
		throw;
	}
}

bool Home::ToggleDevicePower(int _roomid, int deviceid, MyStr username, bool toggle)
{
	int i = TempleFindbyName(username, this->users);

	try
	{
		this->users[i]->CanToggleDevice();
	

	}
	catch(const MyStr& error)
	{
		cout << error;
	}
	int j = TempleFind(_roomid, this->rooms);
	this->rooms[j]->ToggleDevice(deviceid, toggle);
	return 1;
}
bool Home::ChangeSetting(int _roomid, int deviceid, MyStr username)
{
	try
	{
		int i = TempleFindbyName(username, this->users);
		this->users[i]->CanToggleDevice();
		int j = TempleFind(_roomid, this->rooms);
		this->rooms[j]->UpdateDeviceSetting(deviceid);

	}
	catch (const MyStr error)
	{
		throw;
	}
	return 1;
}
