//Header File: linkedStack.h

#ifndef H_StackType 
#define H_StackType

#include <iostream>
#include <cassert>

#include "stackADT.h"


using namespace std;

//Definition of the node
template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type> *link;
};

template <class Type>
class linkedStackType : public stackADT<Type>
{
public:
	const linkedStackType<Type>& operator=
		(const linkedStackType<Type>&);
	bool isEmptyStack() const;
	bool isFullStack() const;
	void initializeStack();
	void push(const Type& newItem);
	Type top() const;
	void pop();
	linkedStackType();
	linkedStackType(const linkedStackType<Type>& otherStack);
	~linkedStackType();
private:
	nodeType<Type> *stackTop;

	void copyStack(const linkedStackType<Type>& otherStack);
};

//Default constructor
template <class Type>
linkedStackType<Type>::linkedStackType()
{
	stackTop = NULL;
}

template <class Type>
bool linkedStackType<Type>::isEmptyStack() const
{
	return(stackTop == NULL);
} //end isEmptyStack

template <class Type>
bool linkedStackType<Type>::isFullStack() const
{
	return false;
} //end isFullStack

template <class Type>
void linkedStackType<Type>::initializeStack()
{
	nodeType<Type> *temp; //pointer to delete the node

	while (stackTop != NULL)    //while there are elements in 
								//the stack
	{
		temp = stackTop;    //set temp to point to the 
							//current node
		stackTop = stackTop->link;  //advance stackTop to the
									//next node
		delete temp;    //deallocate memory occupied by temp
	}
} //end initializeStack

template <class Type>
void linkedStackType<Type>::push(const Type& newElement)
{
	nodeType<Type> *newNode;  //pointer to create the new node

	newNode = new nodeType<Type>; //create the node

	newNode->info = newElement; //store newElement in the node
	newNode->link = stackTop; //insert newNode before stackTop
	stackTop = newNode;       //set stackTop to point to the 
							  //top node
} //end push

template <class Type>
Type linkedStackType<Type>::top() const
{
	assert(stackTop != NULL); //if stack is empty,
							  //terminate the program
	return stackTop->info;    //return the top element 
}//end top

template <class Type>
void linkedStackType<Type>::pop()
{
	nodeType<Type> *temp;   //pointer to deallocate memory

	if (stackTop != NULL)
	{
		temp = stackTop;  //set temp to point to the top node

		stackTop = stackTop->link;  //advance stackTop to the 
									//next node
		delete temp;    //delete the top node
	}
	else
		cout << "Cannot remove from an empty stack." << endl;
}//end pop

template <class Type>
void linkedStackType<Type>::copyStack
(const linkedStackType<Type>& otherStack)
{
	nodeType<Type> *newNode, *current, *last;

	if (stackTop != NULL) //if stack is nonempty, make it empty
		initializeStack();

	if (otherStack.stackTop == NULL)
		stackTop = NULL;
	else
	{
		current = otherStack.stackTop;  //set current to point
										//to the stack to be copied

										//copy the stackTop element of the stack 
		stackTop = new nodeType<Type>;  //create the node

		stackTop->info = current->info; //copy the info
		stackTop->link = NULL;  //set the link field of the
								//node to NULL
		last = stackTop;        //set last to point to the node
		current = current->link;    //set current to point to
									//the next node

									//copy the remaining stack
		while (current != NULL)
		{
			newNode = new nodeType<Type>;
			newNode->info = current->info;
			newNode->link = NULL;
			last->link = newNode;
			last = newNode;
			current = current->link;
		}//end while
	}//end else
} //end copyStack

  //copy constructor
template <class Type>
linkedStackType<Type>::linkedStackType(
	const linkedStackType<Type>& otherStack)
{
	stackTop = NULL;
	copyStack(otherStack);
}//end copy constructor

 //destructor
template <class Type>
linkedStackType<Type>::~linkedStackType()
{
	initializeStack();
}//end destructor

 //overloading the assignment operator
template <class Type>
const linkedStackType<Type>& linkedStackType<Type>::operator=
(const linkedStackType<Type>& otherStack)
{
	if (this != &otherStack) //avoid self-copy
		copyStack(otherStack);

	return *this;
}//end operator=

#endif