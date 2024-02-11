// DataConverter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Interactions.h"
#include "FileActions.h"

int main()
{
	std::string* src = Interactions::askSourcePath();
	//std::string* dest = Interactions::askDestinationPath();

	std::cout << "Source path: " << src[0] << '\n';
	std::cout << "Source type: " << src[1] << '\n';

	FileActions fa = FileActions(src[0], src[1]);
	fa.read();
}