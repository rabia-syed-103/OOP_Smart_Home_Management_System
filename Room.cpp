#include "Room.h"
#include <fstream>

Room::Room():id('\0')
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
	try
	{
		CheckFind(dev->getid(), this->devices);
		this->devices.push(dev);
	}
	catch (const MyStr& error)
	{
		throw error;
	}
}
void Room::RemoveDevice(Device* dev)
{
	try
	{
		int i = this->devices.find(dev);
		this->devices[i]->RemoveDevice();
		this->devices.delete_at(i);
	}
	catch (const MyStr& error)
	{
		throw;
	}

}
bool Room::ToggleDevice(int deviceid, bool toggle)
{
	try
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
		
			return 0;
		}
	}
	catch (const MyStr error)
	{
		throw;
	}
	return 0;

}
bool Room::UpdateDeviceSetting(int devicename)
{
	try 
	{
		int i = TempleFind(devicename, this->devices);	
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
void Room::serialize(fstream& f)
{
	f.write((char*)&id, sizeof(id));
	const char* newname = this->name.c_str();
	int len = this->name.get_length(newname);
	f.write((char*)&len, sizeof(len));
	f.write(newname, len);
	for (int i = 0; i < this->devices.size(); i++)
	{
		this->devices[i]->serialize(f);
	}

}
void Room::deserialize(fstream& f)
{
	f.read((char*)&id, sizeof(id));
	int len;
	f.read((char*)&len, sizeof(len));
	char* newname = new char[len + 1];
	f.read(newname, len);
	newname[len] = '\0';
	this->name.cpy(newname);
	for (int i = 0; i < this->devices.size(); i++)
	{
		this->devices[i]->deserialize(f);
	}

}
void Room::Display()
{
	cout << "Room Name :: " << this->name;
	cout << "\nDevice Details ::\n";
	for (int i = 0; i < this->devices.size(); i++)
	{
		this->devices[i]->Display();
	}
	cout << endl;
}
Device* Room::getdevice(int i)
{
	for (int j = 0; j < this->devices.size(); j++)
	{
		if(this->devices[i]->getid() == i)
			return this->devices[j];

	}
}
int Room::getid()
{
	return this->id;
}

void Room::RoomEnergyUpdate(int deviceid)
{
	int i = TempleFind(deviceid, this->devices);

	try
	{
		this->devices[i]->EnergyUsed();
	}
	catch (const MyStr& update)
	{
		MyStr newupdate = "Room Name : ";
		newupdate = newupdate.append(this->getname()).append(update);
		throw MyStr(newupdate);
	}
}




