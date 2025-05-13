// *************************************************
// 
//  Assignment:    #19
//  File:          rock_paper_scissor.cpp
//
//  Due Date:      November 22, 2021 
//
//  Author:        Avdo Mesanovic 
//
//  Course Name:   Programming I 
//
//  Course Number: COSC 1550 
//
//  Description:   This program engages the user in a game of
//				   rock, paper, scissors versus the computer
//
// *************************************************

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int getUserChoice();
int getComputerChoice(int);
void determineWinner(int, int);

int main()
{
	int userChoice = getUserChoice();
	int computerChoice = getComputerChoice(userChoice);
	determineWinner(userChoice, computerChoice);
	return 0;
}

// *************************************************
// This function displays the game menu for the user and asks user to pick a choice
int getUserChoice()
{
	int userChoice;
	cout << "Game Menu \n";
	cout << "---------- \n";
	cout << "1) Rock \n";
	cout << "2) Paper \n";
	cout << "3) Scissors \n";
	cout << "4) Quit \n";
	cout << "Enter your choice \n";
	cin >> userChoice;
	while (userChoice < 1 || userChoice > 4)
	{
		cout << "Selection must be between 1-4 \n";
		cin >> userChoice;
	}
	if (userChoice == 1)
	{
		cout << "You selected : Rock \n";
	}
	else if (userChoice == 2)
	{
		cout << "You selected : Paper \n";
	}
	else if (userChoice == 3)
	{
		cout << "You selected : Scissors \n";
	}
	return userChoice;
}

// *************************************************
// This function generates a random number (rock, paper, or scissor) for the computer
int getComputerChoice(int userChoice)
{
	srand((unsigned)time(0));
	int randomNumber = 1 + rand() % 3;
	if (randomNumber == 1)
	{
		cout << "Computer selected : Rock \n";
	}
	else if (randomNumber == 2)
	{
		cout << "Computer selected : Paper \n";
	}
	else if (randomNumber == 3)
	{
		cout << "Computer selected : Scissors \n";
	}
	return randomNumber;
}

// *************************************************
// This function passes the computer generated number and the user generated number to determine the winner
void determineWinner(int userChoice, int randomNumber)
{
	if (userChoice == 1)
	{
		if (randomNumber == 3)
		{
			cout << "You win! Rock smashes scissors \n";
		}
		else if (randomNumber == 2)
		{
			cout << "Computer wins! Paper covers rock \n";
		}
		else
		{
			cout << "Tie! No winner \n";
		}
	}
	if (userChoice == 2)
	{
		if (randomNumber == 1)
		{
			cout << "You win! Paper covers rock \n";
		}
		else if (randomNumber == 3)
		{
			cout << "Computer wins! Scissors cut paper \n";
		}
		else
		{
			cout << "Tie! No winner \n";
		}
	}
	if (userChoice == 3)
	{
		if (randomNumber == 2)
		{
			cout << "You win! Scissors cut paper \n";
		}
		else if (randomNumber == 1)
		{
			cout << "Computer wins! Rock smashes scissors \n";
		}
		else
		{
			cout << "Tie! No winner \n";
		}
	}
}

/*
	Game Menu
	----------
	1) Rock
	2) Paper
	3) Scissors
	4) Quit
	Enter your choice
	1
	You selected : Rock
	Computer selected : Rock
	Tie! No winner

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 19\Debug\assignment 19.exe (process 2524) exited with code 0.
	Press any key to close this window . . .
----------------------------------------------------------------------------------------------------------------------------
	Game Menu
	----------
	1) Rock
	2) Paper
	3) Scissors
	4) Quit
	Enter your choice
	1
	You selected : Rock
	Computer selected : Paper
	Computer wins! Paper covers rock

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 19\Debug\assignment 19.exe (process 11984) exited with code 0.
	Press any key to close this window . . .
----------------------------------------------------------------------------------------------------------------------------
	Game Menu
	----------
	1) Rock
	2) Paper
	3) Scissors
	4) Quit
	Enter your choice
	2
	You selected : Paper
	Computer selected : Scissors
	Computer wins! Scissors cut paper

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 19\Debug\assignment 19.exe (process 3768) exited with code 0.
	Press any key to close this window . . .
----------------------------------------------------------------------------------------------------------------------------
	Game Menu
	----------
	1) Rock
	2) Paper
	3) Scissors
	4) Quit
	Enter your choice
	3
	You selected : Scissors
	Computer selected : Paper
	You win! Scissors cut paper

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 19\Debug\assignment 19.exe (process 7876) exited with code 0.
	Press any key to close this window . . .
*/