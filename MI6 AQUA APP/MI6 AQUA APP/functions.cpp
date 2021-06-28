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
	cout << "| 4. Change the sunbed price                 |" << endl;
	cout << "| 5. Change the swimming permission          |" << endl;
	cout << "| 6. Change the flag                         |" << endl;
	cout << "|--------------------------------------------|" << endl;
}

void addBeach(vector<Beach>& beaches)
{
	Beach beach;
	string name_;
	bool groundSwell_;
	double beachUmbrellaPrice_;
	double sunbedPrice_;
	bool swimmingPermission_;
	int choice;
	Flag flag_;
	cout << "\nEnter name: ";
	cin >> name_;
	beach.setName(name_);
	cout << "Enter ground-swell: ";
	cin >> groundSwell_;
	beach.setGroundSwell(groundSwell_);
	cout << "Enter umbrella price: ";
	cin >> beachUmbrellaPrice_;
	beach.setBeachUmbrellaPrice(beachUmbrellaPrice_);
	cout << "Enter sunbed price: ";
	cin >> sunbedPrice_;
	beach.setSunbedPrice(sunbedPrice_);
	cout << "Enter swimming permission: ";
	cin >> swimmingPermission_;
	beach.setSwimmingPermission(swimmingPermission_);
	cout << "\nEnter flag \n1. Green\n2. Yellow\n3. Red\n";
	cin >> choice;
	switch (choice)
	{
	case 1: flag_ = green;
		break;
	case 2: flag_ = yellow;
		break;
	case 3: flag_ = red;
		break;
	default:
		break;
	}
	beach.setSwimmingFlag(flag_);
	beaches.push_back(beach);
}

void removeBeach(vector<Beach>& beaches)
{
	string name_;
	cout << "\nEnter the name of the beach: ";
	cin >> name_;
	for (size_t i = 0; i < beaches.size(); i++)
	{
		if (beaches[i].returnName() == name_)
		{
			beaches.erase(beaches.begin() + i);
			return;
		}
	}
}

int getIdByName(vector<Beach>& beaches,string name_)
{
	int id = -1;
	for (size_t i = 0; i < beaches.size(); i++)
	{
		if (beaches[i].returnName() == name_)
		{
			id = i;
		}
	}
	return id;
}

void editBeach(vector<Beach>& beaches)
{
	string name_;
	cout << "\nEnter the name of the beach: ";
	cin >> name_;
	int id = getIdByName(beaches, name_);
	bool groundSwell_;
	double beachUmbrellaPrice_;
	double sunbedPrice_;
	bool swimmingPermission_;
	Flag flag_;
	string temp;
	editMenu();
	validInputForChoice(temp, 1, 6);
	stringstream sstream(temp);
	int choice = 0;
	sstream >> choice;
	switch (choice)
	{
	case 1: cout << "\nEnter a name for the beach: ";
		cin >> name_;
		beaches[id].setName(name_);
		break;
	case 2: cout << "\nEnter new ground-swell state: ";
		cin >> groundSwell_;
		beaches[id].setGroundSwell(groundSwell_);
		break;
	case 3: cout << "\nEnter new price for umbrella: ";
		cin >> beachUmbrellaPrice_;
		beaches[id].setBeachUmbrellaPrice(beachUmbrellaPrice_);
		break;
	case 4:
		cout << "\nEnter new price for sunbed: ";
		cin >> sunbedPrice_;
		beaches[id].setSunbedPrice(sunbedPrice_);
		break;
	case 5: 
		cout << "\nEnter new permission of swimming: ";
		cin >> swimmingPermission_;
		beaches[id].setSwimmingPermission(swimmingPermission_);
		break;
	case 6:
		cout << "\nEnter new flag \n1. Green\n2. Yellow\n3. Red\n";
		cin >> choice;
		switch (choice)
		{
		case 1: flag_ = green;
			break;
		case 2: flag_ = yellow;
			break;
		case 3: flag_ = red;
			break;
		default:
			break;
		}
		beaches[id].setSwimmingFlag(flag_);
		break;
	}
}

void displayBeach(Beach beach)
{
	cout << "\n----------------------------";
	cout << "\nName: " << beach.returnName();
	cout << "\nGround-swell: ";
	if (beach.returnFlag())
		cout << "Yes";
	else cout << "No";
	cout << "\nPrice for umbrella: " << beach.returnUmbrellaPrice();
	cout << "\nPrice for sunbed: " << beach.returnSunbedPrice();
	cout << "\nPermission for swimming: ";
	if (beach.returnSwimmingPermission())
		cout << "Yes";
	else cout << "No";
	cout << "\nFlag: ";
	switch (beach.returnFlag())
	{
	case 0: cout << "Green";
		break;
	case 1: cout << "Yellow";
		break;
	case 2: cout << "Red";
		break;
	}
	cout << "\n----------------------------";
}

void displayAllBeaches(vector<Beach>& beaches)
{
	for (size_t i = 0; i < beaches.size(); i++)
	{
		displayBeach(beaches[i]);
	}
}

bool menu(vector<Beach>& beaches)
{
	int id;
	string name_;
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
		cout << "\nEnter the name of the beach: ";
		cin >> name_;
		id = getIdByName(beaches, name_);
		displayBeach(beaches[id]);
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