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

	void verifyFile();

	// CSV Methods
	void readCSV();
	void getKeys(std::string header);
public:
	FileActions(std::string path, std::string type, char action = 'r');
	void read();
};