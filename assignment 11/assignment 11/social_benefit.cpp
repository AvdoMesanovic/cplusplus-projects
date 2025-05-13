// *************************************************
// 
//  Assignment:    #11
//  File:          social_benefit.cpp
//
//  Due Date:      October 1, 2021 
//
//  Author:        Avdo Mesanovic 
//
//  Course Name:   Programming I 
//
//  Course Number: COSC 1550 
//
//  Description:   This program determines if a requestor
//				   is elligble for a social benefit
//
// *************************************************

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{

	char gender;
	int age;

	cout << "What is your gender? Please answer with a 'M' for male or 'F' for female. \n"; 
	cin >> gender; 
	gender = toupper(gender);
	cout << "What is your age? \n";
	cin >> age;

	if (gender == 'M')
	{
		if (age < 65)
		{
			cout << "Sorry, but your benefit is $0 per month. You must be at least 65 years of age. \n";
		}
		else
		{
			cout << "Your benefit is $100 per month. \n";
		}
	}
	else
	{
		if (age < 60)
		{
			cout << "Sorry, but your benefit is $0 per month. You must be at least 60 years of age. \n";
		}
		else
		{
			cout << "Your benefit is $180 per month. \n";
		}
	}

	return 0;
}

/*
	What is your gender? Please answer with a 'M' for male or 'F' for female.
	m
	What is your age?
	55
	Sorry, but your benefit is $0 per month. You must be at least 65 years of age.

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 11\Debug\assignment 11.exe (process 6236) exited with code 0.
	Press any key to close this window . . .
----------------------------------------------------------------------------------------------------------------------------
	What is your gender? Please answer with a 'M' for male or 'F' for female.
	m
	What is your age?
	65
	Your benefit is $100 per month.

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 11\Debug\assignment 11.exe (process 11028) exited with code 0.
	Press any key to close this window . . .
----------------------------------------------------------------------------------------------------------------------------
	What is your gender? Please answer with a 'M' for male or 'F' for female.
	f
	What is your age?
	55
	Sorry, but your benefit is $0 per month. You must be at least 60 years of age.

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 11\Debug\assignment 11.exe (process 13764) exited with code 0.
	Press any key to close this window . . .
----------------------------------------------------------------------------------------------------------------------------
	What is your gender? Please answer with a 'M' for male or 'F' for female.
	f
	What is your age?
	60
	Your benefit is $180 per month.

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 11\Debug\assignment 11.exe (process 9748) exited with code 0.
	Press any key to close this window . . .
*/