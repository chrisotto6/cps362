//************************************************************
// Author: Chris Otto
// Week: 1
// Implemenation file personType
//************************************************************

#include <iostream>
#include <string>
#include "personType.h"

using namespace std;

void personType::print() const
{
	cout << firstName << " " << middleName << " " << lastName << endl;
}

void personType::setName(string first,string middle, string last)
{
	setFirstName(first);
	setMiddleName(middle);
	setLastName(last);
}

void personType::setFirstName(string first)
{
	firstName = first;
}

void personType::setMiddleName(string middle)
{
	middleName = middle;
}

void personType::setLastName(string last)
{
	lastName = last;
}

string personType::getFirstName() const
{
	return firstName;
}

string personType::getMiddleName() const
{
	return middleName;
}

string personType::getLastName() const
{
	return lastName;
}

bool personType::isFirstName(string first) const
{
	return first == firstName;
}

bool personType::isLastName(string last) const
{
	return last == lastName;
}

//Default constructor
personType::personType()
{
	setName("", "", "");
}

//Constructor with parameters
personType::personType(string first,string middle, string last)
{
	setName(first, middle, last);
}

