#include "linkedList.h"

linkedList::linkedList() {	
	head = NULL;
	tail = NULL;
	size = 0;
}

void linkedList::add(string text) {
	lnode *tmp = new lnode;
	tmp->text = text;
	tmp->next = NULL;

	if (head == NULL)
	{
		head = tmp;
		tail = tmp;
	}
	else
	{
		tail->next = tmp;
		tail = tail->next;
	}
	size++;
}

string linkedList::remove(int n)
{
	string text = "";
	lnode *temp = head;
	if (n == 1)
	{
		head = temp->next;   
		text = temp->text;
		delete temp;  
		size--;
		return text;
	}

	for (int i = 0; temp != NULL && i<n-2; i++)
		temp = temp->next;

	if (temp == NULL || temp->next == NULL)
		return NULL;

	lnode *next = temp->next->next;
	text = temp->next->text;
	delete temp->next;  
	if(n == size)
		tail = temp;
	size--;
	temp->next = next;  
	
	return text;
}

string linkedList::move(int n, int m)
{
	string nText = remove(n);
	insert(m, nText);
	return nText;
}

void linkedList::insert(int n, string text)
{
	lnode **current = &head;
	while (n--) {
		if (n == 0) {
			lnode *nNode = new lnode();
			nNode->text = text;
			nNode->next = *current;
			*current = nNode;
		}
		else
			current = &(*current)->next;
	}
	size++;
}



string linkedList::replace(int n, string text)
{
	lnode *current = head;
	for (int i = 0; i < n - 1; i++)
		current = current->next;
	string txtTemp = current->text;
	current->text = text;
	return txtTemp;
}

void linkedList::print(int p, int lc) const
{
	lnode* current = head;

	for (int i = 0; i < p * 10; i++) {
		current = current->next;
	}
	for (int i = 0; i < lc; i++)
	{	
		cout <<p*10+i+1<<"-)"<<current->text.c_str() << endl;
		current = current->next;
	}
	
}


void linkedList::initializeList()
{
	if (head == NULL)
		return;
	lnode *temp = head->next;
	while (temp != NULL)
	{		
		head->next = temp->next;
		delete temp;
		temp = head->next;
	}
	delete head;
	head = NULL;
	size = 0;
}

