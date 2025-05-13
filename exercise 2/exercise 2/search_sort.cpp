// *************************************************
// 
//  Assignment:    #2
//  File:          search_sort.cpp
//
//  Due Date:      February 7, 2022
//
//  Author:        Avdo Mesanovic 
//
//  Course Name:   Programming II 
//
//  Course Number: COSC 1560 
//
//  Description:   This program searches through a list of 10 
//				   student names and also sorts the same list
//
// *************************************************

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void readNames(ifstream& inFile, string names[], int numNames);
void displayNames(const string names[], int numNames);
int searchNames(const string names[], int numNames, const string& name);
void bubbleSort(string names[], int numNames);
void bubbleSortDescending(string names[], int numNames);

int main()
{
	const int numNames = 10;
	int findName;

	string names[numNames];
	string userName;

	ifstream inFile;
	inFile.open("StudentNames.txt");
	if (!inFile)
	{
		exit(1);
	}
	readNames(inFile, names, numNames);
	inFile.close();

	displayNames(names, numNames);
	cout << "\n";

	cout << "Please enter the name you'd wish to search for \n";
	cin >> userName;
	findName = searchNames(names, numNames, userName);
	if (findName == 1)
	{
		cout << userName << " found" << endl;
	}
	else
	{
		cout << userName << " not found" << endl;
	}
	cout << "\n";
	cout << "Ascending order: \n";
	bubbleSort(names, numNames);
	displayNames(names, numNames);
	cout << "\n";
	cout << "Descending order: \n";
	bubbleSortDescending(names, numNames);
	displayNames(names, numNames);

	return 0;
}

// *************************************************
// This function reads all names from the file and store in the array 
void readNames(ifstream& inFile, string names[], int numNames)
{
	for (int n = 0; n < numNames; n++)
	{
		getline(inFile, names[n]);
	}
}

// *************************************************
// This function displays all names from the array
void displayNames(const string names[], int numNames)
{
	cout << "All names: \n";
	for (int n = 0; n < numNames; n++)
	{
		cout << names[n] << endl;
	}
}

// *************************************************
// This function searches through the names for the third argument passed
int searchNames(const string names[], int numNames, const string& name)
{
	int index = 0;
	bool found = false;
	while (index < numNames && !found)
	{
		if (name.compare(names[index]) == 1)
		{
			found = true;
		}
		index++;
	}
	return found;
}

// *************************************************
// This function sorts the names in ascending order
void bubbleSort(string names[], int numNames)
{
	int index;
	for (int maxElement = (numNames - 1); maxElement >= 0; maxElement--)
	{
		for (index = 0; index < maxElement; index++)
		{
			if (names[index] > names[index + 1])
			{
				swap(names[index], names[index + 1]);
			}
		}
	}
}


// *************************************************
// This function sorts the names in descending order
void bubbleSortDescending(string names[], int numNames)
{
	int index;
	for (int maxElement = numNames - 1; maxElement >= 0; maxElement--)
	{
		for (index = 0; index < maxElement; index++)
		{
			if (names[index] < names[index + 1])
			{
				swap(names[index], names[index + 1]);
			}
		}
	}
}



/*
	All names:
	Smith, John
	Song, Mona
	Jones, Trevor
	Li, Na
	Zhang, Xiu Ying
	Saleem, Mohammad
	Lloyd, Arthur
	Jones, Rhys
	Evans, Olivia
	Davies, Emily

	Please enter the name you'd wish to search for
	Emily
	Emily found

	Ascending order:
	All names:
	Davies, Emily
	Evans, Olivia
	Jones, Rhys
	Jones, Trevor
	Li, Na
	Lloyd, Arthur
	Saleem, Mohammad
	Smith, John
	Song, Mona
	Zhang, Xiu Ying

	Descending order:
	All names:
	Zhang, Xiu Ying
	Song, Mona
	Smith, John
	Saleem, Mohammad
	Lloyd, Arthur
	Li, Na
	Jones, Trevor
	Jones, Rhys
	Evans, Olivia
	Davies, Emily

	C:\Users\avdom\OneDrive\Documents\source\repos\exercise 2\Debug\exercise 2.exe (process 11768) exited with code 0.
	Press any key to close this window . . .
*/