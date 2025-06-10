#include <iostream>
#include "MyStr.h"
using namespace std;

//Constructors
MyStr::MyStr() {
	this->len = 0;
	this->cap = 0;
	this->Cs = nullptr;
}
//C-MyStr to MyStr
MyStr::MyStr(const char* arr)
{
	this->len = get_length(arr);
	Cs = new char[this->len];
	for (this->cap = 0; this->cap < len; this->cap++)
	{
		Cs[this->cap] = arr[this->cap];
	}
}
void MyStr::cpy(const char* arr)
{
	delete[] this->Cs;
	this->len = get_length(arr);
	Cs = new char[this->len];
	for (this->cap = 0; this->cap < len; this->cap++)
	{
		Cs[this->cap] = arr[this->cap];
	}
}
//Value and MyStr
MyStr::MyStr(int val, const char a)
{
	this->len = val;
	Cs = new char[this->len];
	for (this->cap = 0; this->cap < len; this->cap++)
	{
		Cs[this->cap] = a;
	}
}
//MyStr To MyStr
MyStr::MyStr(const MyStr& str)
{
	this->len = str.len;
	this->Cs = new char[this->len];
	for (this->cap = 0; this->cap < len; this->cap++)
	{
		Cs[this->cap] = str.Cs[this->cap];
	}

}
//Number to MyStr Constructor
MyStr::MyStr(int n)
{
	MyStr str = str.itos(n);
	this->len = str.len;
	Cs = new char[this->len];
	for (this->cap = 0; this->cap < len; this->cap++)
	{
		Cs[this->cap] = str.Cs[this->cap];
	}
}

//Assignment Operator
MyStr& MyStr:: operator=(const MyStr& str)
{
	if (this != &str)
	{
		delete[] this->Cs;
		this->len = str.len;
		this->cap = str.cap;
		this->Cs = new char[this->len];
		for (int i = 0; i < this->len; i++)
			this->Cs[i] = str.Cs[i];
	}
	return *this;
}
//Integer to MyStr
MyStr MyStr::itos(int num)
{
	MyStr str;
	int temp = num;
	int track = num;
	if (temp < 0)
	{
		str.len++;
		temp = 0 - temp;
		track = 0 - num;
	}
	while (temp > 0)
	{
		temp = temp / 10;
		str.len++;
	}
	str.len++;
	temp = num;
	int remain;
	str.Cs = new char[str.len];
	for (int i = str.len - 2; i >= 0; i--)
	{
		remain = track % 10;
		track = track / 10;
		str.Cs[i] = remain + '0';

	}
	str.Cs[str.len - 1] = '\0';
	if (num < 0)
		str.Cs[0] = '-';
	str.cap = str.len;
	return str;
}
//MyStr to Integer
int  MyStr::stoi(const MyStr str)
{
	int num = 0;
	int multiplier = 1;
	int giv = 0;
	if (str.Cs[0] == '-')
		giv = 1;
	for (int i = str.len - 2; i >= giv; i--)
	{
		num = num + (str.Cs[i] - '0') * multiplier;
		multiplier *= 10;
	}
	if (str.Cs[0] == '-')
		num = 0 - num;
	return num;
}

//Replace 
MyStr MyStr::replace_first(char c)
{
	this->Cs[0] = c;
	return *this;
}

//Get Length
int MyStr::get_length(const char* arr)
{
	int i = 0;
	for (i = 0; arr[i] != '\0'; i++)
	{
	};
	i++;
	return i;
}
int MyStr::_get_length(const char* arr)
{
	int i = 0;
	for (i = 0; arr[i] != '\0'; i++)
	{
	};
	i++;
	return i;
}

//Print
void MyStr::Print()
{
	for (int i = 0; i < this->cap; i++)
		cout << Cs[i];
}
//Destructor

//Operators
char MyStr :: operator[](int i) const
{
	if (i <0 || i > this->len)
		return '-1';
	return this->Cs[i];
}
char& MyStr:: operator[](int i)
{
	return this->Cs[i];
}

//Insert
void MyStr::regrow_double(MyStr& str)
{

	MyStr temp(str.len + str.len, '\0');
	temp.cap = 0;
	for (int i = 0; i < str.len; i++)
	{
		temp.Cs[i] = str.Cs[i];
		temp.cap++;
	}

	str = temp;
}
void MyStr::insert_at(int i, char ch)
{
	if (i <0 || i > this->len)
		return;
	if (this->cap == this->len)
	{
		regrow_double(*this);
	}
	for (int j = this->cap; j >= i; j--)
	{
		this->Cs[j + 1] = this->Cs[j];
	}
	this->Cs[i] = ch;


}
void MyStr::insert_at(int i, const MyStr sub)
{
	if (i <0 || i > this->len)
		return;

	for (int j = 0; j < sub.cap; j++)
	{
		this->insert_at(i, sub.Cs[j]);
		this->cap++;
		i++;
	}


}


