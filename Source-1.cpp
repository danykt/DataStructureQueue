#include <iostream>
#include "theaterLine.h"
using namespace std;



void simulateMovie(int startHour, int starMin, int lineSize, string title, ifstream &fs);
int main()
{
	string filename = "E:\\theaterLine\\theaterLine\\lab4_testOne.txt";
	string line;
	ifstream myFile;
	myFile.open(filename);
	if (myFile.fail())
		cout << "could not open file" << endl;
	if (myFile.is_open())
	{
		getline(myFile, line);
	}
	stringstream lineStream(line);
	int hour, min, lineSize;
	string title;
	string word;
	lineStream >> hour;
	lineStream >> min;
	lineStream >> lineSize;

	while (lineStream >> word)
	{
		title += word + " ";
	}

	simulateMovie(hour, min, lineSize, title, myFile);
	myFile.close();

}


void processLine(string &line, int &readHour, int &readMin, string &patron, theater &t)
{
	stringstream lineStream(line);
	lineStream >> readHour;
	lineStream >> readMin;
	lineStream >> patron;
	t.addPatron(patron);
	while (lineStream >> patron)
	{
		cout << "        ";
		t.addPatron(patron);
		
	}
	
}
void getTime(string &line, int &readHour, int &readMin)
{
	stringstream lineStream(line);
	lineStream >> readHour;
	lineStream >> readMin;
}
void processTime(int &hour, int &min)
{
	if (min + 1 > 59)
	{
		min = 0;
		hour++;
	}
	else
		min++;
}

void simulateMovie(int startHour, int startMin, int lineSize, string title, ifstream &fs)
{

	if (startHour == 0)
	{
		startHour = 24;
	}
	else if (startHour == 1)
	{
		startHour = 25;
	}
	cout << "Starting simulation for " << title << "which starts at " << startHour << ":" << startMin << endl;
	cout << "The line can hold a maximum of " << lineSize << " patrons." << endl;
	cout << "The time is currently " << startHour - 2 << ":"<< startMin << "." << endl;
	int LineHour = startHour - 2;
	int LineMin = startMin;
	int readHour, readMin;
	string patron;
	string line;
	theater t(lineSize);
	stringstream lineStream;
	cout << "Star time: " << startHour << ":" << startMin << endl;
	getline(fs, line);
	getTime(line, readHour, readMin);
	
	for (int i = 0; i <= 120; i++)
	{
		
		if (LineHour == readHour && LineMin == readMin)
		{
			cout << readHour << ":" << readMin << "   ";
			processLine(line, readHour, readMin, patron,t);
			

			
			getline(fs, line);
			
			getTime(line, readHour, readMin);
			
		}
		
		
		if (LineHour >= startHour - 1 && LineMin >= startMin)
		{
			if (t.getNumOfPatrons() > 0)
			{
				cout << LineHour<<":"<<LineMin << "   Patron: " << t.removePatron() << " has entered the line." << endl;
			}
		}
		
		
		
		if (LineHour == startHour && LineMin == startMin)
		{

				//cout << LineHour << ":" << LineMin-1<< "   Patron: " << t.removePatron() << " has entered the line." << endl;
			
			cout << "Doors closing, ending simulation!" << endl;
			cout << "There are " << t.getNumOfPatrons() << " left in line!" << endl;
			return;
		}
		processTime(LineHour, LineMin);
	}

}
