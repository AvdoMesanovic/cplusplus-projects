// *************************************************
// 
//  Assignment:    #14
//  File:          math_tutor_2.cpp
//
//  Due Date:      October 29, 2021 
//
//  Author:        Avdo Mesanovic 
//
//  Course Name:   Programming I 
//
//  Course Number: COSC 1550 
//
//  Description:   This program displays a menu that allows math tutors
//				   to generate different types of random math problems
//
// *************************************************

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	const int MAXRANGE = 50;
	int choice,
		total,
		realDecimalAns,
		quotient;
	double totalAsDouble;
	cout << fixed << showpoint << setprecision(2);

	do
	{
		cout << "Menu \n";
		cout << "1. Addition problem \n";
		cout << "2. Subtraction problem \n";
		cout << "3. Multiplication problem \n";
		cout << "4. Division problem \n";
		cout << "5. Quit program \n";
		cin >> choice;
		while (choice < 1 || choice > 5)
		{
			cout << "Choice must be 1, 2, 3, 4, or 5 \n";
			cout << "Enter choice again \n";
			cin >> choice;
		}
		switch (choice)
		{
		case 1:
		{
			unsigned seed;
			cout << "Enter a seed to generate 2 numbers within the range of 1 - 50 to add \n";
			cin >> seed;
			srand(seed);

			int random1 = 1 + rand() % MAXRANGE;
			int random2 = 1 + rand() % MAXRANGE;
			srand(time(0));

			cout << "Enter the correct answer: \n";

			cout << random1 << " + " << random2 << " = " << endl;
			cin >> total;

			if (total == random1 + random2)
			{
				cout << "Congratulations! That's right" << endl;
			}
			else
			{
				total = random1 + random2;
				cout << "Sorry, the correct answer is " << total << endl;
			}
			break;
		}
		case 2:
		{
			unsigned seed;
			cout << "Enter a seed to generate 2 numbers within the range of 1 - 50 to subtract \n";
			cin >> seed;
			srand(seed);

			int random1 = 1 + rand() % MAXRANGE;
			int random2 = 1 + rand() % MAXRANGE;
			srand(time(0));

			cout << "Enter the correct answer: \n";

			cout << random1 << " - " << random2 << " = " << endl;
			cin >> total;

			if (total == random1 - random2)
			{
				cout << "Congratulations! That's right" << endl;
			}
			else
			{
				total = random1 - random2;
				cout << "Sorry, the correct answer is " << total << endl;
			}
			break;
		}
		case 3:
		{
			unsigned seed;
			cout << "Enter a seed to generate 2 numbers within the range of 1 - 50 to multiply \n";
			cin >> seed;
			srand(seed);

			int random1 = 1 + rand() % MAXRANGE;
			int random2 = 1 + rand() % MAXRANGE;
			srand(time(0));

			cout << "Enter the correct answer: \n";

			cout << random1 << " * " << random2 << " = " << endl;
			cin >> total;

			if (total == random1 * random2)
			{
				cout << "Congratulations! That's right" << endl;
			}
			else
			{
				total = random1 * random2;
				cout << "Sorry, the correct answer is " << total << endl;
			}
			break;
		}
		case 4:
		{
			unsigned seed;
			cout << "Enter a seed to generate 2 numbers within the range of 1 - 50 to divide \n";
			cin >> seed;
			srand(seed);

			int random1 = 1 + rand() % MAXRANGE;
			int random2 = 1 + rand() % MAXRANGE;
			srand(time(0));

			cout << "Enter the correct answer: \n";

			cout << random1 << " / " << random2 << " = " << endl;
			cin >> totalAsDouble;

			/* This code is necessary for division, because without it, there would be a fatal error in the compiler.
			Also, with most division, the answers have decimals. So you can't just do what you did for the other cases.
			I ran the program without this part and it kept looping endlessly. It's necessary also because it rounds
			any decimal points in quotients to the nearest tenth. This is important since the setprecision is 2. */
			realDecimalAns = (int)(totalAsDouble * 100 + 0.5);
			totalAsDouble = double(realDecimalAns) / 100;
			double quotient = static_cast<double>(random1) / (random2);
			realDecimalAns = (int)(quotient * 100 + 0.5);
			quotient = double(realDecimalAns) / 100;

			if (totalAsDouble == quotient)
			{
				cout << "Congratulations! That's right" << endl;
			}
			else
			{
				cout << "Sorry, the correct answer is " << quotient << endl;
			}
			break;
		}
			case 5:
			{
				cout << "Quitting, thank you" << endl;
				break;
			}
		}
	} while (choice != 5);

	return 0;
}

