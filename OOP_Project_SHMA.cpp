#include <iostream>
#include "MyStr.h"
#include "MyVector.h"
#include "TemplateFind.h"

#include "Home.h"
#include "Room.h"

#include "Device.h"
#include "Fan.h"
#include "Lock.h"
#include "Light.h"
#include "AC.h"
#include "Sensor.h"

#include "User.h"	
#include "AdultUser.h"

#include "ChildUser.h"

#include "GuestUser.h"


using namespace std;
Home* Home::Main = nullptr;

MyStr username(Home* myHome)
{
	myHome->useridprints();
	MyStr NAME;
	cout << "Enter Username :: ";
	cin.ignore();
	cin >> NAME;
	return NAME;
}
int ID(Home* myHome)
{
	myHome->roomidprints();
	int NAME;
	cout << "Enter Room ID :: ";
	cin >> NAME;
	return NAME;
}
int main()
{

	
	Home* myHome = Home::getinstance("MyHome", "Event.txt", "Energy.txt");
	Sensor* sensor = new Sensor(1, "Fire Sensor");
	myHome->AddRoom(new Room(1, "Kitchen"));
	User* mainuser = new AdultUser("Ali");
	myHome->AddUser(mainuser);
	myHome->AddDeviceToRoom(001, sensor, "Ali");
	int choice;
	while (true) {
		cout << "\n====== Smart Home Menu ======\n";
		cout << "1. Add User\n";
		cout << "2. Add Room\n";
		cout << "3. Add Device to Room\n";
		cout << "4. Toggle Device Power\n";
		cout << "5. Change Device Setting\n";
		cout << "6. Remove Device From Room\n";
		cout << "7. Trigger Sensor\n";
		cout << "8. Print Event Log\n";
		cout << "9. Print Energy Log\n";
		cout << "10. Print All Information of Home Using Serialize&Deserialize\n";
		cout << "11. Exit() \n";

		cout << "Enter choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			int ch;
			cout << "Select User Type :: \n1.Adult\n2.Guest\n3.Child\nChoose :: ";
			cin >> ch;
			cin.ignore();

			cout << "Enter Name :: ";
			MyStr name;
			cin >> name;
			User* newUser = nullptr;
			if (ch == 1)
			{
				newUser = new AdultUser(name);
			}
			else if (ch == 2)
			{
				newUser = new GuestUser(name);

			}
			else if (ch == 3)
			{
				newUser = new ChildUser(name);
			}
			else
			{
				cout << "Invalid Choice!";
			}
			if (newUser != nullptr)
			{
				myHome->AddUser(newUser);
			}

			break;
		}
		case 2:
		{
			cin.ignore();

			MyStr name;
			int id;
			cout << "Enter Room Name :: ";
			cin >> name;
			cout << "Enter ID :: ";
			cin >> id;
			myHome->AddRoom(new Room(id, name));
			break;
		}
		case 3:
		{
			Device* d = nullptr;
			MyStr _user = username(myHome);
			int _id = ID(myHome);
			cout << "Select Device :: \n1.Fan\n2.AC\n3.Light\n4.Lock\nChoose :: ";
			int ch;
			cin >> ch;
			if (ch == 1)
			{
				d = new Fan();
			}
			else if(ch == 2)
			{
				d = new AC();

			}
			else if(ch ==3)
			{
				d = new Light();

			}
			else if (ch == 4)
			{
				d = new Lock();

			}
			else
			{
				cout << "\nInvalid Entry!";
			}
			if (d != nullptr)
			{
				myHome->AddDeviceToRoom(_id, d, _user);
			}
			break;
		}
		case 4:
		{
			int _id = ID(myHome);
			MyStr _USER = username(myHome);
			cout << "Enter Device ID :: ";
			int did;
			cin >> did;
			cout << "Enter Toggling Mode :: ";
			bool mode;
			cin >> mode;
			myHome->ToggleDevicePower(_id, did, _USER, mode);
			break;
		}
		case 5:
		{
			int _id = ID(myHome);
			MyStr _USER = username(myHome);
			cout << "Enter Device ID :: ";
			int did;
			cin >> did;
			myHome->ChangeSetting(_id, did, _USER);
			break;
		}
		case 6:
		{
			int _id = ID(myHome);
			MyStr _USER = username(myHome);
			cout << "Enter Device ID :: ";
			int did;
			cin >> did;
			myHome->RemoveDeviceFromRoom(_id, did, _USER);
			break;
		}
		case 7:
		{
			cout << "By Default We have only 1 Sensor in Kitchen with ID 001.";
			myHome->triggerSensor(001, sensor);
			break;
		}
		case 8:
		{
			myHome->printEventlog();
			break;
		}
		case 9:
		{
			myHome->printEnergyLog();
			break;
		}
		case 10:
		{
			{
				fstream info("filename.bin", ios::out | ios::binary);
				myHome->serialize(info);
				info.close();
			}
			{
				fstream info("filename.bin", ios::in | ios::binary);
				myHome->deserialize(info);
				info.close();
			}
			myHome->Display();
			break;
		}
		case 11:
		{
			cout << "\nExiting will delete all the files since Home Owns them! If you still want to exit press 'e'\n";
			char exit;
			cin >> exit;
			if(exit == 'e')
				break;
		}

		default:
		{
			
			cout << "\nInvalid Choice!";
			break;
		}
		}

	}
}
