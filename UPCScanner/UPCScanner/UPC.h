#pragma once

#ifndef UPC_H_
#define UPC_H_

#include <string>

// UPC class
class UPC
{
	public:
		// Constructor initializing UPC key and value
		UPC()
		{
			key = 0;
			value = "";
		}

		// Constructor initializing UPC with provided key and empty value
		UPC(int64_t& _key)
		{
			key = _key;
		}

		// Constructor initializing UPC with provided key and value
		UPC(int64_t& _key, std::string& _value)
		{
			key = _key;
			value = _value;
		}

		// Operator overload for greater than
		bool operator>(const UPC& other)
		{
			return (this->key > other.key);
		}

		// Operator overload for less than
		bool operator<(const UPC& other)
		{
			return (this->key < other.key);
		}

		// Operator overload for equal to
		bool operator==(const UPC& other)
		{
			return (this->key == other.key);
		}

		// Operator overload for out stream
		friend std::ostream& operator<<(std::ostream& os, UPC& other)
		{
			os << other.key << std::endl;
			os << other.value << std::endl;
			return os;
		}

	private:
		// UPC code
		int64_t key;

		// UPC description string
		std::string value;
};

#endif /* UPC_H_ */