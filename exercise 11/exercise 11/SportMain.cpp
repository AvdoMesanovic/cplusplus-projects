#include "Sport.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

void displaySport(const Sport s[], int numS);

int main()
{
	Sport* sportPtr = nullptr;
	string name;
	int numSports;

	cout << "How many sports? ";
	cin >> numSports;
	cin.get();

	cout << endl;

	sportPtr = new Sport[numSports];

	for (int i = 0; i < numSports; i++)
	{
		sportPtr[i].populate();
		cout << endl;
	}

	cout << endl;

	cout << "a) Display all sports" << endl;
	cout << "b) Add a team to an existing sport" << endl;
	cout << "c) Display a particular sport" << endl;
	cout << "d) Display the sport that has the highest number of teams playing" << endl;
	cout << "e) Exit" << endl;

	cout << endl;

	cout << "Enter your choice: ";
	char ch;
	cin >> ch;
	cin.get();

	cout << endl;

	switch (ch)
	{
		case 'A':
		case 'a':
		{
			displaySport(sportPtr, numSports);
			break;
		}
		case 'B':
		case 'b':
		{
			string teamName,
				   sportName;
			cout << "Enter team's name: ";
			getline(cin, teamName);
			cout << "Enter sport to add this team to: ";
			getline(cin, sportName);
			for (int i = 0; i < numSports; i++)
			{
				if (sportName == sportPtr[i].getName())
				{
					sportPtr[i].addTeam(teamName);
				}
			}
			break;
		}
		case 'C':
		case 'c':
		{
			string sportName;
			cout << "Enter name of desired sport to display: ";
			getline(cin, sportName);
			cout << left << setw(20) << "SPORT NAME" << left << setw(15) << "NUMBER OF TEAMS" << right << setw(20) << "NEXT GAME" << endl;
			for (int i = 0; i < numSports; i++)
			{
				if (sportName == sportPtr[i].getName())
				{
					sportPtr[i].display();
				}
			}
			break;
		}
		case 'D':
		case 'd':
		{
			int largest = sportPtr[0].getNumTeams();
			int index = 0;
			for (int i = 0; i < numSports; i++)
			{
				if (largest < sportPtr[i].getNumTeams())
				{
					largest = sportPtr[i].getNumTeams();
					index = i;
				}
			}
			cout << left << setw(20) << "SPORT NAME" << left << setw(15) << "NUMBER OF TEAMS" << right << setw(20) << "NEXT GAME" << endl;
			sportPtr[index].display();
			break;
		}
		case 'E':
		case 'e':
		{
			return 0;
			break;
		}
		default:
		{
			cout << "You didn’t enter a choice A - E" << endl;
		}
	}
	delete[]sportPtr;
	return 0;
}

// *************************************************
// This function displays all sports
void displaySport(const Sport s[], int numS)
{
	cout << left << setw(20) << "SPORT NAME" << left << setw(15) << "NUMBER OF TEAMS" << right << setw(20) << "NEXT GAME" << endl;
	for (int i = 0; i < numS; i++)
	{
		s[i].display();
	}
}

