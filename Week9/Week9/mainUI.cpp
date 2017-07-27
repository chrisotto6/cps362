// Handles the UI interactions between the main file and the other class files
// Chris Otto

#include "mainUI.h"
#include "calculator.h"

using namespace std;

mainUI::mainUI()
{
}

mainUI::~mainUI()
{
}

void mainUI::mainMethod()
{
	calculator calc;
	calc.calculate();
}