//*****************************************************************************************************
//
//		File:					Node.h
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

#ifndef NODE_H
#define NODE_H

//*****************************************************************************************************

template <typename T>
struct Node
{
	T value;
	int bfactor;
	Node<T>* left;
	Node<T>* right;

	Node();
	Node(const T& v, int b, Node<T>* l = nullptr, Node<T>* r = nullptr);
};

//*****************************************************************************************************

template <typename T>
Node<T>::Node()
{
	bfactor = 0;
	left = nullptr;
	right = nullptr;
}

//*****************************************************************************************************

template <typename T>
Node<T>::Node(const T& v, int b, Node<T>* l, Node<T>* r)
{
	value = v;
	bfactor = b;
	left = l;
	right = r;
}

//*****************************************************************************************************

#endif