//*****************************************************************************************************
//
//		File:					studentList.cpp
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #12
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-01
//
//		Due:					May 5th, 2023
//
//		This program explores the Doubly Linked List data structure and utilizes several
//	    functions to employ it.
//	
//		Other files required: 
//			1. DLList.h - definition of the DLList class
//			2. student.h - definition of the Student structure
//			3. studentFile.txt - text file of student records used for input
//			
//*****************************************************************************************************

#include <iostream>
#include <fstream>

using namespace std;

#include "student.h"
#include "DLList.h"

//*****************************************************************************************************

char getChoice();
void process(DLList<Student>& studentList);
void buildList(DLList<Student>& studentList);
void displayStudents(DLList<Student>& studentList);
void displayStudentsRev(DLList<Student>& studentList);

void countStudents(DLList<Student>& studentList);
void addNewStudent(DLList<Student>& studentList);
void removeStudent(DLList<Student>& studentList);
void findStudent(DLList<Student>& studentList);

//*****************************************************************************************************

int main()
{
	DLList<Student> studentList;

	buildList(studentList);
	process(studentList);

	return 0;
}

//*****************************************************************************************************

char getChoice()
{
	char choice;
	bool valid;

	cout << "======== MENU ======== \n"
	   	 << " A: Add a new Student \n"
		 << " F: Find a Student Record \n"
		 << " R: Remove a Student Record \n"
		 << " C: Count all Students in Student Record \n"
		 << " D: Display all Student Records \n"
		 << " V: Display all Student Records in reverse \n"
		 << " Q: Quit		\n\n"
		 << "Enter your choice: ";

	do
	{
		cin >> choice;
		choice = toupper(choice);

		switch (choice)
		{
		case 'A': 
		case 'F':
		case 'R':
		case 'D':
		case 'C':
		case 'V':
		case 'Q':
			valid = true;
			break;
		default:
			valid = false;
			cout << "\aInvalid choice\n\n" << "Please try again: ";
			break;
		}
	} 
	while (!valid);

	return choice;
}

//*****************************************************************************************************

void process(DLList<Student>& studentList)
{
	char choice;

	do
	{
		choice = getChoice();

		switch (choice)
		{
		case 'A': 
			addNewStudent(studentList);
			break;
		case 'F':
			findStudent(studentList);
			break;
		case 'R':
			removeStudent(studentList);
			break;
		case 'D':
			displayStudents(studentList);
			break;
		case 'C':
			countStudents(studentList);
			break;
		case 'V':
			displayStudentsRev(studentList);
			break;
		case 'Q':
			break;
		}
	} 
	while (choice != 'Q');
}

//*****************************************************************************************************

void buildList(DLList<Student>& studentList)
{
	Student student;
	ifstream studentData;

	studentData.open("studentFile.txt");

	while (studentData >> student.id)
	{
		studentData.ignore();
		studentData.getline(student.name, 50);
		studentData.getline(student.citystate, 50);
		studentData >> student.phone
					>> student.gender
					>> student.year
					>> student.credits
					>> student.gpa
					>> student.major;

		studentList.insert(student);
	}

	studentData.close();
}

//*****************************************************************************************************

void displayStudents(DLList<Student>& studentList)
{
	cout << "\t\tSTUDENT LIST" << endl;
	cout << "====================================================" << endl;
	cout << " ID\tNAME\t\t\t\tMAJOR\tGPA" << endl;
	cout << "====================================================" << endl << " ";
	studentList.display();
	cout << endl << endl;
}

//*****************************************************************************************************

void displayStudentsRev(DLList<Student>& studentList)
{
	cout << "\t\tREVERSE STUDENT LIST" << endl;
	cout << "====================================================" << endl;
	cout << " ID\tNAME\t\t\t\tMAJOR\tGPA" << endl;
	cout << "====================================================" << endl << " ";
	studentList.displayReverse();
	cout << endl << endl;
}

//*****************************************************************************************************

void countStudents(DLList<Student>& studentList)
{
	int temp;
	temp = studentList.getNumValues();

	cout << "Number of Students is " << temp << endl << endl;
}

//*****************************************************************************************************


void addNewStudent(DLList<Student>& studentList)
{
	Student temp;

	cout << "Enter the ID of the Student to be added: ";
	cin >> temp.id;
	cin.ignore();

	cout << "Enter the name of the Student to be added: ";
	cin.getline(temp.name, 50);

	cout << "Enter the city-state of the Student to be added: ";
	cin.getline(temp.citystate, 50);

	cout << "Enter the phone number of the Student to be added: ";
	cin >> temp.phone;

	cout << "Enter the gender of the Student to be added: ";
	cin >> temp.gender;

	cout << "Enter the year of the Student to be added: ";
	cin >> temp.year;

	cout << "Enter the credits of the Student to be added: ";
	cin >> temp.credits;

	cout << "Enter the gpa of the Student to be added: ";
	cin >> temp.gpa;

	cout << "Enter the major of the Student to be added: ";
	cin >> temp.major;

	if (studentList.insert(temp))
	{
		cout << temp;
		cout << "Student has been succesfully added!" << endl << endl;
	}
	else
	{
		cout << "Student was not able to be added" << endl << endl;
	}
}

//*****************************************************************************************************

void removeStudent(DLList<Student>& studentList)
{
	Student temp;

	cout << "Enter the ID of the Student to be removed: ";
	cin >> temp.id;

	if (studentList.remove(temp))
	{
		cout << temp;
		cout << "Student Record has successfully been removed!" << endl << endl;
	}
	else
	{
		cout << "Student Record was not able to be removed" << endl << endl;
	}
}

//*****************************************************************************************************

void findStudent(DLList<Student>& studentList)
{
	Student temp;

	cout << "Enter the ID of the Student Record you wish to view: ";
	cin >> temp.id;

	if (studentList.retrieve(temp))
	{
		cout << temp;
	}
	else
	{
		cout << "Unable to find that Student Record" << endl << endl;
	}
}

//*****************************************************************************************************

//======== MENU ========
// A: Add a new Student
// F: Find a Student Record
// R: Remove a Student Record
// C: Count all Students in Student Record
// D: Display all Student Records
// V: Display all Student Records in reverse
// Q: Quit
//
//Enter your choice: v
//                REVERSE STUDENT LIST
//====================================================
// ID     NAME                            MAJOR   GPA
//====================================================
// 32631  Freud, JR, Fred E               PSYC    1.85
// 32598  Xerxes, Art I                   GREE    3.25
// 31631  Aristotle, Alice A              PHIL    3.1
// 30878  Lewis, Clark N                  GEOG    3.37
// 30749  Mendelssohn, Mozart W           MUSC    2.87
// 30655  Angelo, Mike L                  ART     3.74
// 30381  Elba, Able M                    SPEE    3.4
// 30280  Dewey, Johanna A                EDUC    3.83
// 30268  Newmann, Alfred E               EDUC    0.99
// 29583  Yewliss, Cal C                  MATH    2.99
// 28658  Cicero, Marsha                  LATI    2.87
// 27503  Fahrenheit, Felicia O           CHEM    3.85
// 26316  Custer, General G               HIST    1.95
// 25831  Santamaria, Nina P              HIST    1.77
// 25377  Porgy, Bess N                   MUSI    2.78
// 24237  Euler, Lennie L                 MATH    3.83
// 23750  Vespucci, Vera D                GEOG    2.29
// 23544  Gestalt, Gloria G               PSYC    2.48
// 23497  Fault, Paige D                  CPSC    2.95
// 23314  Macdonald, Ronald B             CPSC    2.99
// 22447  Zylstra, Zelda A                ENGL    1.95
// 22277  Principal, Pamela P             EDUC    1.75
// 21144  Pasteur, Louise A               BIOL    3.1
// 20991  Augusta, Ada B                  CPSC    3.83
// 20454  Chicita, Juanita A              BIOL    2.66
// 19918  Virus, Vera W                   CPSC    3.25
// 19077  Medes, Archie L                 ENGR    3.1
// 18264  Lucky, Lucy L                   HIST    2.29
// 18213  Marx, Karl Z                    ECON    2.75
// 17424  Nakamura, Toky O                SOCI    1.95
// 17376  Scrooge, Ebenezer T             SOCI    3.25
// 16622  Issacson, Esau B                RELI    2.98
// 16540  Weerd, Dewey L                  PHIL    2.99
// 16183  Kuts, Cole                      FOOD    3.98
// 15889  Gazelle, Gwendolyn D            PE      2.78
// 15802  Pascal, Blaze R                 CPSC    1.98
// 15755  VandenVander, Vanessa V         HIST    3.74
// 15671  Rembrandt, Roberta E            ART     2.2
// 15052  Einstein, Alfred M              ENGR    2.78
// 14815  Tchaikovsky, Wolfgang A         MUSC    2.75
// 14674  Rockne, Newton K                PE      1.98
// 13511  Pitt, Stew                      GNED    0.21
// 11951  Mouse, Michael E                EDUC    1.99
// 11749  Issacson, Jacob A               RELI    2.99
// 11688  Kronecker, Leo P                MATH    2.75
// 10304  Deutsch, Sprechen Z             GERM    3.05
// 10236  Andrews, Peter J                CPSC    2.78
// 9743   Johnson, James L                ENGR    3.15
// 9463   Hochschule, Hortense C          EDUC    2.7
// 7885   Fibonacci, Leonard O            MATH    3.25
// 7844   Aardvark, Anthony A             ENGR    2.79
// 7448   Roosevelt, Rose Y               POLS    2.95
// 7107   Shoemaker, Imelda M             POLS    3.15
// 5873   Psycho, II,  Prunella E         PSYC    2.99
// 5710   Busch, Arch E                   ENGR    2.75
// 5430   Nightingale, Florence K         NURS    3.15
// 5316   GotoDijkstra, Edgar G           CPSC    4
// 4777   Gauss, Carl F                   MATH    4
// 4559   Shyster, Samuel D               SOCI    1.95
// 4454   Atanasoff, Eniac C              CPSC    1.88
// 3930   Leibniz, Gottfried W            MATH    1.95
//
//
//======== MENU ========
// A: Add a new Student
// F: Find a Student Record
// R: Remove a Student Record
// C: Count all Students in Student Record
// D: Display all Student Records
// V: Display all Student Records in reverse
// Q: Quit
//
//Enter your choice: q
//
//C:\Users\avdom\OneDrive\Documents\source\repos\data structures 1\assignment 12\x64\Debug\assignment 12.exe (process 4480) exited with code 0.
//Press any key to close this window . . .