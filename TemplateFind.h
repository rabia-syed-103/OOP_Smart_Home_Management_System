#ifndef TEMPLATEFIND_H
#define TEMPLATEFIND_H
#include "MyVector.h"
#include "MyStr.h"

template <typename T>

int T(MyStr obj, MyVector <T*>& list)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (obj.is_equal(list[i]->getname()))
		{
			return i;
		}
	}
	return -1;
}

#endif // !TEMPLATEFIND_H
