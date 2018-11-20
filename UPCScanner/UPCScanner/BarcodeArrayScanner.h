#pragma once

#include "UPC.h"

// Barcode scanner array class
class BarcodeArrayScanner
{
	public:
		// Array constructor
		BarcodeArrayScanner();

		// Search for provided UPC in array
		void find(int64_t& code);

		// Load UPC information from CSV into array
		void loadFromFile(std::string& filePath);

		// Array destructor
		~BarcodeArrayScanner();
	private:
		// main array container
		UPC* scanner = new UPC[1];

		// array size
		int size;
};


