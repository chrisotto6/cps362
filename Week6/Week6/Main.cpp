// Main.cpp contains the main project logic for the assignment

#include "info.h"
#include "occurances.h"
#include <iostream>

using namespace std;

void main()
{
	// Student info
	info myInfo;
	myInfo.identity("", __DATE__);

	// Create a new linked list
	occurances<int>* list;

	list->insertFirst(5);
	list->insertFirst(9);
	list->insertFirst(4);
	list->insertFirst(9);
	list->insertFirst(3);
	list->insertFirst(9);
	list->insertFirst(4);

	// Print out the list
	cout << "The list conatins: " << endl;
	list->print();

	// Delete all instance of 9
	cout << "Remove all '9' values from list...." << endl;
	list->deleteAllOccurances(9);

	// Print out the list
	cout << "\nThe list now contains: " << endl;
	list->print();

	// Delete the first 4
	cout << "Remove the first 4 value from the list...." << endl;
	list->deleteOneOccurance(4);

	// Print out the list
	cout << "The list now contains: " << endl;
	list->print();

	cin.ignore();
	system("PAUSE");
}