//*****************************************************************************************************
//
//		File:					node.h
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #4
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-01
//
//		Due:					September 25th, 2023
//
//
//		This program explores the Linked List data structure and utilizes several functions 
//      to employ it.
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