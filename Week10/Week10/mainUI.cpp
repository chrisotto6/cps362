// Handles the UI interactions between the main file and the other class files

#include "mainUI.h"

using namespace std;

mainUI::mainUI()
{
}

mainUI::~mainUI()
{
}

void mainUI::mainMethod()
{
	// Get the user input to build out the array list
	int num;
	char choice = 'y';
	arrayListType<int> intList;

	while (choice == 'y') {
		cout << "\n\nEnter a number to add to the array..." << endl;
		cin >> num;

		intList.insert(num);

		cout << "\n\nDo you want to enter a new number?" << endl;
		cin >> choice;
	}

	// Print the list out to the user prior to sorting
	cout << "\n\nThe array list before sorting: ";
	intList.print();

	// Process the quick sort of the array list
	intList.quickSort();

	// Print the list out to the user after sorting
	cout << "The array list after sorting: ";
	intList.print();
	cout << "\n\n";
}