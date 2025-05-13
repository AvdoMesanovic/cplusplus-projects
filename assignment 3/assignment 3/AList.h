//*****************************************************************************************************
//
//		File:					AList.h
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #3
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-01
//
//		Due:					September 18th, 2023
//
//
//		This program explores the List ADT and utilizes several functions to employ it.
//	
//		Other files required: N/A
//			
//*****************************************************************************************************

#ifndef ALIST_H
#define ALIST_H

//*****************************************************************************************************

#include <iostream>
#include <new>

//*****************************************************************************************************

template <typename TYPE>
class AList
{
private:
	int size;
	TYPE* list;
	int numValues;

	void _resize();
	int binarySearchRec(const TYPE a[], int first, int last, const TYPE& item) const;

public:
	AList(int s = 10);
	~AList();
	AList(const AList<TYPE>& a);
	void insert(const TYPE& item);
	bool isEmpty() const;
	bool isFull() const;
	int listSize() const;
	void print() const;
	int binarySearch(const TYPE& item) const;
};

//*****************************************************************************************************

template<typename TYPE>
void AList<TYPE>::_resize()
{
	TYPE* newList;
	int newSize;

	newSize = size + (size + 10);
	newList = new(std::nothrow) TYPE[newSize];

	if (newList)
	{
		for (int i = 0; i < numValues; i++)
		{
			newList[i] = list[i];
		}

		delete[]list;
		list = newList;
		size = newSize;
	}
}

//*****************************************************************************************************

template<typename TYPE>
int AList<TYPE>::binarySearchRec(const TYPE a[], int first, int last, const TYPE& item) const
{
	if (first < last)
	{
		int middle = (first + last) / 2;

		if (a[middle] == item)
		{
			return middle;
		}
		else if (a[middle] > item)
		{
			return binarySearchRec(a, first, middle - 1, item);
		}
		else
		{
			return binarySearchRec(a, middle + 1, last, item);
		}
	}

	return -1;
}

//*****************************************************************************************************

template<typename TYPE>
AList<TYPE>::AList(int s)
{
	if (s >= 2)
	{
		size = s;
		list = new TYPE[size];
		numValues = 0;
	}
}

//*****************************************************************************************************

template<typename TYPE>
AList<TYPE>::~AList()
{
	size = 0;
	delete[]list;
	numValues = 0;
	list = nullptr;
}

//*****************************************************************************************************

template<typename TYPE>
AList<TYPE>::AList(const AList<TYPE>& a)
{
	size = a.size;
	numValues = a.numValues;
	list = new TYPE[size];

	for (int i = 0; i < numValues; ++i)
	{
		list[i] = a.list[i];
	}
}

//*****************************************************************************************************

template<typename TYPE>
void AList<TYPE>::insert(const TYPE& item)
{
	if (numValues == size)
	{
		_resize();
	}

	list[numValues] = item;
	numValues += 1;
}

//*****************************************************************************************************

template<typename TYPE>
inline bool AList<TYPE>::isEmpty() const
{
	return (numValues == 0);
}

//*****************************************************************************************************

template<typename TYPE>
inline bool AList<TYPE>::isFull() const
{
	return (numValues == size);
}

//*****************************************************************************************************

template<typename TYPE>
inline int AList<TYPE>::listSize() const
{
	return numValues;
}

//*****************************************************************************************************

template<typename TYPE>
void AList<TYPE>::print() const
{
	if (numValues > 0)
	{
		for (int i = 0; i < numValues; i++)
		{
			cout << "[" << i << "]" << list[i] << "\t";
		}

	}
}

//*****************************************************************************************************

template<typename TYPE>
int AList<TYPE>::binarySearch(const TYPE& item) const
{
	return binarySearchRec(list, 0, numValues - 1, item);
}

//*****************************************************************************************************

#endif