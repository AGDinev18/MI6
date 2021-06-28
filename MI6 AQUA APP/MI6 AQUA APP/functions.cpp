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

void editMenu()
{
	cout << "\n|--------------------------------------------|" << endl;
	cout << "|                    MENU                    |" << endl;
	cout << "| 1. Change the name                         |" << endl;
	cout << "| 2. Change the groundSwell state            |" << endl;
	cout << "| 3. Change the umbrella price               |" << endl;
	cout << "| 4. Change the swimming permission          |" << endl;
	cout << "| 5. Change the flag                         |" << endl;
	cout << "|--------------------------------------------|" << endl;
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
	cout << "\nEnter name: ";
	cin >> name;
	beach.name = name;
	cout << "Enter ground-swell: ";
	cin >> groundSwell;
	beach.setGroundSwell(groundSwell);
	cout << "Enter umbrella price: ";
	cin >> beachUmbrellaPrice;
	beach.setBeachUmbrellaPrice(beachUmbrellaPrice);
	cout << "Enter sunbed price: ";
	cin >> sunbedPrice;
	beach.setSunbedPrice(sunbedPrice);
	cout << "Enter swimming permission: ";
	cin >> swimmingPermission;
	beach.setSwimmingPermission(swimmingPermission);
	cout << "\nEnter flag \n1. Green\n2. Yellow\n3. Red";
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
	cout << "\nEnter the name of the beach: ";
	for (size_t i = 0; i < beaches.size(); i++)
	{
		if (beaches[i].name == name)
		{
			beaches.erase(beaches.begin() + i);
			return;
		}
	}
}

int getIdByName(vector<Beach>& beaches,string name)
{
	int id = -1;
	for (size_t i = 0; i < beaches.size(); i++)
	{
		if (beaches[i].name == name)
		{
			id = i;
		}
	}
	return id;
}

void editBeach(vector<Beach>& beaches)
{
	string name;
	cout << "\nEnter the name of the beach: ";
	cin >> name;
	int id = getIdByName(beaches, name);
	bool groundSwell;
	double beachUmbrellaPrice;
	double sunbedPrice;
	bool swimmingPermission;
	Flag flag;
	string temp;
	editMenu();
	validInputForChoice(temp, 1, 6);
	stringstream sstream(temp);
	int choice = 0;
	sstream >> choice;
	switch (choice)
	{
	case 1: cout << "\nEnter a name for the beach: ";
		cin >> name;
		beaches[id].name = name;
		break;
	case 2: cout << "\nEnter new ground-swell state: ";
		cin >> groundSwell;
		beaches[id].setGroundSwell(groundSwell);
		break;
	case 3: cout << "\nEnter new price for umbrella: ";
		cin >> beachUmbrellaPrice;
		beaches[id].setBeachUmbrellaPrice(beachUmbrellaPrice);
		break;
	case 4: cout << "\nEnter new permission of swimming: ";
		cin >> swimmingPermission;
		beaches[id].setSwimmingPermission(swimmingPermission);
		break;
	case 5: cout << "\nEnter new flag \n1. Green\n2. Yellow\n3. Red";
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
		beaches[id].setSwimmingFlag(flag);
	}
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
	cout << "\n|--------------------------------------------|" << endl;
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