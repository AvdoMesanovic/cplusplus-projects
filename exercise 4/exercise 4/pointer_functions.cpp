// *************************************************
// 
//  Assignment:    #4
//  File:          pointer_functions.cpp
//
//  Due Date:      February 21, 2022
//
//  Author:        Avdo Mesanovic 
//
//  Course Name:   Programming II 
//
//  Course Number: COSC 1560 
//
//  Description:   This program incorporates pointers in functions
//
// *************************************************

#include <iostream>
using namespace std;

void f1(int numbers[], int numValues);
void f2(int* ptr, int numvalues);
void f3(int numbers[], int numValues);
void f4(int numbers[], int numValues);

int main()
{
	const int numValues = 5;
	int numbers[numValues] = {10, 22, 34, 48, 59};
	int* ptr = nullptr;
	ptr = numbers;

	cout << "Value and memory address using array: \n";
	f1(numbers, numValues);
	cout << "Press enter to continue \n";
	cin.get();
	cout << "Value and memory address using pointers: \n";
	f2(ptr, numValues);
	cout << "Press enter to continue \n";
	cin.get();
	f3(numbers, numValues);
	cout << "Press enter to continue \n";
	cin.ignore();
	cin.get();
	f4(numbers, numValues);

	return 0;
}

// *************************************************
// This function prints all values and memory addresses of each element stored in the array without using pointers
void f1(int numbers[], int numValues)
{
	for (int count = 0; count < numValues; count++)
	{
		cout << numbers[count] << " ===> " << &numbers[count] << endl;
	}
}

// *************************************************
// This function prints all values and memory addresses of each element stored in the array using pointers
void f2(int* ptr, int numValues)
{
	for (int count = 0; count < numValues; count++)
	{
		cout << *(ptr + count) << " ===> " << (ptr + count) << endl;
	}
}

// *************************************************
// This function moves the pointer to the corresponding element of the integer that is input, and prints out the corresponding memory address and value
void f3(int numbers[], int numValues)
{
	int userValue1,
		userValue2,
		userValue3;
	int* ptr = nullptr;
	cout << "Please enter an integer value within the range of the indices of the array \n";
	cin >> userValue1;
	while (userValue1 < 0 || userValue1 > (numValues - 1))
	{
		cout << "Error: please enter a number ONLY within the range of the indices of the array \n";
		cin >> userValue1;
	}
	userValue1 = numbers[userValue1];
	ptr = &userValue1;
	cout << "Value and memory address: " << endl;
	cout << *ptr << " ===> " << ptr << endl;
	cout << "\n";
	cout << "Please enter an integer value within the range of the indices of the array \n";
	cin >> userValue2;
	while (userValue2 < 0 || userValue2 >(numValues - 1))
	{
		cout << "Error: please enter a number ONLY within the range of the indices of the array \n";
		cin >> userValue2;
	}
	userValue2 = numbers[userValue2];
	ptr = &userValue2;
	cout << "Value and memory address: " << endl;
	cout << *ptr << " ===> " << ptr << endl;
	cout << "\n";
	cout << "Please enter an integer value within the range of the indices of the array \n";
	cin >> userValue3;
	while (userValue3 < 0 || userValue3 > (numValues - 1))
	{
		cout << "Error: please enter a number ONLY within the range of the indices of the array \n";
		cin >> userValue3;
	}
	userValue3 = numbers[userValue3];
	ptr = &userValue3;
	cout << "Value and memory address: " << endl;
	cout << *ptr << " ===> " << ptr << endl;
}

// *************************************************
// This function uses pointers two point to two array elements and add them
void f4(int numbers[], int numValues)
{
	int userValue1,
		userValue2,
		sum;
	int* ptr1 = nullptr;
	int* ptr2 = nullptr;

	cout << "Please enter an integer value within the range of the indices of the array \n";
	cin >> userValue1;
	while (userValue1 < 0 || userValue1 > (numValues - 1))
	{
		cout << "Error: please enter a number ONLY within the range of the indices of the array \n";
		cin >> userValue1;
	}
	userValue1 = numbers[userValue1];
	ptr1 = &userValue1;
	cout << "Please enter an integer value within the range of the indices of the array \n";
	cin >> userValue2;
	while (userValue2 < 0 || userValue2 > (numValues - 1))
	{
		cout << "Error: please enter a number ONLY within the range of the indices of the array \n";
		cin >> userValue2;
	}
	userValue2 = numbers[userValue2];
	ptr2 = &userValue2;
	sum = *ptr1 + *ptr2;
	cout << "Sum of both elements is " << sum << endl;
}

/*
	Value and memory address using array:
	10 ===> 010FFAF8
	22 ===> 010FFAFC
	34 ===> 010FFB00
	48 ===> 010FFB04
	59 ===> 010FFB08
	Press enter to continue

	Value and memory address using pointers:
	10 ===> 010FFAF8
	22 ===> 010FFAFC
	34 ===> 010FFB00
	48 ===> 010FFB04
	59 ===> 010FFB08
	Press enter to continue

	Please enter an integer value within the range of the indices of the array
	5
	Error: please enter a number ONLY within the range of the indices of the array
	0
	Value and memory address:
	10 ===> 010FFA00

	Please enter an integer value within the range of the indices of the array
	1
	Value and memory address:
	22 ===> 010FF9F4

	Please enter an integer value within the range of the indices of the array
	2
	Value and memory address:
	34 ===> 010FF9E8
	Press enter to continue

	Please enter an integer value within the range of the indices of the array
	-1
	Error: please enter a number ONLY within the range of the indices of the array
	0
	Please enter an integer value within the range of the indices of the array
	1
	Sum of both elements is 32

	C:\Users\avdom\OneDrive\Documents\source\repos\exercise 4\Debug\exercise 4.exe (process 3644) exited with code 0.
	Press any key to close this window . . .
*/