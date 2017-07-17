#include "occurances.h"

template<class Type>
void occurances<Type>::deleteOneOccurance(int k)
{
	NodeType<Type> *temp;
	NodeType<Type> *prev = NULL;
	NodeType<Type> *next;
	bool found = false;

	temp = head;

	do
	{
		next = temp->next;

		if (temp->item != k) {
			prev = temp;
			continue;
		}

		if (prev != NULL)
		{
			prev->next = next;
			found = true;
		}
		else
		{
			head = next;
		}

		delete temp;

	} while ((bool found == false && temp != NULL) || temp != NULL);

}

template<class Type>
void occurances<Type>::deleteAllOccurances(int k)
{
	NodeType<Type> *temp;
	NodeType<Type> *prev = NULL;
	NodeType<Type> *next;

	for (temp = head; temp != NULL; temp = next)
	{
		next = temp->next;
		
		if (temp->item != k) {
			prev = temp;
			continue;
		}

		if (prev != NULL)
			prev->next = next;
		else
			head = next;

		delete temp;
	}
}
