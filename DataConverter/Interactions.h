#pragma once
#include <iostream>

class Interactions {
public:
	static std::string* askSourcePath();
	static std::string* askDestinationPath();
private:
	static std::string getFileExtension(std::string path);
};