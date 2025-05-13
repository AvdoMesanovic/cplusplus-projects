// *************************************************
// 
//  Assignment:    #7b
//  File:          speaker_structures(b).cpp
//
//  Due Date:      March 28, 2022
//
//  Author:        Avdo Mesanovic 
//
//  Course Name:   Programming II 
//
//  Course Number: COSC 1560 
//
//  Description:   This program is a modification of the 
//				   previous program, speaker_structures(a)
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

void inputSpeakers(Speaker* speakersPtr, const int numSpeakers);
void updateSpeaker(Speaker* speakersPtr, int numSpeakers, const string& speakerName);
void displayOneSpeaker(Speaker* speakersPtr, int numSpeakers, const string& speakerName);
void displayTopic(Speaker* speakersPtr, int numSpeakers, const string& speakersTopic);
void displayAllSpeakers(Speaker* speakersPtr, int numSpeakers);

int main()
{
	string updateSpeakerName,
		   displaySpeaker,
		   displaySpeakerTopic;

	Speaker* speakersPtr = nullptr;

	int numSpeakers;

	cout << "Enter number of speakers: ";
	cin >> numSpeakers;
	speakersPtr = new Speaker[numSpeakers];
	cin.get();
	cout << endl;

	inputSpeakers(speakersPtr, numSpeakers);

	cout << "Name of the speaker whose information you would like to update: ";
	getline(cin, updateSpeakerName);
	updateSpeaker(speakersPtr, numSpeakers, updateSpeakerName);
	cin.get();
	cout << endl;

	cout << "Name of the speaker whose information you would like to display: ";
	getline(cin, displaySpeaker);
	displayOneSpeaker(speakersPtr, numSpeakers, displaySpeaker);
	cout << endl;

	cout << "Topic you would like to use to filter speakers: ";
	getline(cin, displaySpeakerTopic);
	displayTopic(speakersPtr, numSpeakers, displaySpeakerTopic);

	displayAllSpeakers(speakersPtr, numSpeakers);

	delete[]speakersPtr;

	return 0;
}

// *************************************************
// This function allows user to enter data for speakers
void inputSpeakers(Speaker* speakersPtr, int numSpeakers)
{
	for (int i = 0; i < numSpeakers; i++)
	{
		cout << "Name of speaker " << i + 1 << ": ";
		getline(cin, speakersPtr[i].name);
		while (speakersPtr[i].name.empty())
		{
			cout << "[ERROR] Please enter a name: ";
			getline(cin, speakersPtr[i].name);
		}
		cout << "Phone number of speaker " << i + 1 << ": ";
		getline(cin, speakersPtr[i].phoneNumber);
		while (speakersPtr[i].phoneNumber.empty())
		{
			cout << "[ERROR] Please enter a phone number: ";
			getline(cin, speakersPtr[i].phoneNumber);
		}
		cout << "Topic of speaker " << i + 1 << ": ";
		getline(cin, speakersPtr[i].topic);
		while (speakersPtr[i].topic.empty())
		{
			cout << "[ERROR] Please enter a topic: ";
			getline(cin, speakersPtr[i].topic);
		}
		cout << "Fee for speaker " << i + 1 << ": $";
		cin >> speakersPtr[i].fee;
		while (speakersPtr[i].fee < 0)
		{
			cout << "Please enter a positive fee: $";
			cin >> speakersPtr[i].fee;
		}
		cin.get();
		cout << endl;
	}
}

