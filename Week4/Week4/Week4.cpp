// Week4.cpp : main project file.

#include "info.h"
#include "mathFun.h"
#include <iostream> 

using namespace std;

int main()
{
	// Student info
	info myInfo;
	myInfo.identity("Week 4", __DATE__);

	mathFun math;

	math.buildVector();
	math.displayVector();

	cin.ignore();
	system("PAUSE");
}