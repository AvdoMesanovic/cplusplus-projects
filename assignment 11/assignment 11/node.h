//*****************************************************************************************************
//
//		File:					node.h
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #11
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-01
//
//		Due:					April 27th, 2023
//
//
//		This program uses a templated Stack and a templated Queue to determine if a character array
//      string is a valid palindrome.
// 
//		Other files required: N/A
//			
//*****************************************************************************************************

#ifndef NODE_H
#define NODE_H

//*****************************************************************************************************

template <typename TYPE>
struct Node
{
	TYPE data;
	Node<TYPE>* next;

	Node();
	Node(const TYPE& d, Node<TYPE>* n = nullptr);
};

//*****************************************************************************************************

template <typename TYPE>
Node<TYPE>::Node()
{
	data = 0;
	next = nullptr;
}

//*****************************************************************************************************

template <typename TYPE>
Node<TYPE>::Node(const TYPE& d, Node<TYPE>* n)
{
	data = d;
	next = n;
}

//*****************************************************************************************************

#endif
