//Programmer:  Chris Otto
//Purpose   :  Class implementations for the Circle Type class

#include "circleType.h"
#include <iostream> 
#include <iomanip>

using namespace std;

// Default constructor
circleType::circleType()
{
	radius = 0;
}

// Set the radius
void circleType::setRadius(float r)
{
	radius = r;
}

// Print radius
void circleType::printRadius()
{
	cout << "Radius: " << radius << endl;
}

// Calculate the area based on the radius
float circleType::calcArea() const
{
	return (3.14 * radius * radius);
}

// Print the area
void circleType::printArea()
{
	cout << "Area: " << calcArea() << endl;
}

// Calculate the circumference based on the radius
float circleType::calcCircum() const
{
	return (2 * 3.14 * radius);
}

// Print the circumference
void circleType::printCircum()
{
	cout << "Circumference: " << calcCircum() << endl;
}

// Print all the items from the circle type and point class 
void circleType::print()
{
	pointType::printCoordinates();
	printRadius();
	printArea();
	printCircum();
}