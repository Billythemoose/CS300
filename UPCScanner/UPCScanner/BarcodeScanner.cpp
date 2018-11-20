
#include "BarcodeBSTScanner.h"
#include "BarcodeArrayScanner.h"
#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

// main UPC BST
BarcodeBSTScanner* scanBST;

// main UPC Array
BarcodeArrayScanner* scanArray;

// loads UPC information from csv
void loadFromFile(string path)
{
	clock_t timer;
	cout << "Loading. This will take some time..." << endl;

	cout << "Loading file into BST..." << endl;
	timer = clock();
	scanBST->loadFromFile(path);
	timer = clock() - timer;
	cout << "BST Load Time: " << timer * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

	cout << endl;

	cout << "Loading file into Array..." << endl;
	timer = clock();
	scanArray->loadFromFile(path);
	timer = clock() - timer;
	cout << "Array Load Time: " << timer * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

	cout << endl;
}

// asks for UPC then searches both BST and Array for code 
bool findCode()
{
	try
	{
		cout << "Search for UPC: ";
		string upcString;
		int64_t upcInt;
		cin >> upcInt;
		cout << "Searching for UPC: " << upcInt << endl;
		clock_t timer;
		timer = clock();
		scanBST->find(upcInt);
		timer = clock() - timer;
		cout << "BST Search Time: " << timer * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
		timer = clock();
		scanArray->find(upcInt);
		timer = clock() - timer;
		cout << "Array Search Time: " << timer * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
	}
	catch (exception& e)
	{
		cout << "Not valid UPC input" << endl;
	}

	string again;
	cout << "Search for another UPC? (Y/N): ";
	cin >> again;
	return (again == "Y" || again == "y");
	cout << endl;
}


// main entry point
int main()
{
	cout << "File Path: ";
	string path;
	cin >> path;

	scanBST = new BarcodeBSTScanner();
	scanArray = new BarcodeArrayScanner();
	loadFromFile(path);

	while (findCode()) { }

	delete scanBST;
	delete scanArray;
}