// *************************************************
// 
//  Assignment:    #10
//  File:          geometry_calculator.cpp
//
//  Due Date:      October 1, 2021 
//
//  Author:        Avdo Mesanovic 
//
//  Course Name:   Programming I 
//
//  Course Number: COSC 1550 
//
//  Description:   This program is a menu driven
//				   geometry calculator
//
// *************************************************

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	int choice;
	double area,
		   radius,
		   length,
		   width,
		   base,
		   height;

	cout << "Geometry Calculator \n";
	cout << "1. Calculate the area of a circle \n";
	cout << "2. Calculate the area of a rectangle \n";
	cout << "3. Calculate the area of a triangle \n";
	cout << "4. Quit \n";
	cout << "Enter your choice (1-4): \n";
	cin >> choice;
	cout << fixed << showpoint << setprecision(2);

	if (choice < 1 || choice > 4)
	{
		cout << "Invalid, please pick a number 1-4 from the list \n";
		cin >> choice;
		if (choice == 1)
		{
			cout << "Please enter the radius of a circle \n";
			cin >> radius;
			if (radius < 0)
			{
				cout << "Invalid, please enter a positive value for radius \n";
				cin >> radius;
			}
			else
			{
				area = 3.14159 * (pow(radius, 2));
				cout << "The area is " << area << endl;
			}
		}
		else if (choice == 2)
		{
			cout << "Please enter the length of a recentangle \n";
			cin >> length;
			cout << "Please enter the width of a rectangle \n";
			cin >> width;
			if (length < 0 && width < 0)
			{
				cout << "Invalid, please enter a positive value for length \n";
				cin >> length;
				cout << "Invalid, please enter a positive value for width \n";
				cin >> width;
				area = length * width;
				cout << "The area is " << area << endl;
			}
			else if (length < 0)
			{
				cout << "Invalid, please enter a positive value for length \n";
				cin >> length;
				area = length * width;
				cout << "The area is " << area << endl;
			}
			else if (width < 0)
			{
				cout << "Invalid, please enter a positive value for width \n";
				cin >> width;
				area = length * width;
				cout << "The area is " << area << endl;
			}
			else
			{
				area = length * width;
				cout << "The area is " << area << endl;
			}
		}
		else if (choice == 3)
		{
			cout << "Please enter the base of a triangle \n";
			cin >> base;
			cout << "Please enter the height of a triangle \n";
			cin >> height;
			if (base < 0 && height < 0)
			{
				cout << "Invalid, please enter a positive value for base \n";
				cin >> base;
				cout << "Invalid, please enter a positive value for height \n";
				cin >> height;
				area = base * height * 0.5;
				cout << "The area is " << area << endl;
			}
			else if (base < 0)
			{
				cout << "Invalid, please enter a positive value for base \n";
				cin >> base;
				area = base * height * 0.5;
				cout << "The area is " << area << endl;
			}
			else if (height < 0)
			{
				cout << "Invalid, please enter a positive value for height \n";
				cin >> height;
				area = base * height * 0.5;
				cout << "The area is " << area << endl;
			}
			else
			{
				area = base * height * 0.5;
				cout << "The area is " << area << endl;
			}
		}
		else if (choice == 4)
		{
			cout << "Thank you!" << endl;
		}
	}
	else if (choice == 1)
	{
		cout << "Please enter the radius of a circle \n";
		cin >> radius;
		if (radius < 0)
		{
			cout << "Invalid, please enter a positive value for radius \n";
			cin >> radius;
		}
		else 
		{
			area = 3.14159 * (pow(radius, 2));
			cout << "The area is " << area << endl;
		}
	}
	else if (choice == 2)
	{
		cout << "Please enter the length of a recentangle \n";
		cin >> length;
		cout << "Please enter the width of a rectangle \n";
		cin >> width;
		if (length < 0 && width < 0)
		{
			cout << "Invalid, please enter a positive value for length \n";
			cin >> length;
			cout << "Invalid, please enter a positive value for width \n";
			cin >> width;
			area = length * width;
			cout << "The area is " << area << endl;
		}
		else if (length < 0)
		{
			cout << "Invalid, please enter a positive value for length \n";
			cin >> length;
			area = length * width;
			cout << "The area is " << area << endl;
		}
		else if (width < 0)
		{
			cout << "Invalid, please enter a positive value for width \n";
			cin >> width;
			area = length * width;
			cout << "The area is " << area << endl;
		}
		else
		{
			area = length * width;
			cout << "The area is " << area << endl;
		}
	}
	else if (choice == 3)
	{
		cout << "Please enter the base of a triangle \n";
		cin >> base;
		cout << "Please enter the height of a triangle \n";
		cin >> height;
		if (base < 0 && height < 0)
		{
			cout << "Invalid, please enter a positive value for base \n";
			cin >> base;
			cout << "Invalid, please enter a positive value for height \n";
			cin >> height;
			area = base * height * 0.5;
			cout << "The area is " << area << endl;
		}
		else if (base < 0)
		{
			cout << "Invalid, please enter a positive value for base \n";
			cin >> base;
			area = base * height * 0.5;
			cout << "The area is " << area << endl;
		}
		else if (height < 0)
		{
			cout << "Invalid, please enter a positive value for height \n";
			cin >> height;
			area = base * height * 0.5;
			cout << "The area is " << area << endl;
		}
		else
		{
			area = base * height * 0.5;
			cout << "The area is " << area << endl;
		}
	}
	else if (choice == 4)
	{
		cout << "Thank you!" << endl;
	}


	return 0;
}

/*
	Geometry Calculator
	1. Calculate the area of a circle
	2. Calculate the area of a rectangle
	3. Calculate the area of a triangle
	4. Quit
	Enter your choice (1-4):
	8
	Invalid, please pick a number 1-4 from the list
	1
	Please enter the radius of a circle
	2
	The area is 12.57

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 10\Debug\assignment 10.exe (process 12920) exited with code 0.
	Press any key to close this window . . .
----------------------------------------------------------------------------------------------------------------------------
	Geometry Calculator
	1. Calculate the area of a circle
	2. Calculate the area of a rectangle
	3. Calculate the area of a triangle
	4. Quit
	Enter your choice (1-4):
	2
	Please enter the length of a recentangle
	-3
	Please enter the width of a rectangle
	4
	Invalid, please enter a positive value for length
	3
	The area is 12.00

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 10\Debug\assignment 10.exe (process 14456) exited with code 0.
	Press any key to close this window . . .
----------------------------------------------------------------------------------------------------------------------------
	Geometry Calculator
	1. Calculate the area of a circle
	2. Calculate the area of a rectangle
	3. Calculate the area of a triangle
	4. Quit
	Enter your choice (1-4):
	3
	Please enter the base of a triangle
	-5
	Please enter the height of a triangle
	-6
	Invalid, please enter a positive value for base
	5
	Invalid, please enter a positive value for height
	6
	The area is 15.00

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 10\Debug\assignment 10.exe (process 4136) exited with code 0.
	Press any key to close this window . . .
---------------------------------------------------------------------------------------------------------------------------
	Geometry Calculator
	1. Calculate the area of a circle
	2. Calculate the area of a rectangle
	3. Calculate the area of a triangle
	4. Quit
	Enter your choice (1-4):
	4
	Thank you!

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 10\Debug\assignment 10.exe (process 3680) exited with code 0.
	Press any key to close this window . . .
*/