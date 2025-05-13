// *************************************************
// 
//  Assignment:    #6a
//  File:          c-string.cpp
//
//  Due Date:      March 7, 2022
//
//  Author:        Avdo Mesanovic 
//
//  Course Name:   Programming II 
//
//  Course Number: COSC 1560 
//
//  Description:   This program is passes C-string to a function, calculates and returns the number of 
//				   words, and displays the appropriate output 
//
// *************************************************

#include <iostream>
#include <string>
using namespace std;

int numberWords(const char* words, int size);

int main()
{
	const int size = 50;
	int numWords;
	char* words = nullptr;
	words = new char[size];

	for (int i = 0; i < 3; i++)
	{
		cout << "Please enter a sentence ending with a '.' and the number of words in the sentence will be returned: \n";
		cin.getline(words, size);
		numWords = numberWords(words, size);
		cout << "\n";
		cout << "Number of words in given sentence is " << numWords << endl;
		cout << "\n";
	}

	return 0;
}

// *************************************************
// This function accepts a C-string as an argument, and the size of the C-string, and returns the number of words in the given sentence
int numberWords(const char* words, int size)
{
	int numWords = 0;
	if (isalpha(words[0]))
	{
		numWords++;
	}
	for (int i = 0; i < size; i++)
	{
		if ((words[i] == ' ' && isalpha(words[i + 1])) || (words[i] == ',' && isalpha(words[i + 1])) || (isalpha(words[i] && words[i + 1] == '.')))
		{
			numWords++;
		}
	}
	return numWords;
}

/*
	Please enter a sentence ending with a '.' and the number of words in the sentence will be returned:
	My name is Avdo, and I like soccer.

	Number of words in given sentence is 8

	Please enter a sentence ending with a '.' and the number of words in the sentence will be returned:
	,, Hello and good morning ,,.

	Number of words in given sentence is 4

	Please enter a sentence ending with a '.' and the number of words in the sentence will be returned:
	   Nice to meet you, John    .

	Number of words in given sentence is 5


	C:\Users\avdom\OneDrive\Documents\source\repos\exercise 6a\Debug\exercise 6a.exe (process 11660) exited with code 0.
	Press any key to close this window . . .

*/