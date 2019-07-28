#ifndef _STRUCTS_
#define _STRUCTS_

#include <iostream>
#include <string>

using namespace std;

struct lnode
{
	string text;
	lnode *next;
};

/*
com == commands | 0 = ins , 1 = del, 2 = mov, 3 = replace
n = position n
m = position m
diff = eklenen satırlar için önceki listeye göre farkı.
*/
struct command {
	int com, n, m, diff;
	string text;
};

struct snode
{
	struct command* command;
	snode* link;
};
#endif

