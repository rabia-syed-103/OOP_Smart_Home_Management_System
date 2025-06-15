#ifndef MYSTR_H
#define MYSTR_H
#include <iostream>
using namespace std;
class MyStr {
	int len;
	int cap;
	char* Cs;
public:
	//Length Find
	int get_length(const char* arr);
	static int _get_length(const char* arr);
	//Constructors 6
	MyStr();
	MyStr(const char* arr);
	MyStr(char* arr);
	MyStr(int val, const char a);
	MyStr(const MyStr& str);
	MyStr(int n);
	MyStr& operator=(const MyStr& str);
	void cpy(const char* arr);
	//Integer to MyStr
	MyStr itos(int num);
	//MyStr to Integer
	static int stoi(const MyStr str);
	//Replace 
	MyStr replace_first(char c);

	//Operators
	char operator[](int i) const;
	char& operator[](int i);

	//Print()
	void Print();
	const char* c_str() const;
	//Insert
	void regrow_double(MyStr& str);
	void insert_at(int i, char ch);
	void insert_at(int i, const MyStr sub);
	//Remove Space 
	//1
	MyStr Trim(const MyStr& str);
	//2 Static
	static MyStr Trim(const char* str);
	//Equality Check
	bool is_equal(const MyStr& str);
	bool is_less(const MyStr& str);
	bool is_greater(const MyStr& str);

	//10.	
	MyStr* split(char delim, int& count) const;
	void regrow(MyStr& str, char a);
	MyStr* split(char* delim, int& count) const;
	static bool is_delim(char* delim, char a);

	//Upper/Lower
	void upper();
	void lower();
	//Concatination
	MyStr concat(const MyStr& s2)const;
	MyStr& append(const MyStr& s2);


	//Substring
	int* all_sub_strings(const MyStr& substring, int& count) const;
	static int* regrow_int(int* arr, int size, int n);

	//14 
	//First
	int find_first(char ch) const;
	int find_first(const MyStr& str) const;
	//Last
	int find_last(char ch);
	int find_last(const MyStr& str) const;

	//Remove

	void remove_at(int i);

	//All Remove
	void remove_first(char ch);
	void remove_all(char ch);
	void remove_last(char ch);
	void pushback(char ch);
	//Clear
	void clear();
	//All
	int* find_all(char ch, int& count);
	friend istream& operator>>(istream& in, MyStr& str);
	friend ostream& operator<<(ostream& out, const MyStr& str);
	void helper_date(const MyStr& str, int& d, int& m, int& y) const;
	//Destructor
	~MyStr();
};


#endif

