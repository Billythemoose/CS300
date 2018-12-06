#pragma once

#include "BinarySearchTree.h"
#include "Scanner.h"

// Barcode scanner BST class
template <class T>
class BarcodeBSTScanner : public Scanner<T>  
{
	public:
		// Constructor for barcode BST
		BarcodeBSTScanner(BinarySearchTree<T>& _database) : database(_database) {}

		// Search BST for provided UPC 
		// void find(int64_t& code);
		void scan(T& product)
		{
			T result = database.find(product);
			cout << result;
		}

		// Load UPC information from CSV file into BST
		// void loadFromFile(std::string& filePath);
		void setDatabase(BinarySearchTree<T> _database)
		{
			database = _database;
		}
		/*
		// Destructor for barcode BST
		~BarcodeBSTScanner()
		{
			delete database;
		}
		*/
	private:
		// Main BST container
		BinarySearchTree<T> database;

		// Initialize BST
		// void initialize();
};
