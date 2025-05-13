//*****************************************************************************************************
//
//		File:					LList.h
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #2
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-01
//
//		Due:					September 11th, 2023
//
//
//		This program explores the Linked List data structure and utilizes several functions 
//      to employ it.
//	
//		Other files required: N/A
//			
//*****************************************************************************************************

#ifndef LLIST_H
#define LLIST_H

//*****************************************************************************************************

#include <iostream>
#include <new>
#include "node.h"

//*****************************************************************************************************

template <typename TYPE>
class LList
{
private:
	Node<TYPE>* front;

	void printListRec(Node<TYPE>* front);
	void insertDescendingOrderRec(Node<TYPE>*& listPtr, const TYPE& item);
	void deleteNoteRec(Node<TYPE>*& listPtr, const TYPE& item);

public:
	LList();
	~LList();
	void printList();
	void insertDescendingOrder(const TYPE& item);
	void deleteNode(const TYPE& item);
};

//*****************************************************************************************************

template <typename TYPE>
void LList<TYPE>::printListRec(Node<TYPE>* front)
{
	if (front != nullptr)
	{
		cout << front->data << endl;
		printListRec(front->next);
	}
}

//*****************************************************************************************************

template <typename TYPE>
void LList<TYPE>::insertDescendingOrderRec(Node<TYPE>*& listPtr, const TYPE& item)
{
	if ((listPtr == nullptr) || (item > listPtr->data))
	{
		Node<TYPE>* tempPtr = listPtr;
		listPtr = new Node<TYPE>;
		listPtr->data = item;
		listPtr->next = tempPtr;
	}
	else
	{
		insertDescendingOrderRec(listPtr->next, item);
	}
}

//*****************************************************************************************************

template <typename TYPE>
void LList<TYPE>::deleteNoteRec(Node<TYPE>*& listPtr, const TYPE& item)
{
	if (listPtr != nullptr)
	{
		if (item == listPtr->data)
		{
			Node<TYPE>* tempPtr = listPtr;
			listPtr = listPtr->next;
			delete tempPtr;
		}
		else
		{
			deleteNoteRec(listPtr->next, item);
		}
	}
}

//*****************************************************************************************************

template<typename TYPE>
LList<TYPE>::LList()
{
	front = nullptr;
}

//*****************************************************************************************************

template<typename TYPE>
LList<TYPE>::~LList()
{
	Node<TYPE>* pTemp;

	while (front)
	{
		pTemp = front;
		front = front->next;
		delete pTemp;
	}
}

//*****************************************************************************************************

template<typename TYPE>
void LList<TYPE>::printList()
{
	printListRec(front);
}

//*****************************************************************************************************

template<typename TYPE>
void LList<TYPE>::insertDescendingOrder(const TYPE& item)
{
	insertDescendingOrderRec(front, item);
}

//*****************************************************************************************************

template<typename TYPE>
void LList<TYPE>::deleteNode(const TYPE& item)
{
	deleteNoteRec(front, item);
}

//*****************************************************************************************************

#endif