/*
	Addition outputs

	Menu
	1. Addition problem
	2. Subtraction problem
	3. Multiplication problem
	4. Division problem
	5. Quit program
	1
	Enter a seed to generate 2 numbers within the range of 1 - 50 to add
	4
	Enter the correct answer:
	2 + 46 =
	48
	Congratulations! That's right

	Menu
	1. Addition problem
	2. Subtraction problem
	3. Multiplication problem
	4. Division problem
	5. Quit program
	1
	Enter a seed to generate 2 numbers within the range of 1 - 50 to add
	2
	Enter the correct answer:
	46 + 17 =
	9
	Sorry, the correct answer is 63
----------------------------------------------------------------------------------------------------------------------------
	Subtraction outputs

	Menu
	1. Addition problem
	2. Subtraction problem
	3. Multiplication problem
	4. Division problem
	5. Quit program
	2
	Enter a seed to generate 2 numbers within the range of 1 - 50 to subtract
	8
	Enter the correct answer:
	15 - 21 =
	-6
	Congratulations! That's right

	Menu
	1. Addition problem
	2. Subtraction problem
	3. Multiplication problem
	4. Division problem
	5. Quit program
	2
	Enter a seed to generate 2 numbers within the range of 1 - 50 to subtract
	13
	Enter the correct answer:
	32 - 27 =
	10
	Sorry, the correct answer is 5
----------------------------------------------------------------------------------------------------------------------------
	Multiplication outputs

	Menu
	1. Addition problem
	2. Subtraction problem
	3. Multiplication problem
	4. Division problem
	5. Quit program
	3
	Enter a seed to generate 2 numbers within the range of 1 - 50 to multiply
	1
	Enter the correct answer:
	42 * 18 =
	756
	Congratulations! That's right

	Menu
	1. Addition problem
	2. Subtraction problem
	3. Multiplication problem
	4. Division problem
	5. Quit program
	3
	Enter a seed to generate 2 numbers within the range of 1 - 50 to multiply
	5
	Enter the correct answer:
	5 * 44 =
	22
	Sorry, the correct answer is 220
----------------------------------------------------------------------------------------------------------------------------
	Division outputs

	Menu
	1. Addition problem
	2. Subtraction problem
	3. Multiplication problem
	4. Division problem
	5. Quit program
	4
	Enter a seed to generate 2 numbers within the range of 1 - 50 to divide
	2
	Enter the correct answer:
	46 / 17 =
	10
	Sorry, the correct answer is 2.71
	Menu
	1. Addition problem
	2. Subtraction problem
	3. Multiplication problem
	4. Division problem
	5. Quit program
	4
	Enter a seed to generate 2 numbers within the range of 1 - 50 to divide
	2
	Enter the correct answer:
	46 / 17 =
	2.71
	Congratulations! That's right
----------------------------------------------------------------------------------------------------------------------------
	Quit outputs

	Menu
	1. Addition problem
	2. Subtraction problem
	3. Multiplication problem
	4. Division problem
	5. Quit program
	5
	Quitting, thank you

	C:\Users\avdom\OneDrive\Documents\source\repos\assigntment 14\Debug\assignment 14.exe (process 11688) exited with code 0.
	Press any key to close this window . . .

	Menu
	1. Addition problem
	2. Subtraction problem
	3. Multiplication problem
	4. Division problem
	5. Quit program
	1
	Enter a seed to generate 2 numbers within the range of 1 - 50 to add
	4
	Enter the correct answer:
	2 + 46 =
	48
	Congratulations! That's right
	Menu
	1. Addition problem
	2. Subtraction problem
	3. Multiplication problem
	4. Division problem
	5. Quit program
	5
	Quitting, thank you

	C:\Users\avdom\OneDrive\Documents\source\repos\assigntment 14\Debug\assignment 14.exe (process 12724) exited with code 0.
	Press any key to close this window . . .
*/