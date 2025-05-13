// *************************************************
// 
//  Assignment:    #7a
//  File:          speaker_structures(a).cpp
//
//  Due Date:      March 28, 2022
//
//  Author:        Avdo Mesanovic 
//
//  Course Name:   Programming II 
//
//  Course Number: COSC 1560 
//
//  Description:   This program keeps track of the 
//				   information of a speakers' bureau
//				   
// *************************************************

#include <iostream>
#include <string>
using namespace std;

struct Speaker
{
	string name;
	string phoneNumber;
	string topic;
	double fee;
};

void inputSpeakers(Speaker members[], int size, int& numSpeakers);
void updateSpeaker(Speaker members[], int numSpeakers, const string& speakerName);
void displayOneSpeaker(Speaker members[], int numSpeakers, const string& speakerName);
void displayTopic(Speaker members[], int numSpeakers, const string& speakersTopic);
void displayAllSpeakers(Speaker members[], int numSpeakers);

int main()
{
	string updateSpeakerName,
		   displaySpeaker,
		   displaySpeakerTopic;

	const int size = 10;
	int numSpeakers;

	Speaker members[size];

	inputSpeakers(members, size, numSpeakers);

	cout << "Name of the speaker whose information you would like to update: ";
	getline(cin, updateSpeakerName);
	updateSpeaker(members, numSpeakers, updateSpeakerName);
	cin.get();
	cout << endl;

	cout << "Name of the speaker whose information you would like to display: ";
	getline(cin, displaySpeaker);
	displayOneSpeaker(members, numSpeakers, displaySpeaker);
	cout << endl;

	cout << "Topic you would like to use to filter speakers: ";
	getline(cin, displaySpeakerTopic);
	displayTopic(members, numSpeakers, displaySpeakerTopic);

	displayAllSpeakers(members, numSpeakers);

	return 0;
}

// *************************************************
// This function allows user to enter data for speakers
void inputSpeakers(Speaker members[], int size, int& numSpeakers)
{
	cout << "Enter the number of speakers (less than 10): ";
	cin >> numSpeakers;
	while (numSpeakers > 10)
	{
		cout << "[ERROR] Please enter a number less than 10: ";
		cin >> numSpeakers;
	}
	cin.get();
	cout << endl;
	for (int i = 0; i < numSpeakers; i++)
	{
		cout << "Name of speaker " << i + 1 << ": ";
		getline(cin, members[i].name);
		while (members[i].name.empty())
		{
			cout << "[ERROR] Please enter a name: ";
			getline(cin, members[i].name);
		}
		cout << "Phone number of speaker " << i + 1 << ": ";
		getline(cin, members[i].phoneNumber);
		while (members[i].phoneNumber.empty())
		{
			cout << "[ERROR] Please enter a phone number: ";
			getline(cin, members[i].phoneNumber);
		}
		cout << "Topic of speaker " << i + 1 << ": ";
		getline(cin, members[i].topic);
		while (members[i].topic.empty())
		{
			cout << "[ERROR] Please enter a topic: ";
			getline(cin, members[i].topic);
		}
		cout << "Fee for speaker " << i + 1 << ": $";
		cin >> members[i].fee;
		while (members[i].fee < 0)
		{
			cout << "Please enter a positive fee: $";
			cin >> members[i].fee;
		}
		cin.get();
		cout << endl;
	}
}

// *************************************************
// This function allows user to update the information of a speaker
void updateSpeaker(Speaker members[], int numSpeakers, const string& speakerName)
{
	for (int i = 0; i < numSpeakers; i++)
	{
		if (members[i].name == speakerName)
		{
			cout << "Update name of speaker " << i + 1 << ": ";
			getline(cin, members[i].name);
			while (members[i].name.empty())
			{
				cout << "[ERROR] Please enter a name: ";
				getline(cin, members[i].name);
			}
			cout << "Update phone number of speaker " << i + 1 << ": ";
			getline(cin, members[i].phoneNumber);
			while (members[i].phoneNumber.empty())
			{
				cout << "[ERROR] Please enter a phone number: ";
				getline(cin, members[i].phoneNumber);
			}
			cout << "Update topic of speaker " << i + 1 << ": ";
			getline(cin, members[i].topic);
			while (members[i].topic.empty())
			{
				cout << "[ERROR] Please enter a topic: ";
				getline(cin, members[i].topic);
			}
			cout << "Update fee for speaker " << i + 1 << ": $";
			cin >> members[i].fee;
			while (members[i].fee < 0)
			{
				cout << "Please enter a positive fee: $";
				cin >> members[i].fee;
			}
		}
	}
}

// *************************************************
// This function displays the information of a specified speaker
void displayOneSpeaker(Speaker members[], int numSpeakers, const string& speakerName)
{
	for (int i = 0; i < numSpeakers; i++)
	{
		if (members[i].name == speakerName)
		{
			cout << "Speaker " << i + 1 << endl;
			cout << "---------" << endl;
			cout << members[i].name << endl;
			cout << members[i].phoneNumber << endl;
			cout << members[i].topic << endl;
			cout << "$" << members[i].fee << endl;
		}
	}
}

