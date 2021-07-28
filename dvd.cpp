#include <string>
#include <iostream>
//#include "LibraryItem.h"
#include "dvd.h"

using namespace std;

Dvd::Dvd()	{



}

void Dvd::SetTitle(string title)	{

	this->title = title;
}

void Dvd::SetCat(string cat)	{

	this->cat = cat;
}

void Dvd::SetRunTime(int runTime)	{

	this->runTime = runTime;
}

void Dvd::SetStudio(string studio)	{

	this->studio = studio;
}

void Dvd::SetReleaseDate(string releaseDate)	{

	this->releaseDate = releaseDate;
}

string Dvd::GetTitle()	{

	return title;
}

string Dvd::GetCat()	{

	return cat;
}

int Dvd::GetRunTime()	{

	return runTime;
}

string Dvd::GetStudio()	{

	return studio;
}

string Dvd::GetReleaseDate()	{

	return releaseDate;
}

void Dvd::PrintInfo()	{

	cout << "   DVD ID #: " << GetId() << " , Cost: $" << GetCost() << " , Max Loan Period: " << GetLoanPeriod() << " , Status: " <<  GetStatus();

        cout << " , Title: " <<  GetTitle() << " , Studio: " << GetStudio() << " , Category: " << GetCat() << " , Run Time: " << GetRunTime() << " , Release Date: " << GetReleaseDate() <<  endl << endl;
}

void Dvd::PrintRawInfo()	{

	int t = 3;

	ofstream out("items.dat", std::ios_base::app);

	out << t << endl << GetId() << endl << GetCost() << endl << GetLoanPeriod() << endl <<  GetStatus() << endl;

        out << GetTitle() << endl << GetStudio() << endl << GetCat() << endl << GetRunTime() << endl << GetReleaseDate() <<  endl;
}
