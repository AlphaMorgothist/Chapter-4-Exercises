// Chapter4Exercises.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <Windows.h>
#include <algorithm>
using namespace std;


void vecAr() {
	vector<string> sVect;
	vector<string>::iterator it;
	string input;
	string remover;
	bool del = false;

	cout << "\n\tWelcome to 'My Favourite Games!' list\n" << endl;
	cout << "Please enter a game to be listed\n" << endl;
	while (true) {
		cout << "List of my favourite games:";
		
		for (it = sVect.begin(); it < sVect.end(); it++) {
			if (*it == "remove") {
				*it = "";
			}
			cout << *it << endl;
		}
		cout << "\n\n\nEnter a game name to add to the list.\nType 'quit' to quit.\nType 'remove' to remove from list" << endl;
		cout << "\nResponse: ";
		getline(cin, input);
		
		if (input == "remove") {
			del = true;
			input = "";
		}
		else if (input != "remove") {
			sVect.push_back(input);
		}
		sort(sVect.begin(), sVect.end());
		
		if (input == "quit") {
			system("CLS");
			break;
		}
		else if (del == true) {
			cout << "Name of game to remove: ";
			getline(cin, remover);
			sVect.erase(remove(sVect.begin(), sVect.end(), remover), sVect.end());
			del = false;
		}
		system("CLS");
	}
	system("pause");
}

int main()
{
	int sel = 0;
	while (sel != 2) {
		cout << "\n\t\t\tChapter 4 Exercises\n" << endl;
		cout << "1: [Exercises 4.1] Favourite Game Vector" << endl;
		cout << "2: Quit" << endl;
		cout << "\n\nSelection: ";
		cin >> sel;
		system("CLS");
		switch (sel) {
		case 1: {
			vecAr();
			break;
		}
		}
	}
    return 0;
}

