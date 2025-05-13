//*****************************************************************************************************
//
//		File:					hashTable.h
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #4
// 
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-01
//
//		Due:					September 25th, 2023
//			
//*****************************************************************************************************

#ifndef HASHTABLE_H
#define HASHTABLE_H

//*****************************************************************************************************

#include "HTElement.h"
#include <new>

//*****************************************************************************************************

template <typename TYPE>
class HashTable
{
private:
	int size;
	HTElement<TYPE>* table;

public:
	HashTable(int s = 10);
	~HashTable();
	void remove(const TYPE& item);
	void insert(const TYPE& item);
	void display() const;
	TYPE* search(const TYPE& item) const;
};

//*****************************************************************************************************

template <typename TYPE>
HashTable<TYPE>::HashTable(int s)
{
	size = s;
	table = new HTElement<TYPE>[size];
}

//*****************************************************************************************************

template <typename TYPE>
HashTable<TYPE>::~HashTable()
{
	delete[]table;
}

//*****************************************************************************************************

template <typename TYPE>
void HashTable<TYPE>::remove(const TYPE& item)
{
    int index;
    index = item.hash(size);
    TYPE empty;

    if (table[index].item == item && table[index].status == 1)
    {
        table[index].status = -1;
        table[index].item = empty;
    }
    else
    {
        for (int i = 1; i < size; i++)
        {
            index = (index + i * i) % size;

            if (table[index].item == item && table[index].status == 1)
            {
                table[index].status = -1;
                table[index].item = empty;
            }
        }
    }
}

//*****************************************************************************************************

template <typename TYPE>
void HashTable<TYPE>::insert(const TYPE& item)
{
	int index;
	index = item.hash(size);
	HTElement<TYPE> element(item, 1);
	table[index] = element;
}

//*****************************************************************************************************

template <typename TYPE>
void HashTable<TYPE>::display() const
{
	for (int i = 0; i < size; i++)
	{       
        table[i].display();
        std::cout << "___" << std::endl;
	}
}

//*****************************************************************************************************

template <typename TYPE>
TYPE* HashTable<TYPE>::search(const TYPE& item) const
{
    int index;
    index = item.hash(size);
    TYPE* result = nullptr;

    if (table[index].item == item && table[index].status == 1) 
    {
        result = &table[index].item;
    }
    else 
    {
        for (int i = 1; i < size; i++)
        {
            index = (index + i * i) % size;

            if (table[index].item == item && table[index].status == 1)
            {
                result = &table[index].item;
            }
        }
    }

    return result;
}

//*****************************************************************************************************

#endif