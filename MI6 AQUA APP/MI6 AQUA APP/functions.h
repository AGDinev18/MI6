#pragma once
#include "Beach.h"
#include <vector>

void validInputForChoice(std::string& choice, int min, int max);

void editMenu();

void addBeach(std::vector<Beach>& beaches);

void removeBeach(std::vector<Beach>& beaches);

void editBeach(std::vector<Beach>& beaches);

void displayBeach(std::vector<Beach>& beaches);

void displayAllBeaches(std::vector<Beach>& beaches);

bool menu(std::vector<Beach>& water);