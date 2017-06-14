// Week1.cpp : main project file.

#include "info.h"
#include "circleType.h"

#include <iostream>
using namespace std;

int main()
{
	// Student info
	info myInfo;
	myInfo.identity("Week 2", __DATE__);

	// In memory varaibles for execution
	float x, y, r;

	// Create a new coordinate object 
	cout << "\nEnter an x coordinate: ";
	cin >> x;
	cout << "\nEnter a y coordinate: ";
	cin >> y;

	// Create new coordinate through the constructor
	pointType point = pointType(x, y);

	// Display the coordinate
	point.displayPoint();

	// Create a new coordinate through the function
	cout << "\nEnter an x coordinate: ";
	cin >> x;
	cout << "\nEnter a y coordinate: ";
	cin >> y;

	// Assign the taken in variables to the object
	pointType newPoint;
	newPoint.setCoordinates(x, y);

	// Print the coordinates
	newPoint.printCoordinates();

	// Display the coordinates through the getCoordinates functions
	cout << "The x-coordinate is: " << newPoint.getXCoordinate() << endl;
	cout << "The y-coordinate is: " << newPoint.getYCoordinate() << endl;

	// Create a new point coordinate and radius
	cout << "\nEnter an x coordinate: ";
	cin >> x;
	cout << "\nEnter a y coordinate: ";
	cin >> y;
	cout << "\nEnter a radius: ";
	cin >> r;

	// Assign the inputs to create new coordinates and radius
	circleType circle;
	circle.setCoordinates(x, y);
	circle.setRadius(r);

	// Print out the new coordinates, radius, area and circumference
	circle.print();

	cin.ignore();
	system("PAUSE");
}
