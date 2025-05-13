// *************************************************
// 
//  Assignment:    #10b
//  File:          american_to_english_binary.cpp
//
//  Due Date:      April 25, 2022
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
void testersUpdate(const Translation t[], int numT, const string& fileName);
void takeTest(const Translation t[], int numT, Person& p);
void displayTesters(const string& fileName);

int main()
{
	srand((unsigned)time(0));

	int numT = 0;
	int numP = 0;

	const string translationFile = "Translation.txt";
	const string testerFile = "Testers.dat";

	Translation* translationPtr = nullptr;

	translationPtr = readTranslation(translationFile, numT);

	displayTesters(testerFile);

	cout << endl;

	testersUpdate(translationPtr, numT, testerFile);

	cout << endl;

	displayTesters(testerFile);

	delete[]translationPtr;

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
	else
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
void testersUpdate(const Translation t[], int numT, const string& fileName)
{
	fstream f1;
	fstream f2;

	Person* personPtr = nullptr;
	int numP;
	Date currentDate;

	f1.open(fileName, ios::in | ios::binary);
	f1.read(reinterpret_cast<char*>(&numP), sizeof(int));
	f1.close();
	personPtr = new Person[numP];
	const int MAXRANGE = numP;

	cout << "Current month :";
	cin >> currentDate.month;
	cin.get();

	cout << "Current day :";
	cin >> currentDate.day;
	cin.get();

	cout << "Current year :";
	cin >> currentDate.year;
	cin.get();

	f2.open(fileName, ios::in | ios::out | ios::binary);

	for (int i = 0; i < 3; i++);
	{
		int randomNum = 1 + rand() % MAXRANGE;
		f2.seekg(sizeof(int) + (sizeof(Person) * randomNum), ios::beg);
		f2.read(reinterpret_cast<char*>(&personPtr[randomNum]), sizeof(Person));
		cout << endl;
		cout << "Test for " << personPtr[randomNum].name << endl;
		takeTest(t, numT, personPtr[randomNum]);
		personPtr[randomNum].testTaken = currentDate;
		f2.seekp(sizeof(int) + (sizeof(Person) * randomNum), ios::beg);
		f2.write(reinterpret_cast<char*>(&personPtr[randomNum]), sizeof(Person));
	}
	delete[]personPtr;
	f2.close();
}

// *************************************************
// This function prompts user to take the test
void takeTest(const Translation t[], int numT, Person& p)
{
	const int MAXRANGE = numT;

	int total = 0;
	double averageScore;
	int questionNum;
	string answer;

	for (int i = 0; i < 5; i++);
	{
		questionNum = rand() % MAXRANGE;
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
	averageScore = (total / 5.0);
	p.score = averageScore;
	cout << "Total score: " << total << "%" << endl;
	cout << "Average score: " << averageScore << "%" << endl;
}

// *************************************************
// This function displays the current information in the Person array 
void displayTesters(const string& fileName)
{
	int numP;
	Person p;

	fstream f;
	f.open(fileName, ios::in | ios::binary);
	f.read(reinterpret_cast<char*>(&numP), sizeof(int));
	cout << left << setw(20) << "NAME" << left << setw(15) << "SCORE" << "TEST TAKEN" << endl;
	for (int i = 0; i < numP; i++)
	{
		cout << left << setw(20) << p.name;
		cout << left << setw(15) << p.score;
		cout << right << setw(1) << p.testTaken.month << "/" << right << setw(1) << p.testTaken.day << "/" << right << setw(1) << p.testTaken.year;
		cout << endl;
	}
}