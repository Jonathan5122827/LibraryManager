#include "patrons.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <time.h>

using namespace std;


void Patrons::AddPatron()	{

	string name;
	Patron currPatron;

	srand (time(0));

	cout << "Enter Patron Name: ";
	getline(cin,name);

	currPatron.SetId(rand() % 10000 + 10000);
	currPatron.SetName(name);
	currPatron.SetFineBal(0.0);
	currPatron.SetBooksOut(0);

	PatronList.push_back(currPatron);
}

void Patrons::EditPatron(int i)	{

	int newBooksOut = PatronList.at(i).GetBooksOut() + 1;
	PatronList.at(i).SetBooksOut(newBooksOut);
}

void Patrons::EditPatron2(int id)	{

	int newBooksOut = PatronList.at(id).GetBooksOut() - 1;
        PatronList.at(id).SetBooksOut(newBooksOut);
}

void Patrons::EditPatron3(int id, int sec)	{

	float newFineBal = PatronList.at(id).GetFineBal() + (sec / 86400)*(.25);
	PatronList.at(id).SetFineBal(newFineBal);
}

void Patrons::EditPatron4(int id, int bookId, LibrayItems &items)	{

	float bookCost = items.GetItemCost2(bookId);

	float newBal = PatronList.at(id).GetFineBal() + bookCost;

	PatronList.at(id).SetFineBal(newBal);
}

void Patrons::DeletePatron(int id)	{

	int i = FindPatron2(id);

	if(PatronList.at(i).GetBooksOut() == 0 && PatronList.at(i).GetFineBal() == 0.0 && PatronIdCheck(id) == true)	{

		if( i == 0)	{

			PatronList.erase(PatronList.begin());
		}

		else if (i != 0 && i !=PatronList.size())	{

			PatronList.erase(PatronList.begin() + i);
		}

		else if( i == PatronList.size())     {

			PatronList.pop_back();
               	}
	}

	else	{

		if(PatronList.at(i).GetBooksOut() != 0 && PatronIdCheck(id) == true)   {

        	        cout << "Patron Has Existing Check Outs. Please Check in all of Patron's Books" << endl;
       		}

		else if(PatronList.at(i).GetFineBal() != 0 && PatronIdCheck(id) == true)   {

                	cout << "Patron Has Existing An Fine Balance. Please Have Patron Pay Fines." << endl;
        	}

		else if	(PatronIdCheck(id) != true)	{

			cout << "Patron Id Not Found" << endl;
		}
	}
}

int Patrons::FindPatron(string name)	{

        for(int i = 0; i < PatronList.size(); i++)    {

                if(PatronList.at(i).GetName() == name)     {

			return i;
                }
        }
}

int Patrons::FindPatron2(int id)    {

        for(int i = 0; i < PatronList.size(); i++)    {

                if(PatronList.at(i).GetId() == id)     {

                        return i;
                }
        }
}

void Patrons::PrintPatron(int id)	{

	if(PatronIdCheck(id) == true)    {

                int i = FindPatron2(id);

			cout << "Name: " << PatronList.at(i).GetName() << ", ";
                	cout << "Patron Id: " << PatronList.at(i).GetId() << ", ";
                	cout << "Fine Balance: " << PatronList.at(i).GetFineBal() <<  ", ";
                	cout << "Books Out: " << PatronList.at(i).GetBooksOut() <<  " " << endl << endl;
        }
}

void Patrons::PrintPatrons()	{

	cout << "ALL PATRONS: " << endl << endl;

	for(int i = 0; i < PatronList.size(); i++)	{

		cout << "Name: " << PatronList.at(i).GetName() << ", ";
		cout << "Patron Id: " << PatronList.at(i).GetId() << ", ";
        	cout << "Fine Balance: " << PatronList.at(i).GetFineBal() <<  ", ";
        	cout << "Books Out: " << PatronList.at(i).GetBooksOut() <<  " " << endl << endl;
	}
}

void Patrons::PayFines(int id)	{

	if(PatronIdCheck(id) == true)    {

                int i = FindPatron2(id);

		PatronList.at(i).SetFineBal(0.0);
		PrintPatron(id);
        }

        else    {

                if (PatronIdCheck(id) != true)     {

                        cout << "Patron Id Not Found" << endl;
                }
        }
}

int Patrons::GetPatronId2(string name)	{

	return PatronList.at(FindPatron(name)).GetId();
}

int Patrons::GetPatronId3(int id)	{


	return PatronList.at(FindPatron2(id)).GetId();
}

int Patrons::GetBooksOut2(int id)	{


	return PatronList.at(FindPatron2(id)).GetBooksOut();
}

bool Patrons::PatronIdCheck(int id)	{

	if(PatronList.at(FindPatron2(id)).GetId() == id)	{

		return true;
	}
}

void Patrons::LoadPatrons()	{

	Patron currPatron;

	string name;
	int id;
	float bal;
	int booksout;

	int count = 0;

	ifstream infile ("patrons.dat");

	infile >> count;
	infile.ignore();

	for(int i = 0; i < count; i++)	{

	getline(infile,name);
	infile >> id;
	infile.ignore();

	infile >> bal;
	infile.ignore();

	infile >> booksout;
	infile.ignore();

	currPatron.SetId(id);
        currPatron.SetName(name);
        currPatron.SetFineBal(bal);
        currPatron.SetBooksOut(booksout);

	PatronList.push_back(currPatron);

	}
	infile.close();
}

void Patrons::StorePatrons()	{

	ofstream outfile("patrons.dat");

	outfile << PatronList.size() << endl;

	for(int i = 0; i < PatronList.size(); i++)	{

	outfile << PatronList.at(i).GetName() << endl;
	outfile << PatronList.at(i).GetId() << endl;
	outfile << PatronList.at(i).GetFineBal() << endl;
 	outfile << PatronList.at(i).GetBooksOut() << endl;
	}
	outfile.close();
}
