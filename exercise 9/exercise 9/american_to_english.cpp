// *************************************************
// 
//  Assignment:    #9
//  File:          american_to_english.cpp
//
//  Due Date:      April 18, 2022
//
//  Author:        Avdo Mesanovic 
//
//  Course Name:   Programming II 
//
//  Course Number: COSC 1560 
//
//  Description:   This program enables people to learn how
//				   to translate from American to English
//				   
// *************************************************

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Translation
{
	string american; // A word in American 
	string english;  // The equivalent (proper) word in English 
};
struct Date
{
	int day;
	int month;
	int year;
};
struct Person
{
	char name[20];
	double score;
	Date testTaken;
};

Translation* readTranslation(const string& fileName, int& num);
Person* readTesters(const string& fileName, int& num);
void testingOptions(const Translation t[], int numT, Person people[], int numP);
void takeTest(const Translation t[], int numT, Person& p);
void displayTesters(const Person p[], int numP);
void writeTesters(const string& fileName, const Person p[], int numP);

int main()
{
	int numT = 0;
	int numP = 0;
	int currentTestNum;

	const string translationFile = "Translation.txt";
	const string testerFile = "Testers.txt";
	
	Translation* translationPtr = nullptr;
	Person* personPtr = nullptr;


	translationPtr = readTranslation(translationFile, numT);

	personPtr = readTesters(testerFile, numP);

	testingOptions(translationPtr, numT, personPtr, numP);
	
	cout << endl;
	
	cout << "Who is the current tester? (1-10): ";
	cin >> currentTestNum;
	cin.get();
	takeTest(translationPtr, numT, personPtr[currentTestNum - 1]);

	cout << endl;

	displayTesters(personPtr, numP);

	writeTesters(testerFile, personPtr, numP);

	delete[]translationPtr;
	delete[]personPtr;

	return 0;
}

// *************************************************
// This function returns a pointer to the array allocated to store the translations read from the file
Translation* readTranslation(const string& fileName, int& numT)
{
	Translation* translationPtr = nullptr;
	fstream f;
	f.open(fileName, ios::in);
	f >> numT;
	f.get();
	translationPtr = new Translation[numT];
	if (!f)
	{
		cout << "Error opening file" << endl;
		return 0;
	}
	if (f)
	{
		for (int i = 0; i < numT; i++)
		{
			getline(f, translationPtr[i].american, ',');
			getline(f, translationPtr[i].english);
		}
	}
	f.close();

	return translationPtr;
}

// *************************************************
// This function returns a pointer to the array allocated to store the testers read from the file
Person* readTesters(const string& fileName, int& numP)
{
	Person* personPtr = nullptr;
	fstream f;
	f.open(fileName, ios::in);
	f >> numP;
	f.get();
	personPtr = new Person[numP];
	if (!f)
	{
		cout << "Error opening file" << endl;
		return 0;
	}
	if (f)
	{
		for (int i = 0; i < numP; i++)
		{
			f.getline(personPtr[i].name, 20);
			f >> personPtr[i].score;
			f.get();
			f >> personPtr[i].testTaken.month;
			f.get();
			f >> personPtr[i].testTaken.day;
			f.get();
			f >> personPtr[i].testTaken.year;
			f.get();
		}
	}
	f.close();

	return personPtr;
}

// *************************************************
// This function prompts user to take the test
void takeTest(const Translation t[], int numT, Person& p)
{
	int total = 0;
	int averageScore;
	int questionNum;
	string answer;

	for (int i = 0; i < 5; i++);
	{
		cout << "Select a number from 1 - 20: ";
		cin >> questionNum;
		cin.get();
		cout << endl;
		cout << "Question #" << questionNum << ": " << "What is the translation for " << t[questionNum - 1].american << "?" << endl;
		getline(cin, answer);
		if (answer == t[questionNum - 1].english)
		{
			cout << "[CORRECT] +1 point " << endl;
			cout << endl;
			++total;
		}
		else
		{
			cout << "[WRONG] +0 points " << endl;
			cout << endl;
		}
	}

	averageScore = (total / 5);
	cout << "Total score: %" << total << endl;
	cout << "Average score: %" << averageScore << endl;
	p.score = averageScore;
}

// *************************************************
// This function prompts the user to enter the current date, so that it can be used for any updates
void testingOptions(const Translation t[], int numT, Person people[], int numP)
{
	srand((unsigned)time(0));

	const int MAXRANGE = numP; 

	for (int i = 0; i < 3; i++);
	{
		int randomPerson = rand() % MAXRANGE; // range is 0 to numP - 1
		cout << people[randomPerson].name << "has been chosen \n";
		cout << "Enter the date test was taken using XX/XX/XXXX format: ";
		cin >> people[randomPerson].testTaken.month;
		cin.get();
		cin >> people[randomPerson].testTaken.day;
		cin.get();
		cin >> people[randomPerson].testTaken.year;
		cin.get();
		cout << endl;
		takeTest(t, numT, people[randomPerson]);
	}
}

// *************************************************
// This function displays the current information in the Person array 
void displayTesters(const Person p[], int numP)
{
	cout << left << setw(20) << "NAME" << left << setw(15) << "SCORE" << "TEST TAKEN" <<  endl;
	for (int i = 0; i < numP; i++)
	{
		cout << left << setw(20) << p[i].name;
		cout << left << setw(15) << p[i].score;
		cout << right << setw(1) << p[i].testTaken.month << "/" << right << setw(1) << p[i].testTaken.day << "/" << right << setw(1) << p[i].testTaken.year;
		cout << endl;
	}
}

// *************************************************
// This function allows user to update the Person array and writes the updated array to the file
void writeTesters(const string& fileName, const Person p[], int numP)
{
	fstream f;
	f.open(fileName, ios::out);
	f << numP << endl;
	for (int i = 0; i < numP; i++)
	{
		f << p[i].name << endl;
		f << p[i].score << "," << p[i].testTaken.month << "/" << p[i].testTaken.day << "/" << p[i].testTaken.year << endl;
	}
	f.close();
}