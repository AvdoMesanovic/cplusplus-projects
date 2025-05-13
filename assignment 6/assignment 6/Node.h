//*****************************************************************************************************
//
//		File:					Node.h
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #6
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-01
//
//		Due:					September 25th, 2023
//			
//*****************************************************************************************************

#ifndef NODE_H
#define NODE_H

//*****************************************************************************************************

template <typename T>
struct Node
{
	T value;
	Node<T>* left;
	Node<T>* right;

	Node();
	Node(const T& v, Node<T>* l = nullptr, Node<T>* r = nullptr);
};

//*****************************************************************************************************

template <typename T>
Node<T>::Node()
{
	left = nullptr;
	right = nullptr;
}

//*****************************************************************************************************

template <typename T>
Node<T>::Node(const T& v, Node<T>* l, Node<T>* r)
{
	value = v;
	left = l;
	right = r;
}

//*****************************************************************************************************

#endif