//Programmer:  Chris Otto
//Purpose   :  Class definitions for the Circle Type class

#include "pointType.h"
#ifndef CIRCLETYPE_H
#define CIRCLETYPE_H

using namespace std;

class circleType:public pointType
{
private:
	float radius;
public:
	// Default constructor
	circleType();

	// Function to set the function
	void setRadius(float r);

	// Print the radius
	void printRadius();

	// Calculate the area
	float calcArea() const;

	// Print the area
	void printArea();

	// Calculate the circumference
	float calcCircum() const;

	// Print the circumference
	void printCircum();

	// Print all the things from this class and the point class
	void print();
};
#endif