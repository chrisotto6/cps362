//Programmer:  Chris Otto
//Purpose   :  Include this header file in all future assignments.  Will display programmers and assignment info.

#ifndef INFO_H
#define INFO_H
#include <string>
using namespace std;

class info
{
private:
	string programmer;
	string instructor;
public:
	info();
	void identity(string assignment, string compileDate);
	~info();
};
#endif