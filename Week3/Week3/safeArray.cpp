//Programmer:  Chris Otto
//Purpose   :  The implementation of the safeArray class

#include "safeArray.h"
#include <iostream> 
using namespace std;

safeArray::safeArray()
{
	lower = 0;
	upper = 0;
}

safeArray::safeArray(const safeArray & copy)
{
}

safeArray::safeArray(int low, int up)
{
	lower = low;
	upper = (up - low - 1);
}

safeArray::~safeArray()
{
}

int & safeArray::operator[](int)
{
	// TODO: insert return statement here
}

const int & safeArray::operator[](int) const
{
	// TODO: insert return statement here
}

bool safeArray::operator==(const safeArray & right)
{
	return false;
}

bool safeArray::operator!=(const safeArray & right)
{
	return false;
}

ostream & operator<<(ostream &, const safeArray &)
{
	// TODO: insert return statement here
}

istream & operator >> (istream &, safeArray &)
{
	// TODO: insert return statement here
}

const safeArray & safeArray::operator=(const safeArray & right)
{
	// TODO: insert return statement here
}

safeArray::safeArray(int up)
{
}
