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
	std::cout << "Source type: " << src[1] << "\n\n";

	FileActions fa = FileActions(src[0], src[1]);
	fa.read();

	std::vector<std::string> keys = fa.getKeys();
	std::vector<std::vector<std::string>> values = fa.getValues();

	int size = keys.size();
	for (std::vector<std::string> v : values)
	{
		for (int i = 0; i <size; i++)
		{
			std::cout << keys.at(i) << ": " << v.at(i) << '\n';
		}

		std::cout << '\n';
	}
}