#include <iostream>
#include <string>
//#include "book.h"
//#include "LibraryItem.h"
#include "book.h"

using namespace std;


Book::Book()	{

	//bookID = 0;
	//cost = 0;
	//title = "NoName";
	//author = "NoAuthur";
	//cat = "NoCat";
	//isbn =	0;
}

//void Book::SetBookId(int bookID)	{

	//this->bookID = bookID;
//}

//void Book::SetCost(int cost)	{

	//this->cost = cost;

//}

void Book::SetTitle(string title)	{

	this->title=title;

}

void Book::SetAuthor(string author)	{

	this->author = author;

}

void Book::SetCat(string cat)	{

	this->cat = cat;

}

void Book::SetIsbn(int isbn)	{

	this->isbn = isbn;

}

//int Book::GetBookId()	{

	//return bookID;

//}

//int Book::GetCost()	{

	//return cost;

//}

string Book::GetTitle()	{

	return title;

}

string Book::GetAuthor()	{

	return author;

}

string Book::GetCat()	{

	return cat;

}

int Book::GetIsbn()	{

	return isbn;

}

void Book::PrintInfo()     {

	cout <<  "   BOOK ID #: " << GetId() << " , Cost: $" << GetCost() << " , Max Loan Period: " << GetLoanPeriod() << " , Status: " <<  GetStatus() << " , Title: ";

	cout << GetTitle() << " , Author: " << GetAuthor() << " , Category: " << GetCat() << ", Isbn #: " << GetIsbn() << endl << endl;
}

void Book::PrintRawInfo()	{

	int t = 1;

	ofstream out("items.dat", std::ios_base::app);

	out << t << endl << GetId() << endl << GetCost() << endl << GetLoanPeriod() << endl <<  GetStatus() << endl;

        out << GetTitle() << endl << GetAuthor() << endl << GetCat() << endl << GetIsbn() << endl;
}
