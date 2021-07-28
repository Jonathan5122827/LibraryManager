#include <string>
#include <iostream>
//#include <fstream>
#include "LibraryItem.h"

//#include "book.h"
using namespace std;

LibraryItem::LibraryItem()	{

	id = 0;
	cost = 0.0;
	status = "none";
	loanPeriod = 0;


}

void LibraryItem::SetId(int id)	{

	this->id = id;
}

void LibraryItem::SetCost(float cost)	{

	this->cost = cost;
}

void LibraryItem::SetStatus(string status)	{

	this->status = status;
}

void LibraryItem::SetLoanPeriod(int loanPeriod)	{

	this->loanPeriod = loanPeriod;
}

int LibraryItem::GetId()	{

	return id;
}

float LibraryItem::GetCost()	{

	return cost;
}

string LibraryItem::GetStatus()	{

	return status;
}

int LibraryItem::GetLoanPeriod()	{

	return loanPeriod;
}

void LibraryItem::PrintInfo()	{

	cout << "ID: ";


}

void LibraryItem::PrintRawInfo()	{



}

ostream& operator<<(ostream& st, LibraryItem* it)	{

	//ofstream outx;

	it->PrintRawInfo();
	return st;
}
