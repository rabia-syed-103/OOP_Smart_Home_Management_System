#ifndef HOME_H
#define HOME_H
#include "User.h"
#include "Device.h"
#include "EventLogger.h"
#include "EnergyMonitor.h"
#include "MyStr.h"
#include "MyVector.h"
#include "Room.h"
class Home
{
	static Home* Main;
	MyStr name;
	MyVector <Room*> rooms;
	MyVector <User*> users;
	EventLogger eventlog;
	Home(const MyStr& _name, const string& filename);
	Home(const Home& other) = delete;

public:
	static Home* getinstance(const MyStr& _name, const string& filename);
	void AddUser(User* _user);
	void AddRoom(Room* _room);
	void AddDeviceToRoom(int _roomid, Device* _device);
	bool ToggleDevicePower(int _roomid, int deviceid, MyStr username,bool toggle);
	bool ChangeSetting(int _roomid, int deviceid, MyStr username);


};
#endif // !HOME_H
