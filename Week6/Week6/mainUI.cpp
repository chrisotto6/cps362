// Header for the UI class

#include "mainUI.h"
#include <iostream>

using namespace std;

mainUI::mainUI()
{
}


mainUI::~mainUI()
{
}

void mainUI::mainMethod()
{
	// Create a new linked list and int
	unorderedLinkedList<int> list;
	int size;
	bool add = true;
	char option;

	// Get the number from the user
	cout << "Enter in a number: ";
	cin >> size;

	while (add) {
		list.insertLast(size);

		cout << "\nDo you want to add another number? (y/n)" << endl;
		cin >> option;
		if (option == 'y')
		{
			cout << "\nEnter in a number: ";
			cin >> size;
		}
		else {
			add = false;
		}
	}

	// Print out the list
	cout << "\nThe list conatins: " << endl;
	list.print();

	// Delete all instance of 9
	int param;
	cout << "\nEnter a value to remove all occurances of in the list: " << endl;
	cin >> param;
	list.deleteAllOccurances(param);

	// Print out the list
	cout << "\nThe list now contains: " << endl;
	list.print();

	// Delete the first 4
	cout << "\n\nRemove the smallest value from the list." << endl;
	list.deleteSmallest();

	// Print out the list
	cout << "\nThe list now contains: " << endl;
	list.print();
}