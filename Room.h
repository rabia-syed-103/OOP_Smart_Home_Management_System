#ifndef ROOM_H
#define ROOM_H
#include "MyStr.h"
#include "MyVector.h"
#include "Device.h"
#include "TemplateFind.h"
class Room
{
	int id;
	MyStr name;
	MyVector <Device*> devices;
public:
	Room();
	Room(int _id,MyStr _name, MyVector <Device*> _device);
	Room(int _id,MyStr _name);
	Room(const Room& other) = delete;
	void AddDevice(Device* dev);
	void RemoveDevice(Device* dev);
	bool ToggleDevice(int deviceid,bool toggle);
	bool UpdateDeviceSetting(int devicename);
	MyStr getname();
	int getid();
	void RoomEnergyUpdate(int deviceid);
	~Room();
	void serialize(fstream& f);
	void deserialize(fstream& f);
	void Display();
	Device* getdevice(int i);
};
#endif // !ROOM_H


