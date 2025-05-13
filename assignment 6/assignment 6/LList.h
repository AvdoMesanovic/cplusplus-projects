//*****************************************************************************************************
//
//		File:					LList.h
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #6
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-01
//
//		Due:					March 24th, 2023
//
//
//		This program explores the Linked List data structure and utilizes several functions 
//      to employ it.
//	
//		Other files required: 
//			1. Node.h - definition of the Node structure
//			
//*****************************************************************************************************

#ifndef LLIST_H
#define LLIST_H

//*****************************************************************************************************

#include<iostream>
#include <new>
#include "Node.h"

//*****************************************************************************************************

template <typename TYPE>
class LList
{
private:
	Node<TYPE>* front;

public:
	LList();
	~LList();
	bool insert(const TYPE& dataIn);
	bool remove(TYPE& dataOut);
	bool retrieve(TYPE& dataOut) const; 
	bool viewFront(TYPE& dataOut) const;
	bool viewRear(TYPE& dataOut) const;
	void display() const;
	int getNumValues() const;
	bool isEmpty() const;
	bool isFull() const;
};

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
bool LList<TYPE>::insert(const TYPE& dataIn)
{
	bool success = false;
	Node<TYPE>* pBefore = nullptr;
	Node<TYPE>* pAfter = front;
	Node<TYPE>* pNew;

	while ((pAfter) && (pAfter->data < dataIn))
	{
		pBefore = pAfter;
		pAfter = pAfter->next;
	}

	pNew = new(nothrow) Node<TYPE>(dataIn, pAfter);

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

		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool LList<TYPE>::remove(TYPE& dataOut)
{
	bool success = false;
	Node<TYPE>* pTemp = front;
	Node<TYPE>* pBefore = nullptr;

	while ((pTemp) && (pTemp->data < dataOut))
	{
		pBefore = pTemp;
		pTemp = pTemp->next;
	}

	if ((pTemp) && (pTemp->data == dataOut))
	{
		dataOut = pTemp->data;

		if (pBefore)
		{
			pBefore->next = pTemp->next;
		}
		else
		{
			front = pTemp->next;
		}

		delete pTemp;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool LList<TYPE>::retrieve(TYPE& dataOut) const
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
bool LList<TYPE>::viewFront(TYPE& dataOut) const
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
bool LList<TYPE>::viewRear(TYPE& dataOut) const
{
	bool success = false;
	Node<TYPE>* pTemp = front;
	
	while ((pTemp) && (pTemp->next))
	{
		pTemp = pTemp->next;
	}

	if (pTemp)
	{
		dataOut = pTemp->data;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
void LList<TYPE>::display() const
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
int LList<TYPE>::getNumValues() const
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
bool LList<TYPE>::isEmpty() const
{
	return (front == nullptr);
}

//*****************************************************************************************************

template<typename TYPE>
bool LList<TYPE>::isFull() const
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