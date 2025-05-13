//*****************************************************************************************************
//
//		File:					AList.h
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #5
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-01
//
//		Due:					March 2nd, 2023
//
//
//		This program explores the List ADT and utilizes several functions to employ it.
//	
//		Other files required: 
//			1.	driverAList.cpp - a driver to prove the correctness of the AList class template
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
	int capacity;
	TYPE* list;
	int numValues;

	bool _resize();

public:
	AList(int cap = 5);
	~AList();
	bool insertFront(const TYPE& dataIn);
	bool insertBack(const TYPE& dataIn);
	bool insertAtIndex(const TYPE& dataIn, int index);
	bool removeFront(TYPE& dataOut);
	bool removeBack(TYPE& dataOut);
	bool removeAtIndex(TYPE& dataOut, int index);
	bool remove(TYPE& dataOut); 
	bool retrieveFront(TYPE& dataOut) const;
	bool retrieveBack(TYPE& dataOut) const;
	bool retrieveAtIndex(TYPE& dataOut, int index) const;
	bool retrieve(TYPE& dataOut) const;
	bool updateFront(const TYPE& dataIn);
	bool updateBack(const TYPE& dataIn);
	bool updateAtIndex(const TYPE& dataIn, int index);
	bool update(const TYPE& dataIn);
	bool display() const;
	bool getSmallest(TYPE& dataOut) const;
	int getCapacity() const;
	int getNumValues() const;
	bool isEmpty() const;
	bool isFull() const;
	bool clear();
};

//*****************************************************************************************************

template<typename TYPE>
bool AList<TYPE>::_resize()
{
	bool success = false;
	TYPE* newList;
	int newCapacity;

	newCapacity = capacity + (capacity / 2);
	newList = new(nothrow) TYPE[newCapacity];

	if (newList)
	{
		for (int i = 0; i < numValues; i++)
		{
			newList[i] = list[i];
		}

		delete[]list;
		list = newList;
		capacity = newCapacity;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
AList<TYPE>::AList(int cap)
{
	if (cap >= 2)
	{
		capacity = cap;
		list = new TYPE[capacity];
		numValues = 0;
	}
}

//*****************************************************************************************************

template<typename TYPE>
AList<TYPE>::~AList()
{
	capacity = 0;
	delete[]list;
	numValues = 0;
	list = nullptr;
}

//*****************************************************************************************************
template<typename TYPE>
bool AList<TYPE>::insertFront(const TYPE& dataIn)
{
	bool success = true;

	if (numValues == capacity)
	{
		success = _resize();
	}

	if (success)
	{
		for (int i = numValues; i > 0; i--)
		{
			list[i] = list[i - 1];
		}

		list[0] = dataIn;
		numValues += 1;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool AList<TYPE>::insertBack(const TYPE& dataIn)
{
	bool success = true;

	if (numValues == capacity)
	{
		success = _resize();
	}

	if (success)
	{
		list[numValues] = dataIn;
		numValues += 1;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::insertAtIndex(const TYPE& dataIn, int index)
{
	bool success = false;

	if ((index <= numValues) && (index >= 0))
	{
		success = true;

		if (numValues == capacity)
		{
			success = _resize();
		}

		for (int i = numValues; i > index; i--)
		{
			list[i] = list[i - 1];
		}

		list[index] = dataIn;
		numValues += 1;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool AList<TYPE>::removeFront(TYPE& dataOut)
{
	bool success = false;

	if (numValues > 0)
	{
		dataOut = list[0];
		numValues -= 1;

		if (numValues > 0)
		{
			for (int i = 0; i < numValues; i++)
			{
				list[i] = list[i + 1];
			}
		}

		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool AList<TYPE>::removeBack(TYPE& dataOut)
{
	bool success = false;

	if (numValues > 0)
	{
		dataOut = list[numValues - 1];
		numValues -= 1;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool AList<TYPE>::removeAtIndex(TYPE& dataOut, int index)
{
	bool success = false;

	if ((index <= numValues) && (index >= 0))
	{
		dataOut = list[index];
		numValues -= 1;

		for (int i = index; i < numValues; i++)
		{
			list[i] = list[i + 1];
		}

		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool AList<TYPE>::remove(TYPE& dataOut)
{
	bool success = false;

	if (numValues > 0)
	{
		for (int i = 0; i < numValues; i++)
		{
			if (list[i] == dataOut)
			{
				for (int j = i + 1; j < numValues; j++)
				{
					list[j - 1] = list[j];
				}

				numValues -= 1;
				success = true;
			}
		}
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool AList<TYPE>::retrieveFront(TYPE& dataOut) const
{
	bool success = false;

	if (numValues > 0)
	{
		dataOut = list[0];
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool AList<TYPE>::retrieveBack(TYPE& dataOut) const
{
	bool success = false;

	if (numValues > 0)
	{
		dataOut = list[numValues - 1];
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool AList<TYPE>::retrieveAtIndex(TYPE& dataOut, int index) const
{
	bool success = false;

	if ((index <= numValues) && (index >= 0))
	{
		dataOut = list[index];
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool AList<TYPE>::retrieve(TYPE& dataOut) const
{
	bool success = false;

	if (numValues > 0)
	{
		for (int i = 0; i < numValues; i++)
		{
			if (list[i] == dataOut)
			{
				dataOut = list[i];
				i = numValues;
				success = true;
			}
		}
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool AList<TYPE>::updateFront(const TYPE& dataIn) 
{
	bool success = false;

	if (numValues > 0)
	{
		list[0] = dataIn;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool AList<TYPE>::updateBack(const TYPE& dataIn)
{
	bool success = false;

	if (numValues > 0)
	{
		list[numValues - 1] = dataIn;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool AList<TYPE>::updateAtIndex(const TYPE& dataIn, int index)
{
	bool success = false;

	if ((index <= numValues) && (index >= 0))
	{
		list[index] = dataIn;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool AList<TYPE>::update(const TYPE& dataIn)
{
	bool success = false;

	if (numValues > 0)
	{
		for (int i = 0; i < numValues; i++)
		{
			if (list[i] == dataIn)
			{
				list[i] = dataIn;
				i = numValues;
				success = true;
			}
		}
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool AList<TYPE>::display() const
{
	bool success = false;

	if (numValues > 0)
	{
		for (int i = 0; i < numValues; i++)
		{
			cout << "[" << i << "]" << list[i] << "\t";
		}

		success = true;
	}
	
	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool AList<TYPE>::getSmallest(TYPE& dataOut) const
{
	bool success = false;

	if (numValues > 0)
	{
		dataOut = list[0];

		for (int i = 1; i < numValues; i++)
		{
			if (list[i] < dataOut)
			{
				dataOut = list[i];
			}
		}

		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
int AList<TYPE>::getCapacity() const
{
	return capacity;
}

//*****************************************************************************************************

template<typename TYPE>
int AList<TYPE>::getNumValues() const
{
	return numValues;
}

//*****************************************************************************************************

template<typename TYPE>
bool AList<TYPE>::isEmpty() const
{
	return (numValues == 0);
}

//*****************************************************************************************************

template<typename TYPE>
bool AList<TYPE>::isFull() const
{
	return (numValues == capacity);
}

//*****************************************************************************************************

template<typename TYPE>
bool AList<TYPE>::clear()
{
	numValues = 0;

	return true;
}

//*****************************************************************************************************

#endif