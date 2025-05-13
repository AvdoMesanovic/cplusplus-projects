//*****************************************************************************************************
//
//		File:					PriorityQueue.h
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #7
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-01
//
//		Due:					October 30th, 2023
//		
//*****************************************************************************************************

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

//*****************************************************************************************************

#include <iostream>
#include <new>

//*****************************************************************************************************

template <typename T>
class PriorityQueue
{
private:
	int capacity;
	T* elements;
	int size;
	
	void heapify(int i);
public:
	PriorityQueue();
	~PriorityQueue();
	void enqueue(const T& value);
	bool dequeue(T& value);
	void display() const;
};

//*****************************************************************************************************

template <typename T>
void PriorityQueue<T>::heapify(int i)
{
	int leftChild;
	int rightChild;
	int largest;
	bool stop = false;
	T temp = elements[i];
	leftChild = i * 2 + 1;

	while ((leftChild < size) && (!stop))
	{
		rightChild = leftChild + 1;

		if (rightChild >= size)
		{
			largest = leftChild;
		}
		else
		{
			if (elements[leftChild] > elements[rightChild])
			{
				largest = leftChild;
			}
			else
			{
				largest = rightChild;
			}
		}

		if (elements[largest] > temp)
		{
			elements[i] = elements[largest];
			i = largest;
			leftChild = i * 2 + 1;
		}
		else
		{
			stop = true;
		}
	}

	elements[i] = temp;
}

//*****************************************************************************************************
template <typename T>
PriorityQueue<T>::PriorityQueue()
{
	capacity = 12;
	elements = new T[capacity];
	size = 0;
}

//*****************************************************************************************************

template <typename T>
PriorityQueue<T>::~PriorityQueue()
{
	capacity = 0;
	delete[]elements;
	size = 0;
	elements = nullptr;
}

//*****************************************************************************************************

template <typename T>
void PriorityQueue<T>::enqueue(const T& value)
{
	if (size == capacity)
	{
		T* newElements;
		int newCapacity;

		newCapacity = capacity + 10;
		newElements = new(std::nothrow) T[newCapacity];

		if (newElements)
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

	int child = size;
	int parent = (child - 1) / 2;

	while ((child > 0) && (value > elements[parent]))
	{
		elements[child] = elements[parent];
		child = parent;
		parent = (parent - 1) / 2;
	}

	elements[child] = value;
	size++;
}

//*****************************************************************************************************

template <typename T>
bool PriorityQueue<T>::dequeue(T& value)
{
	bool removed = false;

	if (size > 0)
	{
		value = elements[0];
		removed = true;
		elements[0] = elements[size - 1];
		--size;
		heapify(0);
	}

	if ((capacity - size >= 10) && (capacity - 10 >= 12))
	{
		T* newElements;
		int newCapacity;

		newCapacity = capacity - 10;
		newElements = new(std::nothrow) T[newCapacity];

		if (newElements)
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

	return removed;
}

//*****************************************************************************************************

template <typename T>
void PriorityQueue<T>::display() const
{
	for (int i = 0; i < size; i++)
	{
		std::cout << elements[i] << std::endl;
	}
}

//*****************************************************************************************************

#endif