#include "Room.h"

Room::Room()
{
}
Room::Room(MyStr _name, MyVector <Device*> _device):name(_name),devices(_device)
{
}
Room::Room(MyStr _name):name(_name)
{}
Room::Room(const Room& other):name(other.name),devices(other.devices)
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
bool Room::ToggleDevice(MyStr devicename, bool toggle)
{
	int i = TempleFind(devicename, this->devices);
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
bool Room::UpdateDeviceSetting(MyStr devicename)
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
