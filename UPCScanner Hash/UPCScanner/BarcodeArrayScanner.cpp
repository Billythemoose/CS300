
#include "BarcodeArrayScanner.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

// Array constructor
BarcodeArrayScanner::BarcodeArrayScanner()
{
	size = 0;
}

// Array destructor
BarcodeArrayScanner::~BarcodeArrayScanner()
{
	delete[] scanner;
}

// load UPC information from CSV into array
void BarcodeArrayScanner::loadFromFile(std::string& filePath)
{
	std::ifstream file;
	file.open(filePath);
	std::string placeholderLine;

	// dump column header line
	getline(file, placeholderLine);

	// loop through file to create array size
	while(getline(file, placeholderLine))
	{
		size++;
	}

	file.close();
	delete[] scanner;
	scanner = new UPC[size];
	file.open(filePath);

	// dump column header line
	getline(file, placeholderLine);

	// loop through file and add UPC to array
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

	file.close();
	std::sort(scanner, scanner + size);
}

// search for provided UPC in array 
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
