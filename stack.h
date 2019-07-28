#ifndef _STACK_
#define _STACK_
#include "structures.h"
using namespace std;

class stack
{
public:
	stack();
	bool isEmptystack() const;
	void initializeStack(); 
	void push(command* command);
	command* top() const;
	void pop();
private:
	snode *stackTop; 
};
#endif

