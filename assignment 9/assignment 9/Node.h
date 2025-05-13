//*****************************************************************************************************
//
//		File:					Node.h
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #9
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-01
//
//		Due:					November 13th, 2023
//			
//*****************************************************************************************************

#ifndef NODE_H
#define NODE_H

//*****************************************************************************************************

template <typename T>
struct Node
{
	T value;
	double frequency;
	Node<T>* left;
	Node<T>* right;

	Node();
	Node(const T& v, double f, Node<T>* l = nullptr, Node<T>* r = nullptr);
};

//*****************************************************************************************************

template <typename T>
Node<T>::Node()
{
	frequency = 0;
	left = nullptr;
	right = nullptr;
}

//*****************************************************************************************************

template <typename T>
Node<T>::Node(const T& v, double f, Node<T>* l, Node<T>* r)
{
	value = v;
	frequency = f;
	left = l;
	right = r;
}

//*****************************************************************************************************

#endif