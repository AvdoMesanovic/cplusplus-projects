#pragma once
#ifndef SPORT_H
#define SPORT_H
#include <string>
using namespace std;

struct Date
{
	int month;
	int day;
	int year;
};

class Sport
{
private:
	string name;
	Date nextGame;
	int numTeams;
	string* teamNames;
public:
	Sport(const string& n = "");
	~Sport();
	string getName() const;;
	Date getDate() const;
	int getNumTeams() const;
	void setName(const string& n);
	void setDate(Date& d);
	void setNumTeams(int num);
	void display() const;
	void populate();
	void addTeam(const string& n);
};
inline
Sport::Sport(const string& n)
{
	setName(n);
}
inline
Sport::~Sport()
{
	delete[]teamNames;
}
inline
string Sport::getName()const
{
	return name;
}
inline
Date Sport::getDate() const
{
	return nextGame;
}
inline
int Sport::getNumTeams() const
{
	return numTeams;
}
inline
void Sport::setName(const string& n)
{
	name = n;
}
inline
void Sport::setNumTeams(int num)
{
	numTeams = num;
}
inline
void Sport::addTeam(const string& n)
{
	teamNames[numTeams++] = n;
}

#endif // !SPORT_H
