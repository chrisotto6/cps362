//************************************************************
// Author: Chris Otto
// Week: 1
// class personType
// This class specifies the members to implement a name.
//************************************************************

#include <string>
#ifndef PERSONTYPE_H
#define PERSONTYPE_H

using namespace std;

class personType
{
public:
	void print() const;
	//Function to output the first name and last name
	//in the form firstName lastName.

	void setName(string first, string middle, string last);
	//Function to set firstName, middleName and lastName according to the
	//parameters.
	//Postcondition: firstName = first; middleName = middle; lastName = last

	void setFirstName(string first);
	//Function to set the firstName
	//Postcondition: firstName = first;

	void setMiddleName(string middle);
	//Function to set the middleName
	//Postcondition: middleName = middle;

	void setLastName(string last);
	//Function to set the lastName
	//Postcondition: lastName = last;

	string getFirstName() const;
	//Function to return the first name.
	//Postcondition: The value of firstName is returned.

	string getMiddleName() const;
	//Function to return the middle name.
	//Postcondition: The value of middleName is returned.

	string getLastName() const;
	//Function to return the last name.
	//Postcondition: The value of lastName is returned.

	bool isFirstName(string name) const;
	//Function to check if the name is the first name

	bool isLastName(string name) const;
	//Function to check if the name is the first name

	personType();
	//Default constructor
	//Sets firstName and lastName to null strings.
	//Postcondition: firstName = ""; lastName = "";

	personType(string first,string middle, string last);
	//Constructor with parameters.
	//Sets firstName and lastName according to the parameters.
	//Postcondition: firstName = first; lastName = last;  

private:
	string firstName; //variable to store the first name
	string lastName;  //variable to store the last name
	string middleName; // variable to store the iddle name
};
#endif