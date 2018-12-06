#pragma once

#include <iostream>
#include "Scanner.h"

// Barcode scanner array class
template <class T>
class BarcodeArrayScanner: public Scanner<T> 
{
	public:
		// Array constructor
		BarcodeArrayScanner(T* _database, int _size) : database(_database), size(_size) {}

		// Search for provided UPC in array
		// void find(int64_t& code);
		void scan(T& product)
		{
			/*
			T* ptr = database;

			while (ptr != nullptr)
			{
				if (*ptr == product)
				{
					std::cout << *ptr;
				}

				++ptr;
			}
			*/

			
			for (int i = 0; i < size; i++)
			{
				if (database[i] == product)
				{
					std::cout << database[i];
					break;
				}
			}
			
		}

		void setDatabase(T* _database)
		{
			database = _database;
		}

		void setSize(int _size)
		{
			size = _size;
		}

		// Load UPC information from CSV into array
		// void loadFromFile(std::string& filePath);

		// Array destructor
		~BarcodeArrayScanner()
		{
			delete database;
		}

	private:
		// main array container
		// UPC* scanner = new UPC[1];
		T* database;

		// array size
		int size;
};


