// *************************************************
// 
//  Assignment:    #10a
//  File:          text_to_binary.cpp
//
//  Due Date:      April 25, 2022
//
//  Author:        Avdo Mesanovic 
//
//  Course Name:   Programming II 
//
//  Course Number: COSC 1560 
//
//  Description:   This program writes the information in Testers.txt
//				   to a binary file named Testers.dat
//				   
// *************************************************

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

struct Date
{
	int month;
	int day;
	int year;
};

struct Person
{
	char name[20];
	double score;
	Date testTaken;
};


int main()
{
	fstream f1;
	fstream f2;

	Person* p = nullptr;

	int numTester = 0;

	f1.open("Testers.txt", ios::in);
	if (!f1)
	{
		cout << "FILE DOES NOT EXIST" << endl;
		return 0;
	}
	else {
		f1 >> numTester;
		p = new Person[numTester];
		f1.get();
		for (int i = 0; i < numTester; i++)
		{
			f1.getline(p[i].name, 20);
			f1 >> p[i].score;
			f1.get();
			f1 >> p[i].testTaken.month;
			f1.get();
			f1 >> p[i].testTaken.day;
			f1.get();
			f1 >> p[i].testTaken.year;
			f1.get();
		}
	}

	f2.open("Testers.dat", ios::out | ios::binary);
	f2.write(reinterpret_cast<char*>(&numTester), sizeof(numTester));
	f2.write(reinterpret_cast<char*>(p), sizeof(p) * numTester);

	f1.close();
	f2.close();

	return 0;
}