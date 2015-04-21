#pragma once

#include <cstring>
#include <iostream>
#include <list>

using namespace std;

class ZString
{
public:
	
	ZString* operator + (ZString& y);

	template<class T>ZString* operator + (T y)
	{
		ZString* z = new ZString();
		z->str = new char[strlen(y) + getLength() + 1];
		strcpy_s(z->str, strlen(y)+getLength()+1, str);
		strcat_s(z->str, strlen(y) + getLength() + 1, y);
	}

	void operator = (ZString& y);

	void operator = (ZString* y);
	
	template<class T>void operator = (T y)
	{
		if (str != NULL)
			delete[] str;
		str = new char[strlen(y) + 1];
		strcpy_s(str, strlen(y) + 1, y);
	}

	ZString();
	ZString(const ZString&); //不能用ZString 会出现死循环 一直调用本函数  不用引用传值会导致很多copy的问题  加上const

	void output(ZString y)
	{
		cout << y.str << endl;
	}

	template<class T>ZString(T y)
	{
		str = new char[strlen(y) + 1];
		strcpy_s(str, strlen(y) + 1, y);
	}

	int getLength(){ return str?strlen(str):0 ; }


	template<class T>
	friend ostream& operator << (ostream& out, T& y)
	{
		out << y.str;
		return out;
	}
	 ZString(ZString&& rhs) : str(rhs.str)   { rhs.str = nullptr; }
	friend istream& operator >> (istream& in, ZString y);
	

	~ZString();
private:
	char* str;
};

