#include "Sport.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

void Sport::setDate (Date& d)
{
	nextGame = d;

	if ((d.month < 1) || (d.month > 12))
	{
		d.month = 1;
	}

	if ((d.day < 1) || (d.day > 30))
	{
		d.day = 1;
	}

	if ((d.year < 1000) || (d.day > 9999))
	{
		d.year = 2000;
	}
}

void Sport::display() const
{
	cout << left << setw(20) << getName();
	cout << left << setw(15) << getNumTeams();
	cout << right << setw(12) << getDate().month << "/" << right << setw(1) << getDate().day << "/" << right << setw(1) << getDate().year;
	cout << endl;
}

void Sport::populate()
{
	Date d;
	string n;
	int num;

	cout << "Enter name of sport: ";
	getline(cin, n);
	setName(n);

	cout << "------------------------------------" << endl;

	cout << "Enter month (number) of next game: ";
	cin >> d.month;
	cin.get();
	cout << "Enter day of next game: ";
	cin >> d.day;
	cin.get();
	cout << "Enter year of next game: ";
	cin >> d.year;
	cin.get();
	setDate(d);

	cout << endl;

	cout << "Enter number of teams for " << n << ": ";
	cin >> num;
	cin.get();
	setNumTeams(num);
	teamNames = new string[numTeams];
	for (int i = 0; i < num; i++)
	{
		cout << "Enter name of team " << i + 1 << ": ";
		getline(cin, teamNames[i]);
	}
}


