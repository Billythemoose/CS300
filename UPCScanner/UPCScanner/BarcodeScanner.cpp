
#include "BarcodeBSTScanner.h"
#include "BarcodeArrayScanner.h"
#include "UPC.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <algorithm>

using namespace std;

BinarySearchTree<UPC> baseBST;
UPC* baseArray;
int baseArraySize;

// loads UPC information from csv
void loadFromFile(string path)
{
	try
	{		
		std::ifstream file;
		file.open(path);
		std::string placeholderLine;

		// dump column header line
		getline(file, placeholderLine);

		// loop through file to create array size
		baseArraySize = 0;
		while (getline(file, placeholderLine))
		{
			baseArraySize++;
		}

		file.close();


		baseBST = BinarySearchTree<UPC>();
		baseArray = new UPC[baseArraySize];

		file.open(path);

		// dump column header line
		getline(file, placeholderLine);

		// loop through file and add UPC to array
		int index = 0;
		while (getline(file, placeholderLine))
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
			baseBST.insert(add);
			baseArray[index] = add;
			index++;
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << endl;
	}
}


void scan(Scanner<UPC>* scanner, UPC item)
{
	scanner->scan(item);
}

bool find()
{
	cout << "Search for UPC: ";
	string upcString;
	int64_t upcInt;
	cin >> upcInt;
	cout << "Searching for UPC: " << upcInt << endl;
	UPC searchItem = UPC(upcInt);
	clock_t timer;

	Scanner<UPC>* scanner = new BarcodeBSTScanner<UPC>(baseBST);
	timer = clock();
	scan(scanner, searchItem);
	timer = clock() - timer;
	cout << "BST Search Time: " << timer * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

	scanner = new BarcodeArrayScanner<UPC>(baseArray, baseArraySize);
	timer = clock();
	scan(scanner, searchItem);
	timer = clock() - timer;
	cout << "Array Search Time: " << timer * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

	scanner = NULL;
	delete scanner;

	string again;
	cout << "Search for another UPC? (Y/N): ";
	cin >> again;
	return (again == "Y" || again == "y");
}



// main entry point
int main()
{
	cout << "File Path: ";
	string path;
	cin >> path;

	loadFromFile(path);

	while (find()) { }
}