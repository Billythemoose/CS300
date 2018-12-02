
#include "BarcodeHashScanner.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <codecvt>


BarcodeHashScanner::BarcodeHashScanner()
{
	// delete[] hashCount;
	// hashCount = new int[1000];
}


BarcodeHashScanner::~BarcodeHashScanner()
{
	delete[] scanner;
}


void BarcodeHashScanner::find(int64_t& code)
{
	/*
	UPC temp = UPC(code);
	UPC result = scanner->find(temp);
	cout << result;
	*/

	// create a fake UPC container
	// hash the code
	// go to the index of the hash
	// loop through the linked list until empty or found
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
			UPC* add = new UPC(key, value);
			Node<UPC>* newNode = new Node<UPC>();
			newNode->data = *add;
			Node<UPC>*& root = scanner[hashIndex];
			if (hashCount[hashIndex] <= 0) {
				root = newNode;
				hashCount[hashIndex]++;
			}
			else {
				while (root->right != NULL) {
					root = root->right;
				}

				root->right = newNode;
				hashCount[hashIndex]++;
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

/*
template <class HashedObj>class HashTable {
public:
		HashTable(const HashedObj & notFound, int size = 101);
		HashTable(const HashTable & rhs) :ITEM_NOT_FOUND(rhs.ITEM_NOT_FOUND), theLists(rhs.theLists) { }
		const HashedObj & find(const HashedObj & x) const;
		void makeEmpty();
		void insert(const HashedObj & x);
		void remove(const HashedObj & x);
		const HashTable & operator=(const HashTable & rhs);
	private:
		vector<List<HashedObj> > theLists;
		// The array of Lists
		const HashedObj ITEM_NOT_FOUND;};
		int hash( const string & key, int tableSize );
		int hash( int key, int tableSize );
}

-- Insert item x into the hash table. If the item is* already present, then do nothing.
template <class HashedObj>
void HashTable<HashedObj>::insert(const HashedObj & x) {
	List<HashedObj> & whichList = theLists[hash(x, theLists.size())];
	ListItr<HashedObj> itr = whichList.find(x);
	if (!itr.isValid())
		whichList.insert(x, whichList.zeroth());
}

// Remove item x from the hash table.
template <class HashedObj>void HashTable<HashedObj>::remove(const HashedObj & x) {
	theLists[hash(x, theLists.size())].remove(x);
}

//  Find item x in the hash table.* Return the matching item or ITEM_NOT_FOUND if not found
template <class HashedObj>const HashedObj & HashTable<HashedObj>::find(const HashedObj & x) const {
	ListItr<HashedObj> itr;
	itr = theLists[hash(x, theLists.size())].find(x);
	if (!itr.isValid())
		return ITEM_NOT_FOUND;
	else
		return itr.retrieve();
}
*/