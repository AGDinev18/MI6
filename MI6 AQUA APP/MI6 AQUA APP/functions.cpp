#include <iostream>
#include <conio.h>
#include <sstream>
#include "functions.h"
#include "Beach.h"
#include <vector>

using namespace std;

void validInputForChoice(string& choice,int min,int max)
{
	char num;
	num = _getch();
	while (num != 13) 
	{
		if (num == 8) 
		{
			if (choice.length() > 0)
			{
				cout << "\b \b";
				choice.erase(choice.length() - 1);
			}
		}
		else
		{
			choice += num;
			stringstream geek(choice);
			int number = 0;
			geek >> number;
			if (number >= min and number <= max)
			{
				cout << num;
			}
			else
			{
				choice = choice.substr(0, 1);
			}
		}
		num = _getch();
	}
}

bool menu(vector<Beach> &water)
{
	string choice;
	cout << "|--------------------------------------------|" << endl;
	cout << "|                    MENU                    |" << endl;
	cout << "| 1. Add a beach                             |" << endl;
	cout << "| 2. Remove a beach                          |" << endl;
	cout << "| 3. Edit a beach                            |" << endl;
	cout << "| 4. Display the info for a specific beach   |" << endl;
	cout << "| 5. List of the added beaches               |" << endl;
	cout << "| 6. Exit                                    |" << endl;
	cout << "|--------------------------------------------|" << endl;
	validInputForChoice(choice, 1, 6);
	return 1;
}