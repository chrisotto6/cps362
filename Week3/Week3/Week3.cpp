// Week3.cpp : main project file

#include "info.h"
#include "safeArray.h"

#include <iostream>
#include <string>
using namespace std;

int main()
{
	// Student info
	info myInfo;
	myInfo.identity("Week 2", __DATE__);
    
	// Create safe Arrays
	safeArray list1(5);
	safeArray list2(5);

	// Create first list
	cout << "list1 : " << list1 << endl;

	cout << "Enter 5 integers: ";
	cin >> list1;
	cout << endl;

	cout << "After filling list1: " << list1 << endl;

	// Create second list
	list2 = list1;
	cout << "list2 : " << list2 << endl;

	// Modify list1
	cout << "Enter 3 elements: ";

	for (int i = 0; i < 3; i++)
		cin >> list1[i];
	cout << endl;

	cout << "First three elements of list1: ";
	for (int i = 0; i < 3; i++)
		cout << list1[i] << " ";
	cout << endl;

	// Create the third list
	safeArray list3(-2, 6);

	cout << "list3: " << list3 << endl;

	list3[-2] = 7;
	list3[4] = 8;
	list3[0] = 54;
	list3[2] = list3[4] + list3[-2];

	cout << "list3: " << list3 << endl;

	return 0;
	system("PAUSE");
}

