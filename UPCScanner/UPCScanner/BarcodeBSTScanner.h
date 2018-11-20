#pragma once

#include "BinarySearchTree.h"
#include "UPC.h"

// Barcode scanner BST class
class BarcodeBSTScanner
{
	public:
		// Constructor for barcode BST
		BarcodeBSTScanner();

		// Search BST for provided UPC 
		void find(int64_t& code);

		// Load UPC information from CSV file into BST
		void loadFromFile(std::string& filePath);

		// Destructor for barcode BST
		~BarcodeBSTScanner();
	private:
		// Main BST container
		BinarySearchTree<UPC>* scanner;

		// Initialize BST
		void initialize();
};
