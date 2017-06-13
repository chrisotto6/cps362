// Week1.cpp : main project file.

#include "info.h"
#include "PersonType.h"
#include <iostream>
using namespace std;

int main()
{
	info myInfo;

	myInfo.identity("Week 1", __DATE__);
	personType personOne("Chris", "Mitchell", "Otto");
	personOne.print();

	cout << "\nCheck to see if the first and last name are these names: Bob Otto\n" << endl;
	if (personOne.isFirstName("Bob"))
	{
		cout << "Yes the first name is Bob" << endl;
	}
	else if (personOne.isLastName("Otto"))
	{
		cout << "Yes the last name is Otto" << endl;
	}

	cin.ignore();
}
