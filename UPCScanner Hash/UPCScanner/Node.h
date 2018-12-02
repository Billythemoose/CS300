#pragma once

#ifndef NODE_H_
#define NODE_H_

// Node template class
template <class T>
class Node
{
	public:
		// Node data
		T data;

		// Node pointer to the left
		Node<T>* left;

		// Node pointer to the right
		Node<T>* right;

		// Constructor initializing Node
		Node();

		// Constructor initializing Node with data
		Node(T& item);

		// Copy constructor for Node
		Node(Node& other);

		// Destructor for Node
		~Node();
};

// Constructor initializing Node
template <class T>
Node<T>::Node() {}

// Constructor initializing Node with data
template <class T>
Node<T>::Node(T& item)
{
	data = item;
}

// Copy constructor for Node
template <class T>
Node<T>::Node(Node& other)
{
	left = *other.left;
	right = *other.right;
	data = other.data;
}

// Destructor for Node
template <class T>
Node<T>::~Node()
{
	if (left) {
		left = nullptr;
	}

	if (right) {
		right = nullptr;
	}
}

#endif /* NODE_H_ */