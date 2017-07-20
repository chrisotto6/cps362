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
	// Variables for execution
	linkedStackType<int> decimal;
	linkedStackType<int> binary;
	int input;

	// Create the stack
	decimal.initializeStack();
	binary.initializeStack();

	// Ping the user for their information
	cout << "What binary number would you like to convert?" << endl;
	cin >> input;

	int weight = -1;
	while (input > 0) {
		decimal.push(input % 10);
		input = input / 10;
		weight++;
	}

	int dec = 0;
	int bit;
	while (!decimal.isEmptyStack()) {
		bit = decimal.top();
		decimal.pop();
		dec = dec + bit * (int)pow(2, weight);
		weight--;
	}

	// Return the decimal to the user
	cout << "\nThe decimal is: " << dec << "." << endl;

	// Ping the user for their information
	cout << "What decimal number would you like to convert?" << endl;
	cin >> input;

	int rem;
	while (input > 0) {
		rem = input % 2;
		input /= 2;
		binary.push(rem);
	}

	// Return the binary to the user
	cout << "\nThe binary is: ";

	while (!binary.isEmptyStack()) {
		cout << binary.top();
		binary.pop();
	}
	cout << endl;

}