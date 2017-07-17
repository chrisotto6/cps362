#include "linkedList.h"

template <class Type>
class occurances :public linkedListType<Type>

{
public:
	void deleteOneOccurance(int k);
	void deleteAllOccurances(int k);
};
