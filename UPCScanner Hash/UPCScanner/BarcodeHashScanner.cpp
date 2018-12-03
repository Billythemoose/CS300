
#include "BarcodeHashScanner.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <codecvt>


BarcodeHashScanner::BarcodeHashScanner() { }


BarcodeHashScanner::~BarcodeHashScanner()
{
	delete[] scanner;
}


void BarcodeHashScanner::find(int64_t& code)
{
	int hashIndex = hash(code);
	std::string empty = "";
	UPC* add = new UPC(code, empty);
	Node<UPC>* root = scanner[hashIndex];
	if (hashCount[hashIndex] > 0) {
		while (root != NULL)
		{
			if ((root->data) == *add)
			{
				std::cout << root->data;
				break;
			}

			root = root->right;
		}
	}
	else {
		std::cout << "Does not exist in Hash" << std::endl;
	}
}

int BarcodeHashScanner::hash(int64_t& key) {
	return key % 1000;
}

void BarcodeHashScanner::loadFromFile(std::string& filePath)
{
	try
	{
		std::ifstream file;
		file.open(filePath);
		file.imbue(std::locale());
		std::string placeholderLine;

		// dump column header line
		getline(file, placeholderLine);

		// loop through file and load UPC 
		while (getline(file, placeholderLine))
		{
			// int key;
			int64_t key;
			std::string value;
			std::string placeholderKey;
			std::istringstream st(placeholderLine);
			std::getline(st, placeholderKey, ',');
			std::getline(st, value);

			std::istringstream stNum(placeholderKey);
			stNum >> key;
			int hashIndex = hash(key);
			if (hashIndex >= 0 && hashIndex <= 1000)
			{
				UPC* add = new UPC(key, value);
				Node<UPC>* newNode = new Node<UPC>();
				newNode->data = *add;
				Node<UPC>*& root = scanner[hashIndex];
				if (hashCount[hashIndex] <= 0) {
					root = newNode;
					hashCount[hashIndex]++;
				}
				else {
					Node<UPC>* temp = root;
					while (temp->right != NULL) {
						temp = temp->right;
					}

					temp->right = newNode;
					hashCount[hashIndex]++;
				}
			}
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void BarcodeHashScanner::print() {
	for (int i = 0; i < 1000; i++) {
		Node<UPC>* root = scanner[i];
		if (hashCount[i] > 0) {
			std::cout << "Values at node ";
			std::cout << i;
			std::cout << std::endl;
			while (root != NULL) {
				std::cout << root->data << std::endl;
				root = root->right;
			}
		}
	}
}
