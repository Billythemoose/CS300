#pragma once

#ifndef NODE_H_
#define NODE_H_

template <class T>
class Node
{
	public:
		T data;
		Node<T>* left;
		Node<T>* right;
		Node();
		Node(T& item);
		Node(Node& other);
		~Node();
};

template <class T>
Node<T>::Node()
{
	left = new Node<T>;
	right = new Node<T>;
}

template <class T>
Node<T>::Node(T& item)
{
	data = item;
	left = new Node<T>;
	right = new Node<T>;
}


template <class T>
Node<T>::Node(Node& other)
{
	left = *other.left;
	right = *other.right;
	data = other.data;
}

template <class T>
Node<T>::~Node()
{
	delete left;
	delete right;
}

#endif /* NODE_H_ */