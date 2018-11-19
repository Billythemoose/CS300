
#include "BarcodeBSTScanner.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <codecvt>

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
}

void BarcodeBSTScanner::find(int64_t& code)
{
	UPC temp = UPC(code);
	// scanner->search(temp);
	UPC result = scanner->find(temp);
	cout << result;
}

void BarcodeBSTScanner::loadFromFile(std::string& filePath)
{
	try
	{
		ifstream file;
		file.open(filePath);

		// file.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));
		file.imbue(locale());
		string placeholderLine;
		getline(file, placeholderLine);
		while(getline(file, placeholderLine))
		{
			// int key;
			int64_t key;
			string value;
			string placeholderKey;
			istringstream st(placeholderLine);
			getline(st, placeholderKey, ',');
			getline(st, value);

			istringstream stNum(placeholderKey);
			stNum >> key;

			UPC* add = new UPC(key, value);
			scanner->insert(*add);
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << endl;
	}
}