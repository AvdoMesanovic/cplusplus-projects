//*****************************************************************************************************
//
//		File:					node.h
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #12
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-01
//
//		Due:					May 5th, 2023
//
//		This program explores the Doubly Linked List data structure and utilizes several
//	    functions to employ it.
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
	Node<TYPE>* prev;

	Node();
	Node(const TYPE& d, Node<TYPE>* n = nullptr, Node<TYPE>* p = nullptr);
};

//*****************************************************************************************************

template <typename TYPE>
Node<TYPE>::Node()
{
	data = 0;
	next = nullptr;
	prev = nullptr;
}

//*****************************************************************************************************

template <typename TYPE>
Node<TYPE>::Node(const TYPE& d, Node<TYPE>* n, Node<TYPE>* p)
{
	data = d;
	next = n;
	prev = p;
}

//*****************************************************************************************************

#endif