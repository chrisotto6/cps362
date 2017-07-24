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
	cout << "\nThis application will validate a word is a palindrome." << endl;

	// Create the two objects to handle the user input and a char str for input
	linkedQueueType<char> queue;
	linkedStackType<char> stack;
	char str[150];

	// Get input from the user to be used as comparison
	cout << "\nEnter in your word or phrase...\n" << endl;
	cin.getline(str, 150, '\n');

	// Insert the elements into the stack and into the queue
	int i = 0;
	char ch;

	do {
		ch = str[i];

		// Convert to lower case
		if (ch > 64 && ch < 91)
				ch += 32;

		queue.addQueue(ch);
		stack.push(ch);
		i++;
	} while (str[i] != '\0');

	// Compare the elements of the queue and the stack
	while (!stack.isEmptyStack()) {
		if (stack.top() != queue.front())
			break;

		stack.pop();
		queue.deleteQueue();
	}

	if (stack.isEmptyStack() && queue.isEmptyQueue()) {
		cout << "\n\nThat word or phrase is a palindrom";
	}
	else {
		cout << "\n\nThat word or phrase is not a palindrom";
	}
}