#include "textEditor.h"

textEditor::textEditor()
{
	page = 0;
}

textEditor::~textEditor()
{
	clearAll();
}

bool textEditor::openFile(string fileName)
{
	ifstream ifile;
	ifile.open(fileName);

	if (!ifile.is_open())
	{
		return false;
	}

	clearAll();

	string line = "";
	while (getline(ifile, line)) {
		this->list.add(line);
	}
	next(); // buraya next eklemen kafi yazdýrmasý için
	return true;
}

bool textEditor::saveFile(string fileName) const
{
	ofstream ofile;
	ofile.open(fileName, ios::out);
	if (!ofile.is_open())
	{
		return false;
	}
	lnode *current = list.getHead();
	int size = list.getSize();
	for (int i = 0; i < size; i++)
	{
		ofile << current->text << endl;
		current = current->next;
	}
	ofile.close();
	return true;
}

void textEditor::insert(int n, string text)
{
	int size = list.getSize();

	if (size < n - 1)
	{
		for (int i = size; i < n - 1; i++) {
			list.add("\n");
		}
		list.add(text);
	}
	else
	{
		list.insert(n, text);
	}
	opStack.push(createNewCommand(0, n, 0, n - size));
	page--;
	next();
}

bool textEditor::deleteLine(int n)
{
	if (list.getSize() < n)
		return false;
	else {
		opStack.push(createNewCommand(1, n, 0, 0, list.remove(n)));
	}
	page--;
	next();
	return true;
}

bool textEditor::move(int n, int m)
{
	int size = list.getSize();
	if (size < n || size < m)
		return false;
	else {
		opStack.push(createNewCommand(2, n, m, 0, list.move(n, m)));
	}
	page--;
	next();
	return true;
}

bool textEditor::replace(int n, string text)
{
	if (list.getSize() < n)
		return false;
	else {
		opStack.push(createNewCommand(3, n, 0, 0, list.replace(n, text)));
	}
	page--;
	next();
	return true;
}

bool textEditor::next()
{
	int size = list.getSize();
	if (page != 0 && double(size) / 10 - page <= 0.0f)
	{
		list.print((page-1), size % 10 == 0 ? 10 : size % 10);
		cout << endl << endl << "--- Page " << page << " ---" << endl << endl;
		return false;
	}
	if (size < (page + 1) * 10) {		
		list.print((page), size % 10);
		page++;
	}
	else {		
		list.print((page), 10);
		page++;
	}
	cout << endl << endl << "--- Page " << page << " ---" << endl << endl;
	return true;
}

bool textEditor::prev()
{
	if (page <= 1) {
		page = 0;
		next();
		return false;
	}
	int size = list.getSize();
	if (size < (page - 1) * 10) {		
		list.print((page), size % 10);
		page--;
	}
	else {	
		list.print((page-2), 10);
		page--;
	}
	cout << endl << endl << "--- Page " << page << " ---" << endl << endl;

	return true;
}

bool textEditor::undo()
{
	if (opStack.isEmptystack())
		return false;
	else {
		command *c = opStack.top();
		opStack.pop();
		switch (c->com) {
		case 0: //  ins
		{
			if (c->diff > 0) {
				int size = list.getSize();
				for (int i = 0; i < c->diff; i++)
					list.remove(size - c->diff +1);
			}
			else {
				list.remove(c->n);
			}
		}
		break;
		case 1: // del
		{
			list.insert(c->n, c->text);
		}
		break;
		case 2: // mov
		{
			list.remove(c->m);
			list.insert(c->n, c->text);		
		}
		break;
		case 3: // replace
		{
			list.replace(c->n, c->text);
		}
		break;
		}
	}
	page--;
	next();
	return true;
}

command * textEditor::createNewCommand(int com, int n, int m, int diff, string text) const
{
	command *c = new command();
	c->com = com;
	c->n = n;
	c->m = m;
	c->diff = diff;
	c->text = text;
	return c;
}

void textEditor::clearAll() {
	opStack.initializeStack();
	list.initializeList();
	page = 0;
}