// *************************************************
// This function allows user to update the information of a speaker
void updateSpeaker(Speaker* speakersPtr, int numSpeakers, const string& speakerName)
{
	for (int i = 0; i < numSpeakers; i++)
	{
		if (speakersPtr[i].name == speakerName)
		{
			cout << "Update name of speaker " << i + 1 << ": ";
			getline(cin, speakersPtr[i].name);
			while (speakersPtr[i].name.empty())
			{
				cout << "[ERROR] Please enter a name: ";
				getline(cin, speakersPtr[i].name);
			}
			cout << "Update phone number of speaker " << i + 1 << ": ";
			getline(cin, speakersPtr[i].phoneNumber);
			while (speakersPtr[i].phoneNumber.empty())
			{
				cout << "[ERROR] Please enter a phone number: ";
				getline(cin, speakersPtr[i].phoneNumber);
			}
			cout << "Update topic of speaker " << i + 1 << ": ";
			getline(cin, speakersPtr[i].topic);
			while (speakersPtr[i].topic.empty())
			{
				cout << "[ERROR] Please enter a topic: ";
				getline(cin, speakersPtr[i].topic);
			}
			cout << "Update fee for speaker " << i + 1 << ": $";
			cin >> speakersPtr[i].fee;
			while (speakersPtr[i].fee < 0)
			{
				cout << "Please enter a positive fee: $";
				cin >> speakersPtr[i].fee;
			}
		}
	}
}

// *************************************************
// This function displays the information of a specified speaker
void displayOneSpeaker(Speaker* speakersPtr, int numSpeakers, const string& speakerName)
{
	for (int i = 0; i < numSpeakers; i++)
	{
		if (speakersPtr[i].name == speakerName)
		{
			cout << "Speaker " << i + 1 << endl;
			cout << "---------" << endl;
			cout << speakersPtr[i].name << endl;
			cout << speakersPtr[i].phoneNumber << endl;
			cout << speakersPtr[i].topic << endl;
			cout << "$" << speakersPtr[i].fee << endl;
		}
	}
}

// *************************************************
// This function displays all the speakers speaking about a specified topic
void displayTopic(Speaker* speakersPtr, int numSpeakers, const string& speakersTopic)
{
	int searchCounter = 0;
	for (int i = 0; i < numSpeakers; i++)
	{
		if (speakersPtr[i].topic == speakersTopic)
		{
			cout << "Speaker " << i + 1 << endl;
			cout << "---------" << endl;
			cout << speakersPtr[i].name << endl;
			cout << speakersPtr[i].phoneNumber << endl;
			cout << speakersPtr[i].topic << endl;
			cout << "$" << speakersPtr[i].fee << endl;
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
void displayAllSpeakers(Speaker* speakersPtr, int numSpeakers)
{
	cout << "All speakers:" << endl;
	for (int i = 0; i < numSpeakers; i++)
	{
		cout << "Speaker " << i + 1 << endl;
		cout << "---------" << endl;
		cout << "Name: " << speakersPtr[i].name << endl;
		cout << "Phone Number: " << speakersPtr[i].phoneNumber << endl;
		cout << "Topic: " << speakersPtr[i].topic << endl;
		cout << "Fee: $" << speakersPtr[i].fee << endl;
		cout << endl;
	}
}

/*
Enter number of speakers: 2

Name of speaker 1: Avdo Mesanovic
Phone number of speaker 1: 314-728-5281
Topic of speaker 1: War Tactics
Fee for speaker 1: $30

Name of speaker 2: Dettlaff van der Eretein
Phone number of speaker 2: 609-511-2037
Topic of speaker 2: Ecosystem Preservation
Fee for speaker 2: $50

Name of the speaker whose information you would like to update: Avdo Mesanovic
Update name of speaker 1: Joe Smith
Update phone number of speaker 1: 314-222-2222
Update topic of speaker 1: Rocket Science
Update fee for speaker 1: $20

Name of the speaker whose information you would like to display: Joe Smith
Speaker 1
---------
Joe Smith
314-222-2222
Rocket Science
$20

Topic you would like to use to filter speakers: Computer Structures
[ERROR] No one is speaking about that topic

All speakers:
Speaker 1
---------
Name: Joe Smith
Phone Number: 314-222-2222
Topic: Rocket Science
Fee: $20

Speaker 2
---------
Name: Dettlaff van der Eretein
Phone Number: 609-511-2037
Topic: Ecosystem Preservation
Fee: $50


C:\Users\avdom\OneDrive\Documents\source\repos\exercise 7b\Debug\exercise 7b.exe (process 17160) exited with code 0.
Press any key to close this window . . .
*/
