//*****************************************************************************************************
//
//		File:					reverseString.cpp
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #2
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-01
//
//		Due:					September 11th, 2023
//
//
//		This program recursively reverses a string.
//	
//		Other files required: N/A
//			
//*****************************************************************************************************

#include <iostream>
#include <string>
using namespace std;

//*****************************************************************************************************

void reverseString(string& s, int i = 0);

//*****************************************************************************************************

int main()
{
	string s = "ABC";
	reverseString(s);
	cout << "Reversed string: " << s << endl;

	return 0;
}

//*****************************************************************************************************

void reverseString(string& s, int i)
{
    int n = s.length();
    if (i != n / 2)
    {
        swap(s[i], s[n - i - 1]);
        reverseString(s, i + 1);
    } 
}

//*****************************************************************************************************

// Reversed string : CBA