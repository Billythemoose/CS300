
#include "BarcodeBSTScanner.h"
#include <iostream>


using namespace std;

int main()
{
	cout << "File Path: ";
	string path;
	cin >> path;
	BarcodeBSTScanner* scan = new BarcodeBSTScanner();
	scan->loadFromFile(path);

	cout << "Search for UPC: ";
	string upcString;
	// cin >> upcString;
	int64_t upcInt;
	cin >> upcInt;
	scan->find(upcInt);

	delete scan;
}