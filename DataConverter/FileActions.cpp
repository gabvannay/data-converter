#include "FileActions.h"

std::vector<std::string> FileActions::getKeys()
{
	return keys;
}

std::vector<std::vector<std::string>> FileActions::getValues()
{
	return values;
}

/// <summary>
/// Open the file to the provided path and assign the type for later use
/// </summary>
/// <param name="path">The path leading to the file</param>
/// <param name="type">The format type of the file</param>
/// <param name="action">The action to do with the file, either 'r' for "reading" or 'w' for "write"</param>
FileActions::FileActions(std::string path, std::string type, char action)
{

	if (action == 'r')
	{
		file.open(path, std::ios::in);
	}
	else if (action == 'w')
	{
		file.open(path, std::ios::out);
	}
	else
	{
		throw std::invalid_argument("Invalid action !");
	}

	this->type = type;
	verifyFile();
}

/// <summary>
/// Check if the file is opened and if not throws an error. Automatically called by the constructor after initializing the file
/// </summary>
void FileActions::verifyFile()
{
	if (!file.is_open())
	{
		throw std::invalid_argument("File can't be open !");
	}
}

void FileActions::read()
{
	if (type == "csv")
		readCSV();
}

void FileActions::readCSV()
{
	std::string header;
	std::string wLine;

	std::getline(file, header);
	getKeys(header);

	while (std::getline(file, wLine))
	{
		values.push_back(
			parseCSV(wLine)
		);
	}
}

std::vector<std::string> FileActions::parseCSV(std::string line)
{
	int l = line.length();
	size_t pos = 0;
	size_t last = 0;
	std::vector<std::string> elements;

	for (pos; pos <= l; pos++)
	{
		char current = line[pos];
		if (current == ';' || current == '\0')
		{
			elements.push_back(line.substr(last, pos - last));
			last = pos + 1;
		}
	}

	return elements;
}

/// <summary>
/// Get the keys in the header of a CSV file. Will loop on the characters in the header and get the substring a each ';' character to put it in a vector containing the keys.
/// </summary>
/// <param name="header">The CSV file's header</param>
void FileActions::getKeys(std::string header)
{
	keys = parseCSV(header);
}