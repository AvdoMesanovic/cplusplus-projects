// *************************************************
// 
//  Assignment:    #6b
//  File:          string_functions.cpp
//
//  Due Date:      March 7, 2022
//
//  Author:        Avdo Mesanovic 
//
//  Course Name:   Programming II 
//
//  Course Number: COSC 1560 
//
//  Description:   This program uses string functions to display 
//				   information about the given string
//
// *************************************************

#include <iostream>
#include <string>
using namespace std;

void stringInfo(const string& sentence);

int main()
{
	const string& sentence = "This is a 101 SAMPLE to demonstrate string processing";
	cout << sentence << endl << endl;

	stringInfo(sentence);

	return 0;
}

// *************************************************
// This function takes the given sentence and uses string functions to display the required information
void stringInfo(const string& sentence)
{
	int num = 0;

	num = sentence.length();
	cout << "Length of the sentence: " << num << endl;

	num = 0;
	for (int i = 0; sentence[i] != '\0'; i++)
	{
		if (isalpha(sentence[i]))
		{
			num++;
		}
	}
	cout << "Number of letters in the sentence: " << num << endl;

	num = 0;
	for (int i = 0; sentence[i] != '\0'; i++)
	{
		if (isdigit(sentence[i]))
		{
			num++;
		}
	}
	cout << "Number of digits in the sentence: " << num << endl;

	num = 0;
	for (int i = 0; sentence[i] != '\0'; i++)
	{
		if (islower(sentence[i]))
		{
			num++;
		}
	}
	cout << "Number of lowercase letters in the sentence: " << num << endl;

	num = 0;
	for (int i = 0; sentence[i] != '\0'; i++)
	{
		if (isupper(sentence[i]))
		{
			num++;
		}
	}
	cout << "Number of uppercase letters in the sentence: " << num << endl;

	cout << "Character at index 12 of the sentence: " << sentence.at(12) << endl;

	cout << "Last character of the sentence: " << sentence.back() << endl;

	cout << "The index of the first 's' in the sentence: " << sentence.find('s', 0) << endl;

	cout << "The index of the second 's' in the sentence: " << sentence.find('s', 5);

	cout << "\n";
}

/*
	This is a 101 SAMPLE to demonstrate string processing

	Length of the sentence: 53
	Number of letters in the sentence: 42
	Number of digits in the sentence: 3
	Number of lowercase letters in the sentence: 35
	Number of uppercase letters in the sentence: 7
	Character at index 12 of the sentence: 1
	Last character of the sentence: g
	The index of the first 's' in the sentence: 3
	The index of the second 's' in the sentence: 6

	C:\Users\avdom\OneDrive\Documents\source\repos\exercise 6b\Debug\exercise 6b.exe (process 12068) exited with code 0.
	Press any key to close this window . . .
*/