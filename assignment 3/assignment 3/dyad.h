//*****************************************************************************************************
//
//		File:					dyadDriver.h
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #3
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-01
//
//		Due:					February 13th, 2023
//
//
//		This program uses a class template to hold two values of different data types. 
//	
//		Other files required: 
//			1.	dyadDriver.cpp - a driver to prove the correctness of the Dyad class template
//			
//*****************************************************************************************************

#ifndef DYAD_H
#define DYAD_H

//*****************************************************************************************************

template <typename TYPE>
class Dyad
{
	private:
		TYPE val1;
		TYPE val2;

	public:
		Dyad(TYPE v1 = 0, TYPE v2 = 0);
		TYPE getFirst() const;
		TYPE getSecond() const;
		void get2Values(TYPE& v1, TYPE& v2) const;
		void swapValues();
};

//*****************************************************************************************************

template <typename TYPE>
Dyad<TYPE>::Dyad(TYPE v1, TYPE v2)
{
	val1 = v1;
	val2 = v2;
}

//*****************************************************************************************************

template <typename TYPE>
TYPE Dyad<TYPE>::getFirst() const
{
	return val1;
}

//*****************************************************************************************************

template <typename TYPE>
TYPE Dyad<TYPE>::getSecond() const
{
	return val2;
}

//*****************************************************************************************************

template <typename TYPE>
void Dyad<TYPE>::get2Values(TYPE& v1, TYPE& v2) const
{
	v1 = val1;
	v2 = val2;
}

//*****************************************************************************************************

template <typename TYPE>
void Dyad<TYPE>::swapValues()
{
	TYPE temp;

	temp = val1;
	val1 = val2;
	val2 = temp;
}

//*****************************************************************************************************

#endif