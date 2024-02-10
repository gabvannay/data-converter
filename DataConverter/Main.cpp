// DataConverter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Interactions.h"

int main()
{
	std::string* src = Interactions::askSourcePath();
	std::string* dest = Interactions::askDestinationPath();
}