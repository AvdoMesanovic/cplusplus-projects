//*****************************************************************************************************
//
//		File:					SortedList.h
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #10
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-01
//
//		Due:					November 20th, 2023
//			
//*****************************************************************************************************

#ifndef SORTEDLIST_H
#define SORTEDLIST_H

//*****************************************************************************************************

#include <iostream>
#include <stdlib.h>
#include <time.h>

//*****************************************************************************************************

template <typename T>
class SortedList
{
private:
	T* elements;
	int capacity;
	int size;
	int partition(T* elems, int low, int high);
	int partitionD(T* elems, int low, int high);
	void quickSortARec(T* elems, int low, int high);
	void quickSortDRec(T* elems, int low, int high);
public:
	SortedList(int c = 10);
	~SortedList();
	void insert(const T& item);
	void randomise();
	void selectionSortA();
	void selectionSortD();
	void quickSortA();
	void quickSortD();
	void display() const;
};

//*****************************************************************************************************

template <typename T>
int SortedList<T>::partition(T* elems, int low, int high)
{
	T pivot = elems[(low + high) / 2];
	std::swap(elems[low], elems[(low + high) / 2]);
	int smallIndex = low;
	int index;

	for (int i = low + 1; i <= high; i++)
	{
		index = i;

		if (pivot > elems[index])
		{
			smallIndex++;
			std::swap(elems[smallIndex], elems[index]);
		}
	}

	std::swap(elems[low], elems[smallIndex]);
	return smallIndex;
}

//*****************************************************************************************************

template <typename T>
int SortedList<T>::partitionD(T* elems, int low, int high)
{
	T pivotValue = elems[(low + high) / 2];
	std::swap(elems[low], elems[(low + high) / 2]);
	int largeIndex = low;
	int index;

	for (int i = low + 1; i <= high; i++)
	{
		index = i;

		if (pivotValue < elems[index])
		{
			largeIndex++;
			std::swap(elems[largeIndex], elems[index]);
		}
	}

	std::swap(elems[low], elems[largeIndex]);
	return largeIndex;
}

//*****************************************************************************************************

template <typename T>
void SortedList<T>::quickSortARec(T* elems, int low, int high)
{
	if (low < high)
	{
		int pivotLoc = partition(elems, low, high);
		quickSortARec(elems, low, pivotLoc - 1);
		quickSortARec(elems, pivotLoc + 1, high);
	}
}

//*****************************************************************************************************

template <typename T>
void SortedList<T>::quickSortDRec(T* elems, int low, int high)
{
	if (low < high)
	{
		int pivotLoc = partitionD(elems, low, high);
		quickSortDRec(elems, low, pivotLoc - 1);
		quickSortDRec(elems, pivotLoc + 1, high);
	}
}

//*****************************************************************************************************

template<typename T>
inline SortedList<T>::SortedList(int c)
{
	capacity = c;
	elements = new T[capacity];
	size = 0;
}

//*****************************************************************************************************

template<typename T>
inline SortedList<T>::~SortedList()
{
	capacity = 0;
	delete[]elements;
	size = 0;
}

//*****************************************************************************************************

template<typename T>
void SortedList<T>::insert(const T& item)
{
	if (capacity == size)
	{
		T* newElements;
		int newCapacity;

		newCapacity = capacity + 10;
		newElements = new(std::nothrow) T[newCapacity];

		if (newCapacity)
		{
			for (int i = 0; i < size; i++)
			{
				newElements[i] = elements[i];
			}

			delete[]elements;
			elements = newElements;
			capacity = newCapacity;
		}
	}

	elements[size] = item;
	size++;
}

//*****************************************************************************************************

template<typename T>
void SortedList<T>::randomise()
{
	srand(time(0));

	for (int i = size - 1; i > 0; --i)
	{
		int j = rand() % (i + 1);
		std::swap(elements[i], elements[j]);
	}
}

//*****************************************************************************************************

template <typename T>
void SortedList<T>::selectionSortA()
{
	for (int i = 0; i < size - 1; i++)
	{
		int minIndex = i;

		for (int j = i + 1; j < size; j++)
		{
			if (elements[j] < elements[minIndex])
			{
				minIndex = j;
			}
		}

		T temp = elements[i];
		elements[i] = elements[minIndex];
		elements[minIndex] = temp;
	}
}

//*****************************************************************************************************

template <typename T>
void SortedList<T>::selectionSortD()
{
	for (int i = 0; i < size - 1; i++)
	{
		int maxIndex = i;
		for (int j = i + 1; j < size; j++)
		{
			if (elements[j] > elements[maxIndex])
				maxIndex = j;
		}

		T temp = elements[i];
		elements[i] = elements[maxIndex];
		elements[maxIndex] = temp;
	}
}

//*****************************************************************************************************

template <typename T>
void SortedList<T>::quickSortA()
{
	quickSortARec(elements, 0, size - 1);
}

//*****************************************************************************************************

template <typename T>
void SortedList<T>::quickSortD()
{
	quickSortDRec(elements, 0, size - 1);
}

//*****************************************************************************************************

template <class T>
void SortedList<T>::display() const
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << elements[i] << std::endl;
	}
}

//*****************************************************************************************************

#endif
