#include <iostream>
#include <conio.h>
#include <sstream>
#include "functions.h"
#include "Beach.h"
#include <vector>

using namespace std;

void validInputForChoice(string& choice, int min, int max)
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
			if (num >= '1' and num <= '9')
			{
				choice += num;
				stringstream sstream(choice);
				int number = 0;
				sstream >> number;
				if (number >= min and number <= max)
				{
					cout << num;
				}
				else
				{
					choice = choice.substr(0, 1);
				}
			}
		}
		num = _getch();
	}
}


void addBeach(vector<Beach>& beaches)
{
	Beach beach;
	string name;
	bool groundSwell;
	double beachUmbrellaPrice;
	double sunbedPrice;
	bool swimmingPermission;
	int choice;
	Flag flag;
	cout << "Enter name: ";
	cin >> name;
	beach.name = name;
	cout << "Enter groundSwell: ";
	cin >> groundSwell;
	beach.setGroundSwell(groundSwell);
	cout << "Enter beachUmbrellaPrice: ";
	cin >> beachUmbrellaPrice;
	beach.setBeachUmbrellaPrice(beachUmbrellaPrice);
	cout << "Enter sunbedPrice: ";
	cin >> sunbedPrice;
	beach.setSunbedPrice(sunbedPrice);
	cout << "Enter swimmingPermission: ";
	cin >> swimmingPermission;
	beach.setSwimmingPermission(swimmingPermission);
	cout << "Enter flag \n1. Green\n2. Yellow\n3. Red";
	cin >> choice;
	switch (choice)
	{
	case 1: flag = green;
		break;
	case 2: flag = yellow;
		break;
	case 3: flag = red;
		break;
	default:
		break;
	}
	beach.setSwimmingFlag(flag);
	beaches.push_back(beach);
}

void removeBeach(vector<Beach>& beaches)
{
	string name;
	cout << "Enter the name of the beach: ";
	for (size_t i = 0; i < beaches.size(); i++)
	{
		if (beaches[i].name == name)
		{
			beaches.erase(beaches.begin() + i);
			return;
		}
	}
}

void editBeach(vector<Beach>& beaches)
{

}

void displayBeach(vector<Beach>& beaches)
{

}

void displayAllBeaches(vector<Beach>& beaches)
{

}

bool menu(vector<Beach>& beaches)
{
	string temp;
	cout << "|--------------------------------------------|" << endl;
	cout << "|                    MENU                    |" << endl;
	cout << "| 1. Add a beach                             |" << endl;
	cout << "| 2. Remove a beach                          |" << endl;
	cout << "| 3. Edit a beach                            |" << endl;
	cout << "| 4. Display the info for a specific beach   |" << endl;
	cout << "| 5. List of the added beaches               |" << endl;
	cout << "| 6. Exit                                    |" << endl;
	cout << "|--------------------------------------------|" << endl;
	validInputForChoice(temp, 1, 6);
	stringstream sstream(temp);
	int choice = 0;
	sstream >> choice;
	switch (choice)
	{
	case 1:
		addBeach(beaches);
		break;
	case 2:
		removeBeach(beaches);
		break;
	case 3:
		editBeach(beaches);
		break;
	case 4:
		displayBeach(beaches);
		break;
	case 5:
		displayAllBeaches(beaches);
		break;
	case 6:
		return 0;
	default: 
		break;
	}
	return 1;
}