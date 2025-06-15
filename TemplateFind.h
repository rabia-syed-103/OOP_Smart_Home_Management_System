#ifndef TEMPLATEFIND_H
#define TEMPLATEFIND_H
#include "MyVector.h"
#include "MyStr.h"

template <typename T>

int TempleFind(int obj, MyVector <T*>& list)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (obj == list[i]->getid())
		{
			return i;
		}
	}
	//cout << obj;
	throw MyStr("\n!Not Found!");
}
template <typename T>

int TempleFindbyName(MyStr obj, MyVector <T*>& list)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (obj.is_equal(list[i]->getname()))
		{
			return i;
		}
	}
	//cout << obj;
	throw MyStr("\n!Not Found!");

}
template <typename T>

int CheckFind(int obj, MyVector <T*>& list)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (obj == list[i]->getid())
		{
			throw MyStr("\nID already Exists\n");
		}
	}
	//cout << obj;
	return 1;
}

#endif // !TEMPLATEFIND_H
