#pragma once

#include "UPC.h"

class BarcodeArrayScanner
{
	public:
		BarcodeArrayScanner();
		void find(int64_t& code);
		void loadFromFile(std::string& filePath);
		~BarcodeArrayScanner();
	private:
		UPC* scanner = new UPC[1];
		int size;
		// void initialize();
};


