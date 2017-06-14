//Programmer:  Chris Otto
//Purpose   :  Class definitions for the Point Type class

#ifndef POINTTYPE_H
#define POINTTYPE_H

using namespace std;

class pointType
{
protected:
	// Member function prototypes
	float xCoordinate;
	float yCoordinate;
public:
	// Default constructor
	pointType();

	// Constructor to store away the coordinates
	pointType(float xCoord, float yCoord);

	// Displays the saved point
	void displayPoint();

	// Set the coordinates
	void setCoordinates(float xCoord, float yCoord);

	// Print out the saved point
	void printCoordinates();

	// Retrieve the x coordinate
	float getXCoordinate() const;

	// Retrieve the y coordinate
	float getYCoordinate() const;
};
#endif