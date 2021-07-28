#include "patron.h"


using namespace std;


Patron::Patron()	{

	patronID = 0;
	booksOut = 0;
	fineBal = 0.0;
	name = "No Name";

}

Patron::Patron(int patronID,int booksOut,float fineBal,string name)	{

	this-> patronID = patronID;
	this-> booksOut = booksOut;
	this-> fineBal = fineBal;
	this-> name = name;

}

void Patron::SetId(int patronID)	{

	this-> patronID = patronID;

}

void Patron::SetBooksOut(int booksOut)	{

	this-> booksOut = booksOut;

}

void Patron::SetFineBal(float fineBal)	{

	this-> fineBal = fineBal;

}

void Patron::SetName(string name)	{

	this-> name = name;

}

int Patron::GetId()	{

	return patronID;

}

int Patron::GetBooksOut()	{

	return booksOut;


}

float Patron::GetFineBal()	{

	return fineBal;

}

string Patron::GetName()	{

	return name;

}




