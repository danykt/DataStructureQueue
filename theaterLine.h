#pragma once
#pragma once

#include <queue>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class theater
{

private:
	queue<string> q;
	int MAX;

public:
	theater();
	theater(int max);
	int getMax();
	int getNumOfPatrons();
	void addPatron(string p);
	string removePatron();


};

theater::theater()
{
	MAX = 5;
}
theater::theater(int max)
{
	MAX = max;
}
int theater::getMax()
{
	return MAX;
}
int theater::getNumOfPatrons()
{
	return q.size();
}
void theater::addPatron(string p)
{
	int size = q.size();
	if (size < MAX)
	{
		cout << p << " is entering the line." << endl;
		q.push(p);
		
	}
	else
		cout << "The line has overflown!. Patron " << p << " was turned away!" << endl;
}
string theater::removePatron()
{
	if (q.empty())
	{
		return "";
	}
	else
	{
		string val = q.front();
		q.pop();
		
		return val;
	}
}