//*****************************************************************************************************
//
//		File:					AList.h
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #5
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-01
//
//		Due:					October 2nd, 2023
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
	void binarySearchRec(const TYPE a[], int first, int last, const TYPE& item, bool& found, int& loc) const;
public:
	AList(int s = 10);
	~AList();
	AList(const AList<TYPE>& a);
	void insert(const TYPE& item);
	bool binarySearch(const TYPE& item, int& loc) const;
	bool remove(const TYPE& item);
	bool removeRange(int a, int b);
	bool isEmpty() const;
	bool isFull() const;
	int listSize() const;
	void print(std::ostream& output) const;
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
void AList<TYPE>::binarySearchRec(const TYPE a[], int first, int last, const TYPE& item, bool& found, int& loc) const
{
	if (first > last)
	{
		found = false;
	}
	else
	{
		loc = (first + last) / 2;

		if (item > a[loc])
		{
			binarySearchRec(a, first, loc - 1, item, found, loc);
		}
		else if (a[loc] > item)
		{
			binarySearchRec(a, loc + 1, last, item, found, loc);
		}
		else
		{
			found = true;
		}
	}
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

	int insertIndex = numValues;

	while (insertIndex > 0 && item > list[insertIndex - 1])
	{
		list[insertIndex] = list[insertIndex - 1];
		--insertIndex;
	}

	list[insertIndex] = item;
	numValues += 1;
}

//*****************************************************************************************************

template<typename TYPE>
bool AList<TYPE>::binarySearch(const TYPE& item, int& loc) const
{
	bool found = false;
	binarySearchRec(list, 0, numValues - 1, item, found, loc);

	return found;
}

//*****************************************************************************************************

template<typename TYPE>
bool AList<TYPE>::remove(const TYPE& item)
{
	int loc;

	if (binarySearch(item, loc))
	{
		for (int i = loc; i < numValues - 1; i++)
		{
			list[i] = list[i + 1];
		}
		numValues--;
		return true;
	}

	return false;
}

//*****************************************************************************************************

template<typename TYPE>
bool AList<TYPE>::removeRange(int a, int b)
{
	if (a < 0 || b >= numValues || a > b)
	{
		return false;
	}

	int elemsRemoving = b - a + 1;

	for (int i = a; i < numValues - elemsRemoving; i++)
	{
		list[i] = list[i + elemsRemoving];
	}

	numValues -= elemsRemoving;
	return true;
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
void AList<TYPE>::print(std::ostream& output) const
{
	if (numValues > 0)
	{
		for (int i = 0; i < numValues; i++)
		{
			output << "[" << i << "]" << list[i];

			if (i < numValues - 1)
			{
				output << " ";
			}
		}
	}
}

//*****************************************************************************************************

#endif