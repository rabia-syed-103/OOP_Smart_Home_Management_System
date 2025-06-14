#ifndef HOME_H
#define HOME_H
#include "User.h"
#include "Device.h"
#include "EventLogger.h"
#include "EnergyMonitor.h"
#include "MyStr.h"
#include "MyVector.h"
#include "Room.h"
#include "Sensor.h"
class Home
{
	static Home* Main;
	MyStr name;
	MyVector <Room*> rooms;
	MyVector <User*> users;
	EventLogger eventlog;
	EnergyMonitor energylog;

	Home(const MyStr& _name, const MyStr& filename, const MyStr& filename1);
	Home(const Home& other) = delete;

public:
	static Home* getinstance(const MyStr& _name, const MyStr& filename, const MyStr& filename1);
	void AddUser(User* _user);
	void AddRoom(Room* _room);
	void roomidprints();
	void useridprints();
	void AddDeviceToRoom(int _roomid, Device* _device,MyStr _username);
	void RemoveDeviceFromRoom(int _roomid, int _device, MyStr _username);
	bool ToggleDevicePower(int _roomid, int deviceid, MyStr username,bool toggle);
	bool ChangeSetting(int _roomid, int deviceid, MyStr username);
	~Home();
	void serialize(fstream& f);
	void deserialize(fstream& f);
	void Display();
	void printEventlog();
	void printEnergyLog();
	void triggerSensor(int roomName, Sensor* sensor);
	void Clear();

};
#endif // !HOME_H
