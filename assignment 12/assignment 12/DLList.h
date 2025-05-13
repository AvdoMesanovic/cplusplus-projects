//*****************************************************************************************************
//
//		File:					DLList.h
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
//		Other files required:
//			1. Node.h - definition of the Node structure
//			
//*****************************************************************************************************

#ifndef DLList_H
#define DLList_H

//*****************************************************************************************************

#include<iostream>
#include <new>
#include "Node.h"

//*****************************************************************************************************

template <typename TYPE>
class DLList
{
private:
	Node<TYPE>* front;
	Node<TYPE>* rear;

public:
	DLList();
	~DLList();
	bool insert(const TYPE& dataIn);
	bool remove(TYPE& dataOut);
	bool retrieve(TYPE& dataOut) const;
	bool viewFront(TYPE& dataOut) const;
	bool viewRear(TYPE& dataOut) const;
	void display() const;
	void displayReverse() const;
	int getNumValues() const;
	bool isEmpty() const;
	bool isFull() const;
};

//*****************************************************************************************************

template<typename TYPE>
DLList<TYPE>::DLList()
{
	front = nullptr;
	rear = nullptr;
}

//*****************************************************************************************************

template<typename TYPE>
DLList<TYPE>::~DLList()
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
bool DLList<TYPE>::insert(const TYPE& dataIn)
{
	bool success = false;
	Node<TYPE>* pBefore = nullptr;
	Node<TYPE>* pAfter = front;
	Node<TYPE>* pNew;

	while ((pAfter) && (pAfter->data < dataIn))
	{
		pAfter = pAfter->next;
	}

	if (pAfter)
	{
		pBefore = pAfter->prev;
	}
	else
	{
		pBefore = rear;
	}

	pNew = new(nothrow) Node<TYPE>(dataIn, pAfter, pBefore);

	if (pNew)
	{
		if (pBefore)
		{
			pBefore->next = pNew;
		}
		else
		{
			front = pNew;
		}

		if (pAfter)
		{
			pAfter->prev = pNew;
		}
		else
		{
			rear = pNew;
		}

		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool DLList<TYPE>::remove(TYPE& dataOut)
{
	bool success = false;
	Node<TYPE>* pDel = front;

	while ((pDel) && (pDel->data < dataOut))
	{
		pDel = pDel->next;
	}

	if ((pDel) && (pDel->data == dataOut))
	{
		dataOut = pDel->data;
	}

	if (pDel->prev)
	{
		pDel->prev->next = pDel->next;
	}
	else
	{
		front = pDel->next;
	}

	if (pDel->next)
	{
		pDel->next->prev = pDel->prev;
	}
	else
	{
		rear = pDel->prev;
	}

	delete pDel;
	success = true;

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool DLList<TYPE>::retrieve(TYPE& dataOut) const
{
	bool success = false;
	Node<TYPE>* pTemp = front;

	while ((pTemp) && (pTemp->data < dataOut))
	{
		pTemp = pTemp->next;
	}

	if ((pTemp) && (pTemp->data == dataOut))
	{
		dataOut = pTemp->data;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool DLList<TYPE>::viewFront(TYPE& dataOut) const
{
	bool success = false;

	if (front)
	{
		dataOut = front->data;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool DLList<TYPE>::viewRear(TYPE& dataOut) const
{
	bool success = false;

	if (rear)
	{
		dataOut = rear->data;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
void DLList<TYPE>::display() const
{
	Node<TYPE>* pTemp = front;

	while (pTemp)
	{
		cout << pTemp->data << " ";
		pTemp = pTemp->next;
	}
}

//*****************************************************************************************************

template<typename TYPE>
void DLList<TYPE>::displayReverse() const
{
	Node<TYPE>* pTemp = rear;

	while (pTemp)
	{
		cout << pTemp->data << " ";
		pTemp = pTemp->prev;
	}
}

//*****************************************************************************************************

template<typename TYPE>
int DLList<TYPE>::getNumValues() const
{
	int numValues = 0;
	Node<TYPE>* pTemp = front;

	while (pTemp)
	{
		numValues++;
		pTemp = pTemp->next;
	}

	return numValues;
}

//*****************************************************************************************************

template<typename TYPE>
bool DLList<TYPE>::isEmpty() const
{
	return (front == nullptr);
}

//*****************************************************************************************************

template<typename TYPE>
bool DLList<TYPE>::isFull() const
{
	bool success = true;
	Node<TYPE>* pNew = new(nothrow) Node<TYPE>;

	if (pNew)
	{
		delete pNew;
		success = false;
	}

	return success;
}

//*****************************************************************************************************

#endif