// *************************************************
// This function displays all the speakers speaking about a specified topic
void displayTopic(Speaker members[], int numSpeakers, const string& speakersTopic)
{
	int searchCounter = 0;
	for (int i = 0; i < numSpeakers; i++)
	{
		if (members[i].topic == speakersTopic)
		{
			cout << "Speaker " << i + 1 << endl;
			cout << "---------" << endl;
			cout << members[i].name << endl;
			cout << members[i].phoneNumber << endl;
			cout << members[i].topic << endl;
			cout << "$" << members[i].fee << endl;
			cout << endl;
			searchCounter++;
		}
	}
	if (searchCounter == 0)
	{
		cout << "[ERROR] No one is speaking about that topic" << endl << endl;
	}
}

// *************************************************
// This function displays all information stored in the array
void displayAllSpeakers(Speaker members[], int numSpeakers)
{
	cout << "All speakers:" << endl;
	for (int i = 0; i < numSpeakers; i++)
	{
		cout << "Speaker " << i + 1 << endl;
		cout << "---------" << endl;
		cout << "Name: " << members[i].name << endl;
		cout << "Phone Number: " << members[i].phoneNumber << endl;
		cout << "Topic: " << members[i].topic << endl;
		cout << "Fee: $" << members[i].fee << endl;
		cout << endl;
	}
}

/*
Enter the number of speakers (less than 10): 11
[ERROR] Please enter a number less than 10: 3

Name of speaker 1: Avdo Mesanovic
Phone number of speaker 1: 314-728-5281
Topic of speaker 1: War Tactics
Fee for speaker 1: $30

Name of speaker 2: Clinton Davis
Phone number of speaker 2: 609-404-1548
Topic of speaker 2: Ecosystem Preservation
Fee for speaker 2: $-1
Please enter a positive fee: $10

Name of speaker 3: Sylvia Ashwell
Phone number of speaker 3: 314-599-6730
Topic of speaker 3: Journalism Strategies
Fee for speaker 3: $50

Name of the speaker whose information you would like to update: Clinton Davis
Update name of speaker 2:
[ERROR] Please enter a name: Mark Danforth
Update phone number of speaker 2: 257-349-6049
Update topic of speaker 2: War Tactics
Update fee for speaker 2: $15

Name of the speaker whose information you would like to display: Sylvia Ashwell
Speaker 3
---------
Sylvia Ashwell
314-599-6730
Journalism Strategies
$50

Topic you would like to use to filter speakers: War Tactics
Speaker 1
---------
Avdo Mesanovic
314-728-5281
War Tactics
$30

Speaker 2
---------
Mark Danforth
257-349-6049
War Tactics
$15

All speakers:
Speaker 1
---------
Name: Avdo Mesanovic
Phone Number: 314-728-5281
Topic: War Tactics
Fee: $30

Speaker 2
---------
Name: Mark Danforth
Phone Number: 257-349-6049
Topic: War Tactics
Fee: $15

Speaker 3
---------
Name: Sylvia Ashwell
Phone Number: 314-599-6730
Topic: Journalism Strategies
Fee: $50


C:\Users\avdom\OneDrive\Documents\source\repos\exercise 7a\Debug\exercise 7a.exe (process 13012) exited with code 0.
Press any key to close this window . . .
--------------------------------------------------------------------------------------------------------------------
Enter the number of speakers (less than 10): 3

Name of speaker 1: Avdo Mesanovic
Phone number of speaker 1: 314-728-5281
Topic of speaker 1: War Tactics
Fee for speaker 1: $30

Name of speaker 2: Clinton Davis
Phone number of speaker 2: 609-404-1548
Topic of speaker 2: Ecosystem Preservation
Fee for speaker 2: $10

Name of speaker 3: Sylvia Ashwell
Phone number of speaker 3: 314-599-6730
Topic of speaker 3: Journalism Strategies
Fee for speaker 3: $50

Name of the speaker whose information you would like to update: Clinton Davis
Update name of speaker 2: Mark Danforth
Update phone number of speaker 2: 257-349-6049
Update topic of speaker 2: War Tactics
Update fee for speaker 2: $15

Name of the speaker whose information you would like to display: Sylvia Ashwell
Speaker 3
---------
Sylvia Ashwell
314-599-6730
Journalism Strategies
$50

Topic you would like to use to filter speakers: Conserving Energy
[ERROR] No one is speaking about that topic

All speakers:
Speaker 1
---------
Name: Avdo Mesanovic
Phone Number: 314-728-5281
Topic: War Tactics
Fee: $30

Speaker 2
---------
Name: Mark Danforth
Phone Number: 257-349-6049
Topic: War Tactics
Fee: $15

Speaker 3
---------
Name: Sylvia Ashwell
Phone Number: 314-599-6730
Topic: Journalism Strategies
Fee: $50


C:\Users\avdom\OneDrive\Documents\source\repos\exercise 7a\Debug\exercise 7a.exe (process 17868) exited with code 0.
Press any key to close this window . . .
*/