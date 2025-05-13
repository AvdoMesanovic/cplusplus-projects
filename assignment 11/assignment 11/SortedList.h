//*****************************************************************************************************
//
//		File:					SortedList.h
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #11
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-01
//
//		Due:					November 29th, 2023
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
	void heapify(T* elems, int n, int root);
	void heapifyD(T* elems, int n, int root);
	void heapSortARec(T* elems, int n);
	void heapSortDRec(T* elems, int n);
public:
	SortedList(int c = 10);
	~SortedList();
	void insert(const T& item);
	void randomise();
	void selectionSortA();
	void selectionSortD();
	void quickSortA();
	void quickSortD();
	void heapSortA();
	void heapSortD();
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

template <typename T>
void SortedList<T>::heapify(T* elems, int n, int root)
{
	int largest = root;
	int left = 2 * root + 1;
	int right = 2 * root + 2;

	if (left < n && elems[left] > elems[largest])
	{
		largest = left;
	}
	if (right < n && elems[right] > elems[largest])
	{
		largest = right;
	}

	if (largest != root)
	{
		std::swap(elems[root], elems[largest]);
		heapify(elems, n, largest);
	}
}

//*****************************************************************************************************

template <typename T>
void SortedList<T>::heapifyD(T* elems, int n, int root)
{
	int largest = root;
	int left = 2 * root + 1;
	int right = 2 * root + 2;

	if (left < n && elems[left] < elems[largest])
	{
		largest = left;
	}
	if (right < n && elems[right] < elems[largest])
	{
		largest = right;
	}

	if (largest != root)
	{
		std::swap(elems[root], elems[largest]);
		heapifyD(elems, n, largest);
	}
}

//*****************************************************************************************************

template <typename T>
void SortedList<T>::heapSortARec(T* elems, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(elems, n, i);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		std::swap(elems[0], elems[i]);
		heapify(elems, i, 0);
	}
}

//*****************************************************************************************************

template <typename T>
void SortedList<T>::heapSortDRec(T* elems, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapifyD(elems, n, i);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		std::swap(elems[0], elems[i]);
		heapifyD(elems, i, 0);
	}
}

//*****************************************************************************************************

template<typename T>
SortedList<T>::SortedList(int c)
{
	capacity = c;
	elements = new T[capacity];
	size = 0;
}

//*****************************************************************************************************

template<typename T>
SortedList<T>::~SortedList()
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
inline void SortedList<T>::quickSortA()
{
	quickSortARec(elements, 0, size - 1);
}

//*****************************************************************************************************

template <typename T>
inline void SortedList<T>::quickSortD()
{
	quickSortDRec(elements, 0, size - 1);
}

//*****************************************************************************************************

template <typename T>
inline void SortedList<T>::heapSortA()
{
	heapSortARec(elements, size);
}

//*****************************************************************************************************

template <typename T>
inline void SortedList<T>::heapSortD()
{
	heapSortDRec(elements, size);
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
