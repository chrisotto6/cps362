// Main.cpp contains the main project logic for the assignment

using namespace std;

#include "info.h"
#include "mainUI.h"
#include <iostream>

void main()
{
	// Student info
	info myInfo;
	myInfo.identity("Week 7 Assignment", __DATE__);

	// UI Class
	mainUI exec;
	exec.mainMethod();

	cin.ignore();
	system("PAUSE");
}