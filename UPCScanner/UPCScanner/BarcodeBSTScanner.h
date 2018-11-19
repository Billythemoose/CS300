#pragma once

#include "BinarySearchTree.h"
#include "UPC.h"
// implement BST
// read from data file
	// UPC as key
	// info is value
	// there are no duplicates

class BarcodeBSTScanner
{
	public:
		BarcodeBSTScanner();
		void find(int& code);
		void loadFromFile(std::string& filePath);
		~BarcodeBSTScanner();
	private:
		BinarySearchTree<UPC>* scanner;
		void initialize();
};
