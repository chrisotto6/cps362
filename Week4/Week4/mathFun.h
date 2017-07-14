//Programmer:  Chris Otto
//Purpose   :  This class handles all the logical functions for the vector math fun

#ifndef MATHFUN_H
#define MATHFUN_H

#include <vector>
#include <iostream> 

using namespace std;

class mathFun
{
private:
	vector<int> math;
public:
	mathFun();
	~mathFun();
	void setIntValue(int num);
	int getIntValue(int loc) const;
	int getSmallest() const;
	int getLargest() const;
	int getAverage() const;
	void buildVector();
	void displayVector();
};
#endif