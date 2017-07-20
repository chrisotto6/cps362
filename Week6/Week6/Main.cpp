// Main.cpp contains the main project logic for the assignment

#include "info.h"
#include "mainUI.h"
#include <iostream>

using namespace std;

void main()
{
	// Student info
	info myInfo;
	myInfo.identity("Week 6 Assignment", __DATE__);

	// Call to the UI Class to run the app
	mainUI app;
	app.mainMethod();

	cin.ignore();
	system("PAUSE");
}