//Equality
bool MyStr::is_equal(const MyStr& str)
{
	if (this->cap != str.cap)
		return 0;
	for (int i = 0; i < this->cap; i++)
	{
		if (this->Cs[i] != str.Cs[i])
			return 0;
	}
	return 1;
}
bool MyStr::is_less(const MyStr& str)
{
	int loop_end;
	loop_end = str.cap;
	if (this->cap < str.cap)
		loop_end = this->cap;
	for (int i = 0; i < loop_end; i++)
	{
		if (this->Cs[i] < str.Cs[i])
			return 1;
	}
	return 0;
}
bool MyStr::is_greater(const MyStr& str)
{
	int loop_end;
	loop_end = str.cap;
	if (this->cap < str.cap)
		loop_end = this->cap;
	for (int i = 0; i < loop_end; i++)
	{
		if (this->Cs[i] > str.Cs[i])
			return 1;
	}
	return 0;
}

//Destructor
MyStr :: ~MyStr()
{
	delete[] Cs;
}


//Trim
MyStr MyStr::Trim(const MyStr& str)
{

	int i = 0;
	int j = str.len - 2;
	for (i; i < str.cap; i++)
	{
		if (str.Cs[i] != ' ')
			break;
	}
	for (j; j >= 0; j--)
	{
		if (str.Cs[j] != ' ')
			break;
	}
	MyStr temp((j - i) + 2, '\0');
	temp.cap = 0;
	for (i; i <= j; i++)
	{
		temp.Cs[temp.cap] = str.Cs[i];
		temp.cap++;

	}
	temp.Cs[temp.cap] = '\0';
	temp.cap++;
	return temp;
}
MyStr MyStr::Trim(const char* str)
{
	MyStr t;
	int len = MyStr::_get_length(str);
	int i = 0;
	int j = len - 2;
	for (i; i < len; i++)
	{
		if (str[i] != ' ')
			break;
	}
	for (j; j >= 0; j--)
	{
		if (str[j] != ' ')
			break;
	}
	MyStr temp((j - i) + 2, '\0');
	temp.cap = 0;
	for (i; i <= j; i++)
	{
		temp.Cs[temp.cap] = str[i];
		temp.cap++;

	}
	temp.Cs[temp.cap] = '\0';
	temp.cap++;
	return temp;
}

//Clear
void MyStr::clear()
{
	delete[] this->Cs;
	this->len = 0;
	this->cap = 0;
	this->Cs = nullptr;
}

//Split & Tokenization
void MyStr::regrow(MyStr& str, char a)
{
	MyStr temp;
	temp.len = str.len + 1;
	temp.Cs = new char[temp.len];
	temp.cap = str.cap + 1;
	int cp = 0;
	for (cp = 0; cp < str.cap; cp++)
	{
		temp.Cs[cp] = str.Cs[cp];
	}
	temp.Cs[str.cap] = a;
	str = temp;
}
MyStr* MyStr::split(char delim, int& count) const
{
	for (int i = 0; i < this->cap; i++)
	{
		if (this->Cs[i] == delim || i == this->cap - 1)
		{
			count++;

		}
	}
	MyStr* str = new MyStr[count];
	int j = 0;
	for (int i = 0; i < this->len; i++)
	{
		if (j < count)
		{
			if (this->Cs[i] != delim)
			{
				for (i; Cs[i] != delim && Cs[i] != '\0'; i++)
				{
					str[j].regrow(str[j], Cs[i]);
				}
				str[j].regrow(str[j], '\0');
				j++;
			}
		}
	}
	return str;
}
bool MyStr::is_delim(char* delim, char a)
{

	int len = MyStr::_get_length(delim);
	for (int i = 0; i < len; i++)
	{
		if (a == delim[i])
			return 1;
	}
	return 0;
}
MyStr* MyStr::split(char* delim, int& count) const
{
	for (int i = 0; i < this->cap; i++)
	{
		if (MyStr::is_delim(delim, Cs[i]) || Cs[i] == this->cap - 1)
		{
			count++;

		}
	}
	MyStr* str = new MyStr[count];
	int j = 0;
	for (int i = 0; i < this->len; i++)
	{
		if (j < count)
		{
			if (!(MyStr::is_delim(delim, this->Cs[i])))
			{
				for (i; (!MyStr::is_delim(delim, this->Cs[i])) && Cs[i] != '\0'; i++)
				{
					str[j].regrow(str[j], Cs[i]);
				}
				str[j].regrow(str[j], '\0');
				j++;
			}
		}
	}
	return str;
}

