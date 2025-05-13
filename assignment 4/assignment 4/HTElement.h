//*****************************************************************************************************
//
//		File:					HTElement.h
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

#ifndef HTELEMENT_H
#define HTELEMENT_H

//*****************************************************************************************************

template <typename TYPE>
struct HTElement
{
	TYPE item;
	int status;

	HTElement();
	HTElement(const TYPE& i, const int& s);
	void display() const;
};

//*****************************************************************************************************

template <typename TYPE>
HTElement<TYPE>::HTElement()
{
	status = 0;
}

//*****************************************************************************************************

template <typename TYPE>
HTElement<TYPE>::HTElement(const TYPE& i, const int& s)
{
	item = i;
	status = s;
}

//*****************************************************************************************************

template <typename TYPE>
void HTElement<TYPE>::display() const
{
	item.display();
}
//*****************************************************************************************************

#endif