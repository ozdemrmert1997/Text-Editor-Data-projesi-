#include "stack.h"

stack::stack() {
	stackTop = NULL;
}


void stack::initializeStack() {

	snode *temp = stackTop;

	while (temp != NULL)
	{
		stackTop = (snode*)stackTop->link;
		delete temp;
		temp = stackTop;
	}
}

bool stack::isEmptystack() const {
	return stackTop == NULL;
}

void stack::push(command* command) {

	snode *inode = new snode;
	
	inode->link = stackTop;
	inode->command = command;
	stackTop = inode;

}

void stack::pop() {

	snode *temp = stackTop;

	if (!isEmptystack())
	{
		stackTop = stackTop->link;
		delete temp;
	}
	else
	{
		cout << "Cannot pop, empty stack." << endl;
	}
}

command* stack::top() const {
	if (!isEmptystack())
		return stackTop->command;
	else
		return NULL;
}
