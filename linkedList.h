
#ifndef _LINKEDLIST_
#define _LINKEDLIST_
#include "structures.h"
using namespace std;

class linkedList
{
private:
	lnode *head, *tail;
	int size;
public:
	linkedList();
	void add(string text);
	void print(int p, int lc) const;
	void initializeList();
	void insert(int n, string text);

	int getSize() const {
        return size;
        
    };

	string remove(int n);
	string move(int n, int m);
	string replace(int n,string text);

	lnode *getHead() const {
        return head;
        
    }
	
};
#endif
