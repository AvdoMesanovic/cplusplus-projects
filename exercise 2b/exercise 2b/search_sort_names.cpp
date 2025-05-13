// *************************************************
// 
//  Assignment:    #2b
//  File:          search_sort_names.cpp
//
//  Due Date:      February 14, 2022
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
int binarySearchNames(const string names[], int numNames, const string& name);
void selectionSort(string names[], int numNames);
void selectionSortDescending(string names[], int numNames);

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
	
	cout << "All names: \n";
	displayNames(names, numNames);
	cout << "\n";

	cout << "Descending order: \n";
	selectionSortDescending(names, numNames);
	displayNames(names, numNames);
	cout << "\n";
	cout << "Ascending order: \n";
	selectionSort(names, numNames);
	displayNames(names, numNames);
	cout << "\n";
	cout << "Please enter the name you'd wish to search for \n";
	getline(cin, userName);
	findName = binarySearchNames(names, numNames, userName);
	if (findName == -1)
	{
		cout << "Name not found" << endl;
	}
	else
	{
		cout << "Name found" << endl;
	}

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
	for (int n = 0; n < numNames; n++)
	{
		cout << names[n] << endl;
	}
}

// *************************************************
// This function searches through the names for the third argument passed
int binarySearchNames(const string names[], int numNames, const string& name)
{
	int first = 0;
	int last = numNames - 1;
	int middle;
	int position = -1;
	bool found = false;
	while (!found && (first <= last))
	{
		middle = (first + last) / 2;
		if (names[middle] == name)
		{
			found = true;
			position = middle;
		}
		else if (names[middle] > name)
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;
		}
	}
	return position;
}

// *************************************************
// This function sorts the names in ascending order
void selectionSort(string names[], int numNames)
{
	int minIndex;
	string minName;
	for (int startScan = 0; startScan < numNames; startScan++)
	{
		minIndex = startScan;
		minName = names[minIndex];
		for (int index = startScan + 1; index < numNames; index++)
		{
			if (names[index] < minName)
			{
				minName = names[index];
				minIndex = index;
			}
		}
		names[minIndex] = names[startScan];
		names[startScan] = minName;
	}
}

// *************************************************
// This function sorts the names in descending order
void selectionSortDescending(string names[], int numNames)
{
	int minIndex;
	string minName;
	for (int startScan = 0; startScan < numNames; startScan++)
	{
		minIndex = startScan;
		minName = names[minIndex];
		for (int index = startScan + 1; index < numNames; index++)
		{
			if (names[index] > minName)
			{
				minName = names[index];
				minIndex = index;
			}
		}
		names[minIndex] = names[startScan];
		names[startScan] = minName;
	}
}