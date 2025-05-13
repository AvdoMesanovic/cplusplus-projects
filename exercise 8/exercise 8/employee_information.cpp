// *************************************************
// 
//  Assignment:    #8
//  File:          employee_information.cpp
//
//  Due Date:      April 11, 2022
//
//  Author:        Avdo Mesanovic 
//
//  Course Name:   Programming II 
//
//  Course Number: COSC 1560 
//
//  Description:   This program stores information for 
//				   employees of a particular company
//				   
// *************************************************

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct DateEmployed
{
	int month;
	int day;
	int year;
};
struct Employee
{
	string name;
	int age;
	DateEmployed date;
};

Employee* readEmployees(const string& empFile, int& numEmps);
void displayEmployees(const Employee emps[], int numEmps);
Employee* inputEmployees(Employee* emps, int& numEmps);

int main()
{
	const string empFile = "Employees.txt";
	int numEmps;
	string choice;
	Employee* empPtr = nullptr;

	empPtr = readEmployees(empFile, numEmps);
	displayEmployees(empPtr, numEmps);
	cout << endl;

	Employee* allEmps = nullptr;
	ofstream f;

	cout << "Would you like to add employees? Please enter 'Yes' or 'No'" << endl;
	cin >> choice;

	if (choice == "Yes" || choice == "yes")
	{
		allEmps = inputEmployees(empPtr, numEmps);
		f.open(empFile);

		for (int i = 0; i < numEmps; i++)
		{
		   f << allEmps[i].name << "," <<
				allEmps[i].age << "," <<
				allEmps[i].date.month << "/" <<
				allEmps[i].date.day << "/" <<
				allEmps[i].date.year << endl;
		}

		displayEmployees(allEmps, numEmps);
	}

	delete[]empPtr;
	delete[]allEmps;
	return 0;
}

// *************************************************
// This function returns a pointer to the array allocated to store the employees read from the file
Employee* readEmployees(const string& empFile, int& numEmps)
{
	Employee* empPtr = nullptr;
	fstream dataFile;
	dataFile.open(empFile, ios::in);
	dataFile >> numEmps;
	empPtr = new Employee[numEmps];
	if (!dataFile)
	{
		cout << "Error opening file" << endl;
		return 0;
	}
	if (dataFile)
	{
		for (int i = 0; i < numEmps; i++)
		{
			getline(dataFile, empPtr[i].name, ',');
			dataFile.get();
			dataFile >> empPtr[i].age;
			dataFile.get();
			dataFile >> empPtr[i].date.month;
			dataFile.get();
			dataFile >> empPtr[i].date.day;
			dataFile.get();
			dataFile >> empPtr[i].date.year;
			dataFile.get();
		}
	}
	return empPtr;
}

// *************************************************
// This function displays all employees in the first argument
void displayEmployees(const Employee emps[], int numEmps)
{
	cout << left << setw(20) << "NAME" << setw(15) << "AGE" << "DATE EMPLOYED" << endl;
	for (int i = 0; i < numEmps; i++)
	{
		cout << left << setw(20) << emps[i].name;
		cout << left << setw(15) << emps[i].age;
		cout << right << setw(1) << emps[i].date.month << "/" << right << setw(1) << emps[i].date.day << "/" << right << setw(1) << emps[i].date.year;
		cout << endl;
	}
}

// *************************************************
// This function allows user to input new employee details
Employee* inputEmployees(Employee* emps, int& numEmps)
{
	Employee* allEmps = nullptr;
	string temp;
	int num;

	cout << "How many employees would you like to enter? " << endl;
	cin >> num;
	int total = numEmps + num;

	allEmps = new Employee[total];

	for (int i = 0; i < numEmps; i++)
	{
		allEmps[i] = emps[i];
	}
	cin.get();

	for (int i = 0; i < num; i++)
	{
		cout << "NAME: ";
		getline(cin, allEmps[i + numEmps].name);
		cout << "AGE: ";
		cin >> allEmps[i + numEmps].age;
		cin.get();
		cout << "DATE: ";
		cin >> allEmps[i + numEmps].date.month, '/';
		getline(cin, temp, '/');
		cin >> allEmps[i + numEmps].date.day, '/';
		getline(cin, temp, '/');
		cin >> allEmps[i + numEmps].date.year;
		cin.get();
	}

	numEmps += num;

	return allEmps;
}