
#include "BarcodeArrayScanner.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

/*
void BarcodeArrayScanner::initialize()
{

}
*/

BarcodeArrayScanner::BarcodeArrayScanner()
{
	size = 0;
}

BarcodeArrayScanner::~BarcodeArrayScanner()
{
	delete[] scanner;
}

void BarcodeArrayScanner::loadFromFile(std::string& filePath)
{
	std::ifstream file;
	file.open(filePath);
	std::string placeholderLine;
	getline(file, placeholderLine);
	while(getline(file, placeholderLine))
	{
		size++;
	}

	file.close();
	delete[] scanner;
	scanner = new UPC[size];
	
	file.open(filePath);
	getline(file, placeholderLine);
	int index = 0;
	while(getline(file, placeholderLine))
	{
		int64_t key;
		std::string value;
		std::string placeholderKey;
		std::istringstream st(placeholderLine);
		getline(st, placeholderKey, ',');
		getline(st, value);

		std::istringstream stNum(placeholderKey);
		stNum >> key;

		UPC add = UPC(key, value);
		scanner[index] = add;
		index++;
	}

	std::sort(scanner, scanner + size);
}

void BarcodeArrayScanner::find(int64_t& code)
{
	std::string empty = "";
	UPC temp = UPC(code, empty);
	for (int i = 0; i < size; i++)
	{
		if (scanner[i] == temp)
		{
			std::cout << scanner[i];
		}
	}
}
