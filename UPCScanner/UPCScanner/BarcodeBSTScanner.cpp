
#include "BarcodeBSTScanner.h"
#include <iostream>
#include <fstream>
#include <sstream>

void BarcodeBSTScanner::initialize()
{
	scanner = new BinarySearchTree<UPC>();
}

BarcodeBSTScanner::BarcodeBSTScanner()
{
	initialize();
}

BarcodeBSTScanner::~BarcodeBSTScanner()
{
	delete scanner;
	initialize();
}

void BarcodeBSTScanner::find(int& code)
{
	UPC temp = UPC(code);
	scanner->search(temp);
}

void BarcodeBSTScanner::loadFromFile(std::string& filePath)
{
	try
	{
		ifstream file;
		file.open(filePath);
		string placeholderLine;
		while(getline(file, placeholderLine))
		{
			int key;
			string value;
			string placeholderKey;
			stringstream st(placeholderLine);
			getline(st, placeholderKey, ',');
			getline(st, value);
			key = stoi(placeholderKey);

			UPC add = UPC(key, value);
			scanner->insert(add);

		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << endl;
	}
}