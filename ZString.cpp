#include "stdafx.h"
#include "ZString.h"
#include "string.h"



ZString::ZString()
{
	str = NULL;
}

ZString::ZString(const ZString& y)
{
	if (!y.str)
		str = NULL;
	else
	{
		str = new char[strlen(y.str) + 1];
		strcpy_s(str, strlen(y.str) + 1, y.str);
	}
}


ZString::~ZString()
{
	if (str)
	{
		delete []str;
	}
}

ZString* ZString::operator + (ZString& y)
{
	ZString* z = new ZString();
	z->str = new char[y.getLength() + getLength() + 1];
	strcpy_s(z->str, y.getLength() + getLength() + 1, str);
	strcat_s(z->str, y.getLength() + getLength() + 1, y.str);
	return z;
}

void ZString::operator = (ZString &y)
{
	if (str != NULL)
		delete[] str;
	str = new char[y.getLength() + 1];
	strcpy_s(str, y.getLength()+ 1, y.str);
}

void ZString::operator = (ZString* y)
{
	if (str != NULL)
		delete[] str;
	str = new char[y->getLength() + 1];
	strcpy_s(str,y->getLength()+ 1, y->str);
	delete y;
}

istream& operator >> (istream& in, ZString y)
{
	list<char>string;
	char c;
	while ((c = getchar()) != '\n')
		string.push_back(c);
	y.str = new char[string.size() + 1];
	int i = 0;
	for (auto &it : string)
	{
		y.str[i] = (char)it;
		i++;
	}
	y.str[i] = '\0';
	return in;
}