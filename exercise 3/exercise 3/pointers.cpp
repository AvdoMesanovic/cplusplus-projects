// *************************************************
// 
//  Assignment:    #3
//  File:          pointers.cpp
//
//  Due Date:      February 14, 2022
//
//  Author:        Avdo Mesanovic 
//
//  Course Name:   Programming II 
//
//  Course Number: COSC 1560 
//
//  Description:   
//
// *************************************************

#include <iostream>
using namespace std;

int main()
{
	int n1 = 10,
	    n2 = 25,
	    n3 = 50;

	int* p1 = &n1;
	int* p2 = &n2;

	*p1 = *p1 * 2;
	*p1 = *p1 + *p2;
	cout << "Sum of n1 multiplied by 2 and n2 is " << *p1 << "." << endl;

	p1 = &n3;
	*p1 = *p1 + *p2;
	cout << "Sum of n2 and n3 is " << *p1 << "." << endl;

	return 0;
}


/*
	Sum of n1 multiplied by 2 and n2 is 45.
	Sum of n2 and n3 is 75.

	C:\Users\avdom\OneDrive\Documents\source\repos\exercise 3\Debug\exercise 3.exe (process 15080) exited with code 0.
	Press any key to close this window . . .
*/