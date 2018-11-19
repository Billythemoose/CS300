#pragma once

#ifndef UPC_H_
#define UPC_H_

#include <string>

class UPC
{
	public:
		UPC()
		{
			key = 0;
			value = "";
		}

		UPC(int& _key)
		{
			key = _key;
		}

		UPC(int& _key, std::string& _value)
		{
			key = _key;
			value = _value;
		}

		bool operator>(const UPC& other)
		{
			return (this->key > other.key);
		}

		bool operator<(const UPC& other)
		{
			return (this->key < other.key);
		}

		friend std::ostream& operator<<(std::ostream& os, UPC& other)
		{
			os << other.key << std::endl;
			os << other.value << std::endl;
			return os;
		}

	private:
		int key;
		std::string value;
};

/*
UPC::UPC()
{
	key = 0;
	value = "";
}

UPC::UPC(int& _key)
{
	key = _key;
}

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

std::ostream& operator<<(std::ostream& os, UPC& other)
{
	os << other.key << std::endl;
	os << other.value << std::endl;
	return os;
}
*/

#endif /* UPC_H_ */