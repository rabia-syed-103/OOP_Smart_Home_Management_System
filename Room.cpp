#include "Room.h"

Room::Room()
{
}
Room::Room(int _id,MyStr _name, MyVector <Device*> _device):name(_name),id(_id)
{
	for (int i = 0; i < _device.size(); i++)
	{
		this->devices.push(_device[i]);
	}
}
Room::Room(int _id,MyStr _name):name(_name),id(_id)
{}

void Room::AddDevice(Device* dev)
{
	this->devices.push(dev);
}
void Room::RemoveDevice(Device* dev)
{
	int i = this->devices.find(dev);
	this->devices.delete_at(i);

}
bool Room::ToggleDevice(int deviceid, bool toggle)
{
	int i = TempleFind(deviceid, this->devices);
	if (toggle == 1)
	{
		this->devices[i]->turnOn();
		return 1;
	}
	else
	{
		this->devices[i]->turnOff();
		return 1;
	}
	return 0;

}
bool Room::UpdateDeviceSetting(int devicename)
{
	int i = TempleFind(devicename, this->devices);
	try
	{
		this->devices[i]->SetSetting();
	}
	catch (const MyStr error_mess)
	{
		cout << error_mess;

	}
	return 1;
}
MyStr Room::getname()
{ 
	return this->name;
}
Room :: ~Room()
{
	for (int i = 0; i < this->devices.size(); i++)
	{
		delete this->devices[i];
	}

}
int Room::getid()
{
	return this->id;
}


