#ifndef _TEXTEDITOR_
#define _TEXTEDITOR_

#include "linkedList.h"
#include "structures.h"
#include "stack.h"
#include <fstream>
//#include <string>


class textEditor
{
private:
	linkedList list;
	stack opStack;
	int page;

public:	
	textEditor();
	~textEditor();
	bool openFile(string fileName);
	bool saveFile(string fileName) const;
	void insert(int n, string text);
	bool deleteLine(int n);
	bool move(int n, int m);
	bool replace(int n, string text);
	bool next();
	bool prev();
	bool undo();
	command* createNewCommand(int com, int n = 0, int m = 0, int diff = 0, string text = "") const;
	void clearAll();
};
#endif
