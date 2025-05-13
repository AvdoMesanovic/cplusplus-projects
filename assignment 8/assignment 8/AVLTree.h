//*****************************************************************************************************
//
//		File:					AVLTree.h
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #8
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-01
//
//		Due:					November 6th, 2023
//			
//*****************************************************************************************************

#ifndef AVLTREE_H
#define AVLTREE_H

//*****************************************************************************************************

#include "Node.h"
#include <iostream>

//*****************************************************************************************************

template <typename T>
class AVLTree
{
private:
	Node<T>* root;
	void rotateLeft(Node<T>*& k1);
	void rotateRight(Node<T>*& k1);
	void updatebFactors(Node<T>* r);
	int getBalance(Node<T>* r) const;
	void destroyRec(Node<T>*& r);
	void insertRec(Node<T>*& r, const T& item);
	void inorderRec(Node<T>* r, std::ostream& os) const;
	void inorderWriteRec(Node<T>* r, std::ostream& os) const;
	void preorderRec(Node<T>* r, std::ostream& os) const;
	void postorderRec(Node<T>* r, std::ostream& os) const;
	T* searchRec(Node<T>* r, const T& item) const;
	int max(int a, int b) const;
	int heightRec(Node<T>* r) const;
public:
	AVLTree();
	~AVLTree();
	void destroy();
	void insert(const T& item);
	void inorder(std::ostream& os = std::cout) const;
	void inorderWrite(std::ostream& os) const;
	void preorder(std::ostream& os = std::cout) const;
	void postorder(std::ostream& os = std::cout) const;
	T* search(const T& item) const;
	int height() const;
};

//*****************************************************************************************************

template<typename T>
void AVLTree<T>::rotateLeft(Node<T>*& k1)
{
	Node<T>* k2 = k1->right;
	k1->right = k2->left;
	k2->left = k1;
	k1 = k2;
}

//*****************************************************************************************************

template<typename T>
void AVLTree<T>::rotateRight(Node<T>*& k1)
{
	Node<T>* k2 = k1->left;
	k1->left = k2->right;
	k2->right = k1;
	k1 = k2;
}

//*****************************************************************************************************

template<typename T>
void AVLTree<T>::updatebFactors(Node<T>* r)
{
	if (r != nullptr)
	{
		r->bfactor = getBalance(r);
		updatebFactors(r->left);
		updatebFactors(r->right);
	}
}

//*****************************************************************************************************

template<typename T>
int AVLTree<T>::getBalance(Node<T>* r) const
{
	int balance;

	if (r == nullptr)
	{
		balance = 0;
	}
	else
	{
		balance = heightRec(r->left) - heightRec(r->right);
	}

	return balance;
}

//*****************************************************************************************************

template <typename T>
void AVLTree<T>::destroyRec(Node<T>*& r)
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

template<typename T>
void AVLTree<T>::insertRec(Node<T>*& r, const T& item)
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
		else
		{
			insertRec(r->right, item);
		}
	}

	r->bfactor = getBalance(r);

	if (r->bfactor > 1)
	{
		if (r->left->bfactor > 0)
		{
			rotateRight(r);
		}
		else
		{
			rotateLeft(r->left);
			rotateRight(r);
		}
		updatebFactors(r);
	}
	else if (r->bfactor < -1)
	{
		if (r->right->bfactor < 0)
		{
			rotateLeft(r);
		}
		else
		{
			rotateRight(r->right);
			rotateLeft(r);
		}

		updatebFactors(r);
	}
}

//*****************************************************************************************************

template <typename T>
void AVLTree<T>::inorderRec(Node<T>* r, std::ostream& os) const
{
	if (r != nullptr)
	{
		inorderRec(r->left, os);
		std::cout << "(balance factor is " << r->bfactor << ")" << std::endl;
		os << r->value << std::endl;
		inorderRec(r->right, os);
	}
}

//*****************************************************************************************************

template <typename T>
void AVLTree<T>::inorderWriteRec(Node<T>* r, std::ostream& os) const
{
	if (r != nullptr)
	{
		inorderWriteRec(r->left, os);
		os << r->value << std::endl;
		inorderWriteRec(r->right, os);
	}
}

//*****************************************************************************************************

template <typename T>
void AVLTree<T>::preorderRec(Node<T>* r, std::ostream& os) const
{
	if (r != nullptr)
	{
		std::cout << "(balance factor is " << r->bfactor << ")" << std::endl;
		os << r->value << std::endl;
		preorderRec(r->left, os);
		preorderRec(r->right, os);
	}
}

//*****************************************************************************************************

template <typename T>
void AVLTree<T>::postorderRec(Node<T>* r, std::ostream& os) const
{
	if (r != nullptr)
	{
		postorderRec(r->left, os);
		postorderRec(r->right, os);
		std::cout << "(balance factor is " << r->bfactor << ")" << std::endl;
		os << r->value << std::endl;
	}
}

//*****************************************************************************************************

template <typename T>
T* AVLTree<T>::searchRec(Node<T>* r, const T& item) const
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
int AVLTree<T>::max(int a, int b) const
{
	return (a > b) ? a : b;
}

//*****************************************************************************************************

template <typename T>
int AVLTree<T>::heightRec(Node<T>* r) const
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

template<typename T>
inline AVLTree<T>::AVLTree()
{
	root = nullptr;
}

//*****************************************************************************************************

template<typename T>
inline AVLTree<T>::~AVLTree()
{
	destroyRec(root);
}

//*****************************************************************************************************

template <typename T>
inline void AVLTree<T>::destroy()
{
	destroyRec(root);
}

//*****************************************************************************************************

template<typename T>
inline void AVLTree<T>::insert(const T& item)
{
	insertRec(root, item);
}

//*****************************************************************************************************

template <typename T>
inline void AVLTree<T>::inorder(std::ostream& os) const
{
	inorderRec(root, os);
}

//*****************************************************************************************************

template <typename T>
inline void AVLTree<T>::inorderWrite(std::ostream& os) const
{
	inorderWriteRec(root, os);
}

//*****************************************************************************************************

template <typename T>
inline void AVLTree<T>::preorder(std::ostream& os) const
{
	preorderRec(root, os);

}

//*****************************************************************************************************

template <typename T>
inline void AVLTree<T>::postorder(std::ostream& os) const
{
	postorderRec(root, os);
}

//*****************************************************************************************************

template <typename T>
inline T* AVLTree<T>::search(const T& item) const
{
	return searchRec(root, item);
}

//*****************************************************************************************************

template <typename T>
inline int AVLTree<T>::height() const
{
	return heightRec(root);
}

//*****************************************************************************************************

#endif