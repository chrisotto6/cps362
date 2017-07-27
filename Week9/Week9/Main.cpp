// Main.cpp contains the calls to the other classes for application execution

using namespace std;

#include "info.h"
#include "mainUI.h"
#include <iostream>

void main() {
	// Student info
	info myInfo;
	myInfo.identity("Week 9 Assignment - Calculator", __DATE__);

	// UI Class
	mainUI exec;
	exec.mainMethod();

	cin.ignore();
	system("PAUSE");
}