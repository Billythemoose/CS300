#pragma once

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include "Node.h"
#include <iostream>

using namespace std;

/*
template <class T>
struct node {
	T data;
	node<T>* left;
	node<T>* right;
};
*/

template <class T>
class BinarySearchTree {

public:
	BinarySearchTree();
	void printInOrder() { printInOrder(root); }
	void printPreOrder() { printPreOrder(root); }
	void printPostOrder() { printPostOrder(root); }
	int height() { return height(root); }
	void insert(T& item) { insert(root, item); }
	bool search(T& item) { return search(root, item); }
	T findMax(T& e) { return findMax(root, e); }
	T findMin(T& e) { return findMin(root, e); }
	void deletenode(T& item) { deletenode(root, item); }
	~BinarySearchTree() { destroy(root); }

private:
	Node<T>* root;
	void printInOrder(Node<T>*);
	void printPreOrder(Node<T>*);
	void printPostOrder(Node<T>*);
	void destroy(Node<T>*);
	int height(Node<T>*);
	int max(int, int);
	void insert(Node<T>*&, T&);
	bool search(Node<T>*, T&);
	T findMax(Node<T>*, T&);
	T findMin(Node<T>*, T&);
	void deletenode(Node<T>*&, T&);
};

template <class T>
BinarySearchTree<T>::BinarySearchTree() {
	root = NULL;
}

template <class T>
void BinarySearchTree<T>::printInOrder(Node<T>* p) {
	if (p != NULL) {
		printInOrder(p->left);
		cout << p->data << " ";
		printInOrder(p->right);
	}
}

template <class T>
void BinarySearchTree<T>::printPreOrder(Node<T>* p) {
	if (p != NULL) {
		cout << p->data << " ";
		printPreOrder(p->left);
		printPreOrder(p->right);
	}
}

template <class T>
void BinarySearchTree<T>::printPostOrder(Node<T>* p) {
	if (p != NULL) {
		printPostOrder(p->left);
		printPostOrder(p->right);
		cout << p->data << " ";
	}
}
template <class T>
int BinarySearchTree<T>::max(int x, int y) {
	if (x > y)
		return x;
	return y;
}

template <class T>
int BinarySearchTree<T>::height(Node<T>* p) {
	if (p != NULL) {
		return 1 + max(height(p->left), height(p->right));
	}
	return -1;
}

template <class T>
void BinarySearchTree<T>::destroy(Node<T>* p) {
	if (p != NULL) {
		destroy(p->left);
		destroy(p->right);
		delete p;
		p = NULL;
	}
}

template <class T>
void BinarySearchTree<T>::insert(Node<T>*& p, T& item) {
	if (p == NULL) {
		p = new Node<T>;
		p->data = item;
		p->left = p->right = NULL;
	}
	else if (item < p->data) {
		insert(p->left, item);
	}
	else {
		insert(p->right, item);
	}
}

template <class T>
bool BinarySearchTree<T>::search(Node<T>* p, T& item) {
	if (p == NULL)
		return false;
	else if (item < p->data)
		return search(p->left, item);
	else if (item > p->data)
		return search(p->right, item);
	return true;
}

template <class T>
T BinarySearchTree<T>::findMax(Node<T>* p, T& e) {
	if (p == NULL)
		return e;
	else if (p->right == NULL)
		return p->data;
	else
		return findMax(p->right, e);
}

template <class T>
T BinarySearchTree<T>::findMin(Node<T>* p, T& e) {
	if (p == NULL)
		return e;
	else if (p->left == NULL)
		return p->data;
	else
		return findMin(p->left, e);
}

template <class T>
void BinarySearchTree<T>::deletenode(Node<T>*& p, T& item) {
	//item not found, do nothing
	if (p == NULL)
		return;
	else if (item < p->data)	//item is on the left subtree
		deletenode(p->left, item);
	else if (item > p->data)	//item is on the right subtree
		deletenode(p->right, item);
	else {//item is equal to data,  it is found
		if (p->left != NULL && p->right != NULL) {// with two children
			int e = -1;
			p->data = findMax(p->left, e);
			deletenode(p->left, p->data);
		}
		else {
			Node<T>* old = p;
			if (p->left != NULL)
				p = p->left;
			else
				p = p->right;

			delete old;
		}
	}
}

#endif /* BINARYSEARCHTREE_H_ */

