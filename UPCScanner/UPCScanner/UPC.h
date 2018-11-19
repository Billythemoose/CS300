#pragma once

#ifndef UPC_H_
#define UPC_H_

#include <string>

class UPC
{
	public:
		UPC(int& _key, std::string& _value);
		bool operator>(const UPC& other);
		bool operator<(const UPC& other);
	private:
		int key;
		std::string value;
};

UPC::UPC(int& _key, std::string& _value)
{
	key = _key;
	value = _value;
}

bool UPC::operator>(const UPC& other)
{
	return (this->key > other.key);
}

bool UPC::operator<(const UPC& other)
{
	return (this->key < other.key);
}

#endif /* UPC_H_ */