#pragma once

#include "UPC.h"
#include "Node.h"

class BarcodeHashScanner {
public:
	BarcodeHashScanner();
	void find(int64_t& code);
	void loadFromFile(std::string& code);
	~BarcodeHashScanner();
	void print();
private:
	int hash(int64_t& key);
	Node<UPC>** scanner = new Node<UPC>*[1000] {NULL};
	int* hashCount = new int[1000] {0};
};

// create array size 1000
// array contains nodes
// nodes are node<UPC>
// hash the key (number) from the item
// insert into that index