//Programmer:  Chris Otto
//Purpose   :  Class implementations for the Point Type class

#include "pointType.h"
#include <iostream> 
#include <iomanip>

using namespace std;

// Default constructor 
pointType::pointType()
{
	xCoordinate = 0.0;
	yCoordinate = 0.0;
}

// Constructor used to store a coordinate pair
pointType::pointType(float xCoord, float yCoord)
{
	xCoordinate = xCoord;
	yCoordinate = yCoord;
}

// Displays the point
void pointType::displayPoint()
{
	cout << "\n(" << xCoordinate << ", " << yCoordinate << ")\n" << endl;
}

// Sets the coordinates 
void pointType::setCoordinates(float xCoord, float yCoord)
{
	xCoordinate = xCoord;
	yCoordinate = yCoord;
}

// Prints the coordinates
void pointType::printCoordinates()
{
	cout << "\nThe point is (" << xCoordinate << ", " << yCoordinate << ")" << endl;
}

// Returns the xCoordinate 
float pointType::getXCoordinate() const
{
	return xCoordinate;
}

// Returns the yCoordinate
float pointType::getYCoordinate() const
{
	return yCoordinate;
}