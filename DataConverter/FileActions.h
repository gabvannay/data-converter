#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class FileActions {
private:
	std::fstream file;
	std::string type;
	
	std::vector<std::string> keys;
	std::vector<std::vector<std::string>> values;

	void verifyFile();

	// CSV Methods
	void readCSV();
	std::vector<std::string> parseCSV(std::string line);
	void getKeys(std::string header);
public:
	FileActions(std::string path, std::string type, char action = 'r');
	void read();

	std::vector<std::string> getKeys();
	std::vector<std::vector<std::string>> getValues();
};