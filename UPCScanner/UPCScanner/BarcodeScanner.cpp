
#include "BarcodeBSTScanner.h"
#include "BarcodeArrayScanner.h"
#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

int main()
{
	cout << "File Path: ";
	string path;
	cin >> path;

	clock_t timer;
	cout << "Loading. This will take some time..." << endl;
	
	cout << "Loading file into BST..." << endl;
	BarcodeBSTScanner* scanBST = new BarcodeBSTScanner();
	timer = clock();
	scanBST->loadFromFile(path);
	timer = clock() - timer;
	cout << "BST Load Time: " << timer * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

	cout << "Loading file into Array..." << endl;
	BarcodeArrayScanner* scanArray = new BarcodeArrayScanner();
	timer = clock();
	scanArray->loadFromFile(path);
	timer = clock() - timer;
	cout << "Array Load Time: " << timer * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

	cout << endl;
	cout << "Search for UPC: ";
	string upcString;
	int64_t upcInt;
	cin >> upcInt;
	cout << "Searching for UPC: " << upcInt << endl;
	timer = clock();
	scanBST->find(upcInt);
	timer = clock() - timer;
	cout << "BST Search Time: " << timer * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
	timer = clock();
	scanArray->find(upcInt);
	timer = clock() - timer;
	cout << "Array Search Time: " << timer * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

	/*
	scan->loadFromFile(path);
	timer = clock() - timer;
	cout << "Load Time: " << timer * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

	cout << "Search for UPC: ";
	string upcString;
	// cin >> upcString;
	int64_t upcInt;
	cin >> upcInt;
	cout << "Searching for UPC: " << upcInt << endl;
	timer = clock();
	scan->find(upcInt);
	timer = clock() - timer;
	cout << "Search Time: " << timer * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

	cout << "Search for UPC: ";
	cin >> upcInt;
	cout << "Searching for UPC: " << upcInt << endl;
	timer = clock();
	scan->find(upcInt);
	timer = clock() - timer;
	cout << "Search Time: " << timer * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
	*/

	delete scanBST;
	delete scanArray;
}