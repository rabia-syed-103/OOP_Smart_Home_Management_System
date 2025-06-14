#include "Home.h"

Home::Home(const MyStr& _name, const MyStr& filename, const MyStr& filename1):name(_name)
{
	this->eventlog.initialize(filename);
	this->energylog.initialize(filename1);

}

Home* Home::getinstance(const MyStr& _name, const MyStr& filename, const MyStr& filename1)
{
	if (Main == nullptr)
	{
		Main = new Home(_name,filename,filename1);
	}
	return Main;
}

void Home::AddUser(User* _user)
{
	this->users.push(_user);
	MyStr name = _user->getname();
	MyStr mess = name.append(" Added to Home!");
	this->eventlog.writeMessage(mess);
}

void Home::AddRoom(Room* _room)
{
	this->rooms.push(_room);
	MyStr name = _room->getname();
	MyStr mess = name.append(" Added to Home!");
	this->eventlog.writeMessage(mess);

}

void Home::roomidprints()
{
	cout << "All Available Room IDs : ";
	for (int i = 0; i < this->rooms.size(); i++)
	{
		cout << this->rooms[i]->getid()<<" ";
	}
}

void Home::useridprints()
{
	cout << "All Available User Names : ";
	for (int i = 0; i < this->users.size(); i++)
	{
		cout << this->users[i]->getname() << " ";
	}
}

void Home::AddDeviceToRoom(int _roomid, Device* _device, MyStr _username)
{
	try
	{
		int j = TempleFindbyName(_username, this->users);
		this->users[j]->AddDevice();
		int i = TempleFind(_roomid, this->rooms);
		this->rooms[i]->AddDevice(_device);
		MyStr devname = _device->getname();
		
		MyStr roomname = this->rooms[i]->getname();
		MyStr mess = devname.append(" Added to ");
		mess = mess.append(roomname);
		this->eventlog.writeMessage(mess);
		cout << mess;

	}
	catch (const MyStr& error)
	{
		cout << error;
		this->eventlog.writeError(error);
	}
}

void Home::RemoveDeviceFromRoom(int _roomid, int device, MyStr _username)
{

	try
	{
		int j = TempleFindbyName(_username, this->users);
		this->users[j]->AddDevice();
		int i = TempleFind(_roomid, this->rooms);
		Device* _device = this->rooms[i]->getdevice(device);
		this->rooms[i]->RemoveDevice(_device);
		MyStr devname = _device->getname();

		MyStr roomname = this->rooms[i]->getname();
		MyStr mess = devname.append(" Removed From ");
		mess = mess.append(roomname);
		this->eventlog.writeMessage(mess);
		cout << mess;
	}
	catch (const MyStr& error)
	{
		cout << error;
		this->eventlog.writeError(error);
	}
}

bool Home::ToggleDevicePower(int _roomid, int deviceid, MyStr username, bool toggle)
{
	try
	{
		int i = TempleFindbyName(username, this->users);
		this->users[i]->CanToggleDevice();
		int j = TempleFind(_roomid, this->rooms);
		if (!(this->rooms[j]->ToggleDevice(deviceid, toggle)))
		{
			try
			{
				this->rooms[j]->RoomEnergyUpdate(deviceid);
			}
			catch (const MyStr& update)
			{
				this->energylog.writeUpdate(update);
			}
		}
		MyStr id = id.itos(deviceid);
		MyStr mess = username.append(" toggled device id ").append(id).append(" of ").append(this->rooms[j]->getname());
		this->eventlog.writeMessage(mess);
		cout << mess;
	}
	catch(const MyStr& error)
	{
		cout << error;
		this->eventlog.writeError(error);
	}
	
	return 1;
}
bool Home::ChangeSetting(int _roomid, int deviceid, MyStr username)
{
	try
	{
		int i = TempleFindbyName(username, this->users);
		this->users[i]->CanChangeSetting();
		int j = TempleFind(_roomid, this->rooms);
		this->rooms[j]->UpdateDeviceSetting(deviceid);

		MyStr id = id.itos(deviceid);
		MyStr mess = username.append(" changed some settings of device id ").append(id).append(" of ").append(this->rooms[j]->getname());
		this->eventlog.writeMessage(mess);
		cout << mess;
	}
	catch (const MyStr error)
	{
		cout << error;
		this->eventlog.writeError(error);
	}
	return 1;
}

Home::~Home()
{
	for (int i = 0; i < this->rooms.size(); i++)
	{
		delete this->rooms[i];
	}
}

void Home::serialize(fstream& f)
{
	const char* newname = this->name.c_str();
	int len = this->name.get_length(newname);
	f.write((char*)&len, sizeof(len));
	f.write(newname, len);
	for (int i = 0; i < this->rooms.size(); i++)
	{
		this->rooms[i]->serialize(f);
	}
	for (int i = 0; i < this->users.size(); i++)
	{
		this->users[i]->serialize(f);
	}
}

void Home::deserialize(fstream& f)
{
	int len = 0;
	f.read((char*)&len, sizeof(len));
	char* newname = new char[len + 1];
	f.read(newname, len);
	newname[len] = '\0';
	this->name.cpy(newname);
	for (int i = 0; i < this->rooms.size(); i++)
	{
		this->rooms[i]->deserialize(f);
	}
}

void Home::Display()
{
	cout << "Home Name :: " << this->name<<endl;
	cout << "Total Users :: " << this->users.size()<<endl;
	cout << "Total Rooms :: " << this->users.size()<<endl;
	cout << "\nUsers Detail\n";
	for (int i = 0; i < this->users.size(); i++)
	{
		this->users[i]->Display();
	}
	cout << "\nRooms Detail\n";
	for (int i = 0; i < this->rooms.size(); i++)
	{
		this->rooms[i]->Display();
	}
}

void Home::printEventlog()
{
	this->eventlog.PrintLog();
}

void Home::printEnergyLog()
{
	this->energylog.PrintEnergyMonitor();
}

void Home::triggerSensor(int roomID, Sensor* sensorName) {
	MyStr name;
	try
	{
		int i = TempleFind(roomID, this->rooms);
		name = this->rooms[i]->getname();
	}
	catch (const MyStr& error)
	{
		this->eventlog.writeError(error);
	}
	try
	{
		sensorName->detectEvent();
		
	}
	catch (const MyStr& newm)
	{
		MyStr newmess = newm;
		newmess = newmess.append(name).append("!");
		cout << newmess;
		this->eventlog.writeError(newmess);
	}	
}

void Home::Clear()
{
	this->energylog.cleanup();
	this->eventlog.cleanup();
}

