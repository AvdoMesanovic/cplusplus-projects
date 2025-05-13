//*****************************************************************************************************
//
//		File:					queue.h
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
//		Other files required: 
//			1. Node.h - definition of the Node structure
//			
//*****************************************************************************************************

#ifndef QUEUE_H
#define QUEUE_H

//*****************************************************************************************************

#include <new>
#include "Node.h"

//*****************************************************************************************************

template <typename TYPE>
class Queue
{
private:
	Node<TYPE>* front;
	Node<TYPE>* back;
	int numValues;

public:
	Queue();
	~Queue();
	bool enqueue(const TYPE& dataIn);
	bool dequeue(TYPE& dataOut);
	bool viewFront(TYPE& dataOut) const;
	bool viewRear(TYPE& dataOut) const;
	int getNumValues() const;
	bool isEmpty() const;
	bool isFull() const;
};

//*****************************************************************************************************

template<typename TYPE>
Queue<TYPE>::Queue()
{
	front = nullptr;
	back = nullptr;
	numValues = 0;
}

//*****************************************************************************************************

template<typename TYPE>
Queue<TYPE>::~Queue()
{
	Node<TYPE>* pTemp;

	while (front)
	{
		pTemp = front;
		front = front->next;
		delete pTemp;
	}

	back = nullptr;
	numValues = 0;
}

//*****************************************************************************************************

template<typename TYPE>
bool Queue<TYPE>::enqueue(const TYPE& dataIn)
{
	bool success = false;
	Node<TYPE>* pNew;

	pNew = new(nothrow) Node<TYPE>(dataIn);

	if (pNew)
	{
		if (back)
		{
			back->next = pNew;
		}
		else
		{
			front = pNew;
		}

		back = pNew;
		numValues += 1;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool Queue<TYPE>::dequeue(TYPE& dataOut)
{
	bool success = false;
	Node<TYPE>* pDel = front;

	if (front)
	{
		dataOut = front->data;
		front = front->next;
		delete pDel;
		numValues -= 1;
		success = true;

		if (numValues == 0)
		{
			back = nullptr;
		}
	}

	return success;
}

//*****************************************************************************************************


template<typename TYPE>
bool Queue<TYPE>::viewFront(TYPE& dataOut) const
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
bool Queue<TYPE>::viewRear(TYPE& dataOut) const
{
	bool success = false;

	if (back)
	{
		dataOut = back->data;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
int Queue<TYPE>::getNumValues() const
{
	return numValues;
}

//*****************************************************************************************************

template<typename TYPE>
bool Queue<TYPE>::isFull() const
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

template<typename TYPE>
bool Queue<TYPE>::isEmpty() const
{
	return (front == nullptr);
}

//*****************************************************************************************************

#endif