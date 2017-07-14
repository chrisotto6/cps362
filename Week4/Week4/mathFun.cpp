#include "mathFun.h"

// Default Constructor
mathFun::mathFun()
{
}

mathFun::~mathFun()
{
}

// Sets the value within the vector
void mathFun::setIntValue(int num)
{
	math.push_back(num);
}

// Gets the value for a given location
int mathFun::getIntValue(int loc) const
{
	return math[loc];
}

// Goes through the vector and returns the smallest stored value
int mathFun::getSmallest() const
{
	int small = math[0];
	for (unsigned i = 0; i < math.size(); i++)
	{
		if (math[i] < small)
			small = math[i];
	}
	return small;
}

// Goes through the vector and returns the largest stored value
int mathFun::getLargest() const
{
	int large = math[0];
	for (unsigned i = 0; i < math.size(); i++)
	{
		if (math[i] > large)
			large = math[i];
	}
	return large;
}

// Goes through the vector and returns the average of all stored values
int mathFun::getAverage() const
{
	double sum, avg;
	for (unsigned i = 0; i < math.size(); i++)
	{
		sum += math[i];
	}
	avg = sum / math.size();
	return avg;
}

// Method to build the vector through the UI functions and implementing the 
// mathFun class
void mathFun::buildVector()
{
	char choice = 'y';
	int num;

	do
	{
		cout << "Enter a real number: ";
		cin >> num;
		setIntValue(num);

		cout << "\nDo you wish to add another number? (y/n)";
		cin >> choice;
	} while (choice == 'y');
}

// Method to display the smallest, largest and average of the vector based on
// user input
void mathFun::displayVector()
{
	char choice;

	cout << "\nDo you wish to see the smallest number? (y/n)";
	cin >> choice;
	if (choice == 'y')
		cout << "\nSmallest number: " << getSmallest() << endl;

	cout << "\nDo you wish to see the largest number? (y/n)";
	cin >> choice;
	if (choice == 'y')
		cout << "\nLargest number: " << getLargest() << endl;

	cout << "\nDo you wish to see the average of the numbers? (y/n)";
	cin >> choice;
	if (choice == 'y')
		cout << "\nAverage number: " << getAverage() << endl;
}