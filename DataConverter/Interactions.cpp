#include <iostream>
#include "Interactions.h"

/*
void Interactions::askParams() 
{
	askSourcePath();
	askDestinationDatatype();
	askDestinationPath();
}
*/

/// <summary>
/// Asks for the path leading to the source file. Will then try to get the extension to find the datatype.
/// </summary>
/// <returns>A pointer, if I understand correctly, to an array containing the path and the datatype</returns>
std::string* Interactions::askSourcePath()
{
	// First get the path
	std::string path;
	std::cout << "Source path: ";
	std::cin >> path;
	std::cout << std::endl;

	// Then the extension
	std::string type = getFileExtension(path);

	// And return !
	static std::string res[2] = { path, type };
	return res;
}

/// <summary>
/// Asks for the path leading to the destination file. Will then try to get the extension to find the datatype.
/// </summary>
/// <returns>A pointer, if I understand correctly, to an array containing the path and the datatype</returns>
std::string* Interactions::askDestinationPath()
{
	std::string path;
	std::cout << "Destination path: ";
	std::cin >> path;
	std::cout << std::endl;

	std::string type = getFileExtension(path);

	static std::string res[2] = { path, type };
	return res;
}

/// <summary>
/// Will look for the last dot char '.' in the provided path and read the substring after that to get the extension.
/// If the extention is not valid an error is thrown.
/// </summary>
/// <param name="path">The path to the file</param>
/// <returns>The extension found</returns>
std::string Interactions::getFileExtension(std::string path)
{
	std::string availableTypes[4] = { "json", "csv", "php", "txt" };
	size_t pos = path.find_last_of('.');

	if (pos == std::string::npos)
	{
		throw std::invalid_argument("The provided file doesn't contain a valid extension.\nAvailable extensions: \"*.json\", \"*.csv\", \"*.php\", \"*.txt\".");
	}

	std::string srcDatatype = path.substr(pos + 1);
	int size = sizeof(availableTypes) / sizeof(*availableTypes);

	if (std::find(availableTypes, availableTypes + size, srcDatatype) == availableTypes + size)
	{
		throw std::invalid_argument("The provided file doesn't contain a valid extension.\nAvailable extensions: \"*.json\", \"*.csv\", \"*.php\", \"*.txt\".");
	}

	return srcDatatype;
}