//Upper/Lower
void MyStr::upper()
{
	for (int i = 0; i < this->cap; i++)
	{
		if (this->Cs[i] > 96 && this->Cs[i] < 123)
			this->Cs[i] -= 32;
	}
}
void MyStr::lower()
{
	for (int i = 0; i < this->cap; i++)
	{
		if (this->Cs[i] > 64 && this->Cs[i] < 91)
			this->Cs[i] += 32;
	}
}
//Concatination
MyStr MyStr::concat(const MyStr& s2)const
{
	MyStr res((this->cap + s2.cap) - 1, '\0');
	res.cap = 0;
	for (int i = 0; i < this->cap - 1; i++)
	{
		res.Cs[res.cap] = this->Cs[i];
		res.cap++;
	}
	for (int i = 0; i < s2.cap; i++)
	{
		res.Cs[res.cap] = s2.Cs[i];
		res.cap++;
	}
	return res;
}
MyStr& MyStr::append(const MyStr& s2)
{
	int j;
	this->Cs[this->cap - 1] = s2.Cs[0];
	for (int i = 1; i < s2.cap; i++)
	{
		this->regrow(*this, '\0');
		this->Cs[this->cap - 1] = s2.Cs[i];

	}
	return *this;
}

//Regrow int

int* MyStr::regrow_int(int* arr, int size, int n)
{
	int* narr = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		narr[i] = arr[i];
	}
	narr[size] = n;
	size++;
	delete[] arr;
	arr = new int[size];
	for (int i = 0; i < size; i++)
		arr[i] = narr[i];
	return arr;
}
// 13
int* MyStr::all_sub_strings(const MyStr& substring, int& count) const
{
	int* arr = nullptr;
	for (int i = 0; i < this->cap - 1; i++)
	{
		bool flag = 1;
		int k = i;

		for (int j = 0; j < substring.cap - 1; j++)
		{
			if (substring.Cs[j] != this->Cs[k])
				flag = 0;
			k++;
		}
		if (flag)
		{
			arr = MyStr::regrow_int(arr, count, i);
			count++;
		}
	}
	return arr;
}

//14 
//First
int MyStr::find_first(char ch) const
{
	for (int i = 0; i < this->cap; i++)
	{
		if (ch == this->Cs[i])
			return i;
	}

}
int MyStr::find_first(const MyStr& str) const
{
	for (int i = 0; i < this->cap - 1; i++)
	{
		bool flag = 1;
		int k = i;

		for (int j = 0; j < str.cap - 1; j++)
		{
			if (str.Cs[j] != this->Cs[k])
				flag = 0;
			k++;
		}
		if (flag)
		{
			return i;
		}
	}
}
//Last
int MyStr::find_last(char ch)
{
	for (int i = this->cap - 2; i >= 0; i--)
	{
		if (ch == this->Cs[i])
			return i;
	}

}
int MyStr::find_last(const MyStr& str) const
{
	for (int i = this->cap - 2; i >= 0; i--)
	{
		bool flag = 1;
		int k = i;

		for (int j = str.cap - 2; j >= 0; j--)
		{
			if (str.Cs[j] != this->Cs[k])
				flag = 0;
			k--;
		}
		if (flag)
		{
			k++;
			return k;
		}
	}
}

//All
int* MyStr::find_all(char ch, int& count)
{
	int* arr = nullptr;
	for (int i = 0; i < this->cap; i++)
	{
		if (ch == this->Cs[i])
		{
			arr = MyStr::regrow_int(arr, count, i);
			count++;
		}
	}
	return arr;
}
//Remove And Add
void MyStr::remove_at(int i)
{
	MyStr temp(this->len - 1, '\0');
	int k = 0;
	for (int j = 0; j < this->len; j++)
	{
		if (j != i)
		{
			temp.Cs[k] = this->Cs[j];
			k++;
		}
	}
	*this = temp;

}
//All Removals
void MyStr::remove_first(char ch)
{
	int i = this->find_first(ch);
	this->remove_at(i);
}
void MyStr::remove_all(char ch)
{
	MyStr temp(this->len - 1, '\0');
	int k = 0;
	for (int i = 0; i < this->len; i++)
	{
		if (this->Cs[i] != ch)
		{
			temp.Cs[k] = this->Cs[i];
			k++;
		}
	}
	*this = temp;
}
void MyStr::remove_last(char ch)
{
	int i = this->find_last(ch);
	this->remove_at(i);
}
istream& operator>>(istream& in, MyStr& str)
{
	char temp[10000];
	in.getline(temp, 1000, ',');
	str.cpy(temp);
	str = str.Trim(str);
	return in;
}
ostream& operator<<(ostream& out, const MyStr& str)
{
	for (int i = 0; i < str.cap - 1; i++)
		out << str.Cs[i];
	return out;
}
void MyStr::helper_date(const MyStr& str, int& d, int& m, int& y)const
{
	int i = 0;
	for (i; str.Cs[i] != '/'; i++)
	{
		d = d * 10 + (str.Cs[i] - '0');
	}
	i++;
	for (i; str.Cs[i] != '/'; i++)
		m = m * 10 + (str.Cs[i] - '0');
	i++;
	for (i; i < str.cap - 1; i++)
	{
		y = y * 10 + (str.Cs[i] - '0');
	}
}