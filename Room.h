#ifndef ROOM_H
#define ROOM_H
#include "MyStr.h"
#include "MyVector.h"
#include "Device.h"
#include "TemplateFind.h"
class Room
{
	MyStr name;
	MyVector <Device*> devices;
public:
	Room();
	Room(MyStr _name, MyVector <Device*> _device);
	Room(MyStr _name);
	Room(const Room& other);
	void AddDevice(Device* dev);
	void RemoveDevice(Device* dev);
	bool ToggleDevice(MyStr devicename,bool toggle);
	bool UpdateDeviceSetting(MyStr devicename);
	MyStr getname();

};
#endif // !ROOM_H
