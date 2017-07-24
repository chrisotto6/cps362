// Main.cpp contains the calls to the other classes for application execution

using namespace std;

#include "info.h"
#include "mainUI.h"
#include <iostream>

void main() {
	// Student Info
	info myInfo;
	myInfo.identity("Week 10 - Extra Credit", __DATE__);

	// UI class 
	mainUI exec;
	exec.mainMethod();

	cin.ignore();
	system("PAUSE");
}