/*
	How many sports? 2

	Enter name of sport: Soccer
	------------------------------------
	Enter month (number) of next game: 2
	Enter day of next game: 15
	Enter year of next game: 2022

	Enter number of teams for Soccer: 3
	Enter name of team 1: Ohio Panthers
	Enter name of team 2: Missouri Suns
	Enter name of team 3: Washington Magic

	Enter name of sport: Cricket
	------------------------------------
	Enter month (number) of next game: 9
	Enter day of next game: 22
	Enter year of next game: 2022

	Enter number of teams for Cricket: 2
	Enter name of team 1: White Ribbons
	Enter name of team 2: Pink Stars


	a) Display all sports
	b) Add a team to an existing sport
	c) Display a particular sport
	d) Display the sport that has the highest number of teams playing
	e) Exit

	Enter your choice: a

	SPORT NAME          NUMBER OF TEAMS           NEXT GAME
	Soccer              3                         2/15/2022
	Cricket             2                         9/22/2022

	C:\Users\avdom\OneDrive\Documents\source\repos\exercise 11\Debug\exercise 11.exe (process 11844) exited with code 0.
	Press any key to close this window . . .
--------------------------------------------------------------------------------------------------------------------------
	How many sports? 2

	Enter name of sport: Basketball
	------------------------------------
	Enter month (number) of next game: 4
	Enter day of next game: 20
	Enter year of next game: 2022

	Enter number of teams for Basketball: 3
	Enter name of team 1: Pink Stars
	Enter name of team 2: Red Lions
	Enter name of team 3: Black Hawks

	Enter name of sport: Water Polo
	------------------------------------
	Enter month (number) of next game: 9
	Enter day of next game: 16
	Enter year of next game: 2022

	Enter number of teams for Water Polo: 2
	Enter name of team 1: Ohio Suns
	Enter name of team 2: Brooklyn Magic


	a) Display all sports
	b) Add a team to an existing sport
	c) Display a particular sport
	d) Display the sport that has the highest number of teams playing
	e) Exit

	Enter your choice: b

	Enter team's name: Blue Eagles
	Enter sport to add this team to: Basketball

	C:\Users\avdom\OneDrive\Documents\source\repos\exercise 11\Debug\exercise 11.exe (process 13868) exited with code -1073741819.
	Press any key to close this window . . .
--------------------------------------------------------------------------------------------------------------------------
	How many sports? 2

	Enter name of sport: Tennis
	------------------------------------
	Enter month (number) of next game: 4
	Enter day of next game: 15
	Enter year of next game: 2022

	Enter number of teams for Tennis: 3
	Enter name of team 1: Soaring Blackhawks
	Enter name of team 2: Majestic Tigers
	Enter name of team 3: Fabulous Lemurs

	Enter name of sport: Track
	------------------------------------
	Enter month (number) of next game: 9
	Enter day of next game: 20
	Enter year of next game: 2022

	Enter number of teams for Track: 2
	Enter name of team 1: Ohio Suns
	Enter name of team 2: Missouri Nets


	a) Display all sports
	b) Add a team to an existing sport
	c) Display a particular sport
	d) Display the sport that has the highest number of teams playing
	e) Exit

	Enter your choice: c

	Enter name of desired sport to display: Tennis
	SPORT NAME          NUMBER OF TEAMS           NEXT GAME
	Tennis              3                         4/15/2022

	C:\Users\avdom\OneDrive\Documents\source\repos\exercise 11\Debug\exercise 11.exe (process 7240) exited with code 0.
	Press any key to close this window . . .
--------------------------------------------------------------------------------------------------------------------------
	How many sports? 2

	Enter name of sport: Soccer
	------------------------------------
	Enter month (number) of next game: 4
	Enter day of next game: 15
	Enter year of next game: 2022

	Enter number of teams for Soccer: 4
	Enter name of team 1: FC Barcelona
	Enter name of team 2: Real Madrid
	Enter name of team 3: Chelsea FC
	Enter name of team 4: Tottenham Hotspur

	Enter name of sport: Basketball
	------------------------------------
	Enter month (number) of next game: 9
	Enter day of next game: 20
	Enter year of next game: 2022

	Enter number of teams for Basketball: 2
	Enter name of team 1: Brooklyn Nets
	Enter name of team 2: Phoenix Suns


	a) Display all sports
	b) Add a team to an existing sport
	c) Display a particular sport
	d) Display the sport that has the highest number of teams playing
	e) Exit

	Enter your choice: d

	SPORT NAME          NUMBER OF TEAMS           NEXT GAME
	Soccer              4                         4/15/2022

	C:\Users\avdom\OneDrive\Documents\source\repos\exercise 11\Debug\exercise 11.exe (process 10816) exited with code 0.
	Press any key to close this window . . .
--------------------------------------------------------------------------------------------------------------------------
	How many sports? 2

	Enter name of sport: Soccer
	------------------------------------
	Enter month (number) of next game: 3
	Enter day of next game: 21
	Enter year of next game: 2022

	Enter number of teams for Soccer: 2
	Enter name of team 1: FC Barcelona
	Enter name of team 2: Real Madrid

	Enter name of sport: Basketball
	------------------------------------
	Enter month (number) of next game: 4
	Enter day of next game: 15
	Enter year of next game: 2022

	Enter number of teams for Basketball: 3
	Enter name of team 1: Brooklyn Nets
	Enter name of team 2: Phoenix Suns
	Enter name of team 3: Orlando Magic


	a) Display all sports
	b) Add a team to an existing sport
	c) Display a particular sport
	d) Display the sport that has the highest number of teams playing
	e) Exit

	Enter your choice: e


	C:\Users\avdom\OneDrive\Documents\source\repos\exercise 11\Debug\exercise 11.exe (process 15892) exited with code 0.
	Press any key to close this window . . .

*/