#include <iostream>
//#include <sstream>

#include "textEditor.h"

using namespace std;

void printCommands();

int main() {
    printCommands();
    textEditor editor;
    do {
        string command = "", par1 = "", par2 = "";
        cin >> command;
        cout<<endl;
        if (command == "open")
        {
            cin >> par1;
            cout << endl;
            if (!editor.openFile(par1)) {
                cout << "Error! file couldn't open" << endl;
            }
        }
        else if (command == "save") {
            cin >> par1;
            cout << endl;
            if (!editor.saveFile(par1)) {
                cout << "Error! file couldn't write" << endl;
            }
            else{
                cout<<"Successfuly saved"<<endl;
            }
        }
        else if (command == "insert")
        {
            cin >> par1;
            getline(cin, par2);
            cout << endl;
            editor.insert(stoi(par1), par2.substr(1, par2.length()));
        }
        else if (command == "delete")
        {
            cin >> par1;
            if(!editor.deleteLine(stoi(par1)))
            {
                cout << "Error! n is bigger than list length" << endl;
            }
        }
        else if (command == "move")
        {
            cin >> par1 >> par2;
            cout << endl;
            if (!editor.move(stoi(par1), stoi(par2))) {
                cout << "Error! n or m are bigger than list length" << endl;
            }
        }
        else if (command == "replace")
        {
            cin >> par1;
            getline(cin, par2);
            cout << endl;
            if (!editor.replace(stoi(par1), par2.substr(1, par2.length()))) {
				cout << "Error! n is bigger than list length" << endl;
			}
		}
		else if (command == "next")
		{		
			if (!editor.next()) {
				cout << endl  <<"This is the last page of the contents. You can't go to the next page!" << endl;
			}
		}
		else if (command == "prev")
		{
			if (!editor.prev())
			{
				cout << endl << "This is the first page of the contents. You can't go to the previous page!" << endl;			
			}
		}
		else if (command == "undo")
		{
			if (!editor.undo()) {
				cout << "There isn't reverts action in the stack." << endl;
			}
			cout << endl;
		}
		else if (command == "exit")
		{
			break;
		}
		else {
			cout << endl << "Unkown command!" << " You can only use following commands." << endl << endl;
			printCommands();
		}
	} while (true);
	return 0;
}

void printCommands() {
    cout << "- Commands:" << endl << endl;
    cout << "open filename : read the contents."<< endl;
    cout << "save filename : write the contents." << endl;
    cout << "insert n text : insert a new line in the text at the line position n." << endl;
    cout << "delete n : delete the line at position n." << endl;
    cout << "move n m : move the line at position n to position m." << endl;
    cout << "replace n text : replace the line at position n to the text." << endl;
    cout << "next : display the next content page." << endl;
    cout << "prev : display the previous content page." << endl;
    cout << "undo : reverts the last taken action." << endl;
}
