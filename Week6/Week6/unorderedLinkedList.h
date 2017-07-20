// Extending the LinkedList.h file to create the instances of deleteAllOccurances
// and deleteSmallest

#ifndef H_UnorderedLinkedList
#define H_UnorderedLinkedList

#include "linkedList.h"

using namespace std;

template <class Type>
class unorderedLinkedList : public linkedListType<Type>
{
public:
	bool search(const Type& searchItem) const;
	void insertFirst(const Type& newItem);
	void insertLast(const Type& newItem);
	void deleteNode(const Type& deleteItem);
	void deleteSmallest(void);
	void deleteAllOccurances(const Type& value);
};


template <class Type>
bool unorderedLinkedList<Type>::
search(const Type& searchItem) const
{
	nodeType<Type> *current; //pointer to traverse the list
	bool found = false;

	current = first; //set current to point to the first 
					 //node in the list

	while (current != NULL && !found)    //search the list
		if (current->info == searchItem) //searchItem is found
			found = true;
		else
			current = current->link; //make current point to
									 //the next node
	return found;
}//end search

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
	nodeType<Type> *newNode; //pointer to create the new node

	newNode = new nodeType<Type>; //create the new node

	newNode->info = newItem;    //store the new item in the node
	newNode->link = first;      //insert newNode before first
	first = newNode;            //make first point to the
								//actual first node
	count++;                    //increment count

	if (last == NULL)   //if the list was empty, newNode is also 
						//the last node in the list
		last = newNode;
}//end insertFirst

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
	nodeType<Type> *newNode; //pointer to create the new node

	newNode = new nodeType<Type>; //create the new node

	newNode->info = newItem;  //store the new item in the node
	newNode->link = NULL;     //set the link field of newNode
							  //to NULL

	if (first == NULL)  //if the list is empty, newNode is 
						//both the first and last node
	{
		first = newNode;
		last = newNode;
		count++;        //increment count
	}
	else    //the list is not empty, insert newNode after last
	{
		last->link = newNode; //insert newNode after last
		last = newNode; //make last point to the actual 
						//last node in the list
		count++;        //increment count
	}
}//end insertLast


template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
	nodeType<Type> *current; //pointer to traverse the list
	nodeType<Type> *trailCurrent; //pointer just before current
	bool found;

	if (first == NULL)    //Case 1; the list is empty. 
		cout << "Cannot delete from an empty list."
		<< endl;
	else
	{
		if (first->info == deleteItem) //Case 2 
		{
			current = first;
			first = first->link;
			count--;
			if (first == NULL)    //the list has only one node
				last = NULL;
			delete current;
		}
		else //search the list for the node with the given info
		{
			found = false;
			trailCurrent = first;  //set trailCurrent to point
								   //to the first node
			current = first->link; //set current to point to 
								   //the second node

			while (current != NULL && !found)
			{
				if (current->info != deleteItem)
				{
					trailCurrent = current;
					current = current->link;
				}
				else
					found = true;
			}//end while

			if (found) //Case 3; if found, delete the node
			{
				trailCurrent->link = current->link;
				count--;

				if (last == current)   //node to be deleted 
									   //was the last node
					last = trailCurrent; //update the value 
										 //of last
				delete current;  //delete the node from the list
			}
			else
				cout << "The item to be deleted is not in "
				<< "the list." << endl;
		}//end else
	}//end else
}//end deleteNode

template<class Type>
void unorderedLinkedList<Type>::deleteSmallest(void)
{
	nodeType<Type> *current;
	nodeType<Type> *trail;
	nodeType<Type> *smallest;
	nodeType<Type> *smallestTrail;

	if (first == NULL)
		cout << "Cannot delete from a list without anything in it." << endl;
	else
	{
		if (first->link == NULL)
		{
			first = NULL;
			delete last;
			last = NULL;
		}
		else
		{
			smallest = first;
			smallestTrail = first;
			trail = first->link;
			current = first->link;

			while (current != NULL)
			{
				if (smallest->info > current->info)
				{
					smallestTrail = trail;
					smallest = current;
				}
				trail = current;
				current = current->link;
			}

			if (smallest == first)
				first = first->link;
			else if (smallest != first)
			{
				smallestTrail->link = smallest->link;

				if (smallest == last)
					last = smallestTrail;
			}

			delete smallest;
			count--;
		}
	}
}

template<class Type>
void unorderedLinkedList<Type>::deleteAllOccurances(const Type& value)
{
	nodeType<Type> *current = first;
	nodeType<Type> *trail = first;

	while (current != NULL)
	{
		if (current->info == value)
		{
			if (current == first)
			{
				first = current->link;
				delete current;
				count--;
				current = first;
			}
			else
			{
				trail->link = current->link;
				delete current;
				count--;
				current = trail->link;
			}
		}
		else
		{
			trail = current;
			current = current->link;
		}
	}
	return;
}
#endif
