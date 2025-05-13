//*****************************************************************************************************
//
//		File:					BinarySearchTree.h
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #6
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-01
//
//		Due:					October 9th, 2023
//		
//*****************************************************************************************************

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

//*****************************************************************************************************

#include "Node.h"
#include <iostream>

//*****************************************************************************************************

template <typename T>
class BinarySearchTree
{
private:
	Node<T>* root;

	void destroyRec(Node<T>*& r);
	void insertRec(Node<T>*& r, const T& item) const;
	void inorderRec(Node<T>* r, std::ostream& os) const;
	void preorderRec(Node<T>* r, std::ostream& os) const;
	void postorderRec(Node<T>* r, std::ostream& os) const;
	T* searchRec(Node<T>* r, const T& item) const;
	int max(int a, int b) const;
	int heightRec(Node<T>* r) const;
public:
	BinarySearchTree();
	~BinarySearchTree();
	void destroy();
	void insert(const T& item);
	void inorder(std::ostream& os = std::cout) const;
	void preorder(std::ostream& os = std::cout) const;
	void postorder(std::ostream& os = std::cout) const;
	T* search(const T& item) const;
	int height() const;
};

//*****************************************************************************************************

template <typename T>
void BinarySearchTree<T>::destroyRec(Node<T>*& r)
{
	if (r != nullptr)
	{
		destroyRec(r->left);
		destroyRec(r->right);
		delete r;
		r = nullptr;
	}
}

//*****************************************************************************************************

template <typename T>
void BinarySearchTree<T>::insertRec(Node<T>*& r, const T& item) const
{
	if (r == nullptr)
	{
		r = new Node<T>;
		r->value = item;
	}
	else
	{
		if (item < r->value)
		{
			insertRec(r->left, item);
		}
		else if (item > r->value)
		{
			insertRec(r->right, item);
		}
		else
		{
			std::cout << "duplication, insert not allowed";
		}
	}
}

//*****************************************************************************************************

template <typename T>
void BinarySearchTree<T>::inorderRec(Node<T>* r, std::ostream& os) const
{
	if (r != nullptr)
	{
		inorderRec(r->left, os);
		os << r->value << std::endl;
		inorderRec(r->right, os);
	}
}

//*****************************************************************************************************

template <typename T>
void BinarySearchTree<T>::preorderRec(Node<T>* r, std::ostream& os) const
{
	if (r != nullptr)
	{
		os << r->value << std::endl;
		preorderRec(r->left, os);
		preorderRec(r->right, os);
	}
}

//*****************************************************************************************************

template <typename T>
void BinarySearchTree<T>::postorderRec(Node<T>* r, std::ostream& os) const
{
	if (r != nullptr)
	{
		postorderRec(r->left, os);
		postorderRec(r->right, os);
		os << r->value << std::endl;
	}
}

//*****************************************************************************************************

template <typename T>
T* BinarySearchTree<T>::searchRec(Node<T>* r, const T& item) const
{
	T* result;

	if (r == nullptr)
	{
		result = nullptr;
	}
	else if (item < r->value)
	{
		result = searchRec(r->left, item);
	}
	else if (item > r->value)
	{
		result = searchRec(r->right, item);
	}
	else
	{
		result = new T(r->value);
	}

	return result;
}

//*****************************************************************************************************

template <typename T>
int BinarySearchTree<T>::max(int a, int b) const
{
	return (a > b) ? a : b;
}

//*****************************************************************************************************

template <typename T>
int BinarySearchTree<T>::heightRec(Node<T>* r) const
{
	if (r == nullptr)
	{
		return 0;
	}
	else
	{
		return 1 + max(heightRec(r->left), heightRec(r->right));
	}
}

//*****************************************************************************************************

template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	root = nullptr;
}

//*****************************************************************************************************

template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
	destroyRec(root);
}

//*****************************************************************************************************

template <typename T>
void BinarySearchTree<T>::destroy()
{
	destroyRec(root);
}

//*****************************************************************************************************

template <typename T>
void BinarySearchTree<T>::insert(const T& item)
{
	insertRec(root, item);
}

//*****************************************************************************************************

template <typename T>
void BinarySearchTree<T>::inorder(std::ostream& os) const
{
	inorderRec(root, os);
}

//*****************************************************************************************************

template <typename T>
void BinarySearchTree<T>::preorder(std::ostream& os) const
{
	preorderRec(root, os);

}

//*****************************************************************************************************

template <typename T>
void BinarySearchTree<T>::postorder(std::ostream& os) const
{
	postorderRec(root, os);
}

//*****************************************************************************************************

template <typename T>
T* BinarySearchTree<T>::search(const T& item) const
{
	return searchRec(root, item);
}

//*****************************************************************************************************

template <typename T>
int BinarySearchTree<T>::height() const
{
	return heightRec(root);
}

//*****************************************************************************************************

#endif