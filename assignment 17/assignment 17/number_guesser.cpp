// *************************************************
// 
//  Assignment:    #17
//  File:          number_guesser.cpp
//
//  Due Date:      November 8, 2021 
//
//  Author:        Avdo Mesanovic 
//
//  Course Name:   Programming I 
//
//  Course Number: COSC 1550 
//
//  Description:   This program generates a random number and keeps prompting 
//				   the user to guess what it is until they get it right
//
// *************************************************

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	const int MAXRANGE = 100;
	int guess = 0,
		count = 0;

	srand((unsigned)time(0));
	int randomNumber = 1 + rand() % MAXRANGE;

	cout << "Can you guess the number I'm thinking of? (1 - 100) \n";

	while (guess != randomNumber)
	{
		cin >> guess;
		if (guess < randomNumber)
		{
			cout << "No, that's too low, try again \n";
		}
		else if (guess > randomNumber)
		{
			cout << "No, that's too high, try again \n";
		}
		count++;
	}
	cout << "Nice job, the number I was thinking of was " << randomNumber << endl;
	cout << "You were able to get it right in " << count << " guesse(s)!" << endl;

	return 0;
}

/*
	Can you guess the number I'm thinking of? (1 - 100)
	30
	No, that's too low, try again
	60
	No, that's too low, try again
	90
	No, that's too high, try again
	70
	No, that's too low, try again
	80
	No, that's too low, try again
	85
	No, that's too low, try again
	86
	No, that's too low, try again
	87
	Nice job, the number I was thinking of was 87
	You were able to get it right in 8 guesse(s)!

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 17\Debug\assignment 17.exe (process 7424) exited with code 0.
	Press any key to close this window . . .
----------------------------------------------------------------------------------------------------------------------------
	Can you guess the number I'm thinking of? (1 - 100)
	50
	No, that's too low, try again
	70
	No, that's too high, try again
	55
	No, that's too low, try again
	60
	Nice job, the number I was thinking of was 60
	You were able to get it right in 4 guesse(s)!

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 17\Debug\assignment 17.exe (process 14180) exited with code 0.
	Press any key to close this window . . .
*/