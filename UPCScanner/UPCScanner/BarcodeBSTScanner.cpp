/*/
#include "BarcodeBSTScanner.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <codecvt>

// initialize BST
void BarcodeBSTScanner::initialize()
{
	scanner = new BinarySearchTree<UPC>();
}

// BST constructor base 
BarcodeBSTScanner::BarcodeBSTScanner()
{
	initialize();
}

// BST destructor 
BarcodeBSTScanner::~BarcodeBSTScanner()
{
	delete scanner;
}

// search BST for provided code
void BarcodeBSTScanner::find(int64_t& code)
{
	UPC temp = UPC(code);
	UPC result = scanner->find(temp);
	cout << result;
}

// load UPC information from CSV file into BST
void BarcodeBSTScanner::loadFromFile(std::string& filePath)
{
	try
	{
		ifstream file;
		file.open(filePath);
		file.imbue(locale());
		string placeholderLine;

		// dump column header line
		getline(file, placeholderLine);

		// loop through file and load UPC 
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
*/
