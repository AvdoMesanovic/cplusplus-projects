//*****************************************************************************************************
//
//		File:					student.h
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #12
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-01
//
//		Due:					May 5th, 2023
//
//		This program explores the Doubly Linked List data structure and utilizes several
//	    functions to employ it.
//	
//		Other files required: N/A
//			
//*****************************************************************************************************

#ifndef STUDENT_H
#define STUDENT_H

//*****************************************************************************************************

#include <iostream>
#include <iomanip>

//*****************************************************************************************************

struct Student
{
	int id;
	char name[50];
	char citystate[50];
	char phone[12];
	char gender;
	int year;
	int credits;
	float gpa;
	char major[6];

	Student();
	friend ostream& operator << (ostream& out, const Student& data);

	bool operator == (const Student& rhs) const;
	bool operator == (int value) const;
	bool operator != (const Student& rhs) const;
	bool operator != (int value) const;
	bool operator < (const Student& rhs) const;
	bool operator < (int value) const;
	bool operator > (const Student& rhs) const;
	bool operator > (int value) const;
	bool operator <= (const Student& rhs) const;
	bool operator <= (int value) const;
	bool operator >= (const Student& rhs) const;
	bool operator >= (int value) const;
};

//*****************************************************************************************************

Student::Student()
{
	id = 0;
}

//*****************************************************************************************************

ostream& operator << (ostream& out, const Student& data)
{
	out << data.id << "\t" << left << setw(20) << data.name << "\t\t" << data.major << "\t" 
		<< data.gpa << endl;

	return out;
}

//*****************************************************************************************************

bool Student::operator == (const Student& rhs) const
{
	return (this->id == rhs.id);
}

//*****************************************************************************************************

bool Student::operator == (int value) const
{
	return (this->id == value);
}

//*****************************************************************************************************

bool Student::operator != (const Student& rhs) const
{
	return (this->id != rhs.id);
}

//*****************************************************************************************************

bool Student::operator != (int value) const
{
	return (this->id != value);
}

//*****************************************************************************************************

bool Student::operator < (const Student& rhs) const
{
	return (this->id < rhs.id);
}

//*****************************************************************************************************

bool Student::operator < (int value) const
{
	return (this->id < value);
}

//*****************************************************************************************************

bool Student::operator > (const Student& rhs) const
{
	return (this->id > rhs.id);
}

//*****************************************************************************************************

bool Student::operator > (int value) const
{
	return (this->id > value);
}

//*****************************************************************************************************

bool Student::operator <= (const Student& rhs) const
{
	return (this->id <= rhs.id);
}

//*****************************************************************************************************

bool Student::operator <= (int value) const
{
	return (this->id <= value);
}

//*****************************************************************************************************

bool Student::operator >= (const Student& rhs) const
{
	return (this->id >= rhs.id);
}

//*****************************************************************************************************

bool Student::operator >= (int value) const
{
	return (this->id >= value);
}

//*****************************************************************************************************

#endif