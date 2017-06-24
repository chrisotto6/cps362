// Programmer: Chris Otto
// Purpose   : The safeArray is the main operational component for testing the bounds of the array

#ifndef SAFEARRAY_H
#define SAFEARRAY_H

#include <iostream>

using namespace std;

class safeArray
{
	friend ostream& operator<<(ostream&, const safeArray&);
	friend istream& operator >> (istream&, safeArray&);

	private:
		int lower;
		int upper;
		int *aPtr;
	public:
		const safeArray& operator=(const safeArray &right);

		safeArray(int up);
		safeArray(int low, int up);
		safeArray();
		safeArray(const safeArray &copy);
		~safeArray();

		int &operator[] (int);
		const int &operator[](int) const;

		bool operator==(const safeArray &right);
		bool operator!=(const safeArray &right);
};
#endif