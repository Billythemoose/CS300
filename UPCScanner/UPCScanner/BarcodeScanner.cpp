
#include "BarcodeBSTScanner.h"
#include <iostream>


using namespace std;

int main()
{
	cout << "File Path";
	string path;
	cin >> path;
	BarcodeBSTScanner* scan = new BarcodeBSTScanner();
	scan->loadFromFile(path);
	delete scan;
}