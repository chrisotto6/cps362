//Programmer:  Chris Otto
//Purpose   :  Include this header file in all future assignments.  Will display programmers and assignment info.
#include "info.h"
#include <iostream> 
#include <iomanip>
using namespace std;

info::info()
{
	programmer = "Chris Otto";  //should be set to your name.
	instructor = "Judy Ligocki";
}

info::~info()
{
}

void info::identity(string assignment, string currentDate)
{
	cout << setw(66) << setfill('*');
	cout << "\n";
	cout << "Programmer   : " << programmer << endl;
	cout << "Assignment   : " << assignment << endl;
	cout << "Instructor   : " << instructor << endl;
	cout << "Current Date : " << currentDate << endl;
	cout << "CompileDate  : " << __DATE__ << endl; //will pull system date at time this file is compiled.
	cout << setw(66) << setfill('*');
	cout << "\n";
}