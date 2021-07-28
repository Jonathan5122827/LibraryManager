#include "loans.h"
//#include "patrons.h"
//#include "books.h"
//#include "loans.h"
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;


void Loans::CheckOut(Patrons &patss, LibrayItems &itemss)	{

	int id;
	int bid;
	Loan currLoan;

	srand (time(0));
	time_t due = time(0) + 604800;
	char* dt = ctime(&due);

	string due2(dt);

	//cout << "Patrons:" << endl;
	patss.PrintPatrons();

	//cout << "Books:" << endl;
	itemss.PrintInItems();

	cout << "Enter Patron's ID who is checking out: ";
	cin >> id;
	cout << endl << "Enter Item's ID the Patron is checking out; ";
	cin >> bid;

	if((patss.GetBooksOut2(id) < 6) && (patss.PatronIdCheck(id) == true) && (itemss.ItemIdCheck(bid) == true)){

	currLoan.SetPatronId(patss.GetPatronId3(id));
	currLoan.SetBookId(itemss.GetItemId3(bid));
	currLoan.SetStatus("On Time");
	currLoan.SetLoanId(rand () % 8999 + 1000);
	currLoan.SetDueDate(due2);
	currLoan.SetDueDateSec(due);
	patss.EditPatron(patss.FindPatron2(id));
	itemss.EditItem(itemss.FindItem2(bid));

	loansList.push_back(currLoan);
	}

	else{

		if(patss.PatronIdCheck(id) == false)	{

			cout << endl << "Patron's Id not found." << endl << endl;
		}

		else if(itemss.ItemIdCheck(bid) == false)	{

			cout << endl << "Item's Id not found." << endl << endl;
		}

		else if(patss.GetBooksOut2(id) == 6 && patss.PatronIdCheck(id) == true)	{

			cout << endl << "Patrons check outs are " << patss.GetBooksOut2(id) << ".Patron can not check out anymore items." << endl << endl;
		}
	}
}

void Loans::PrintPatronCheckOuts()	{

	cout << endl << "ALL PATRON CHECK OUTS:" << endl << endl;

	for(int i = 0; i < loansList.size(); i++)	{

		cout << "Patron ID: " << loansList.at(i).GetPatron() << ", ";
		cout << "Loan ID: " << loansList.at(i).GetLoanId() << ", ";
		cout << "Loan Status: " << loansList.at(i).GetStatus() << ", ";
		cout << "Item ID: " << loansList.at(i).GetBookId() << ", ";
		cout << "Loan Due Date: " << loansList.at(i).GetDueDate() << endl << endl;
	}
}

void Loans::PrintPatronCheckOuts2(int id)	{

	cout << "PATRON'S CHECK OUTS:" << endl << endl;

	for(int i = 0; i < loansList.size(); i++)       {
		if(loansList.at(i).GetPatron()  == id)	{

                	cout << "Patron ID: " << loansList.at(i).GetPatron() << ", ";
                	cout << "Loan ID: " << loansList.at(i).GetLoanId() << ", ";
                	cout << "Loan Status: " << loansList.at(i).GetStatus() << ", ";
                	cout << "Item ID: " << loansList.at(i).GetBookId() << ", ";
                	cout << "Loan Due Date: " << loansList.at(i).GetDueDate() << endl << endl;
		}
        }
}

void Loans::CheckIn(Patrons &patss, LibrayItems &itemss)	{

	int PatronId;
	int LoanId;

	patss.PrintPatrons();

	cout << "Enter Patron's ID who is checking in: ";
	cin >> PatronId;

	PrintPatronCheckOuts2(PatronId);

	cout << "Enter Loan Id that the Patron's is checking in: ";
	cin  >> LoanId;

	for(int i = 0; i < loansList.size(); i++)       {
                if(loansList.at(i).GetLoanId()  == LoanId)  {

			patss.EditPatron2(patss.FindPatron2(loansList.at(i).GetPatron()));
        		itemss.EditItem2(itemss.FindItem2(loansList.at(i).GetBookId()));

                        loansList.erase(loansList.begin() + i);
                }
        }
}

void Loans::ReportLost(Patrons &patss, LibrayItems &itemss)	{

	int PatronId;
        int LoanId;

	patss.PrintPatrons();

        cout << "Enter Patron's ID who is reporting a lost book: ";
        cin >> PatronId;

        PrintPatronCheckOuts2(PatronId);

        cout << "Enter Loan Id that the Patron's is reporting lost:";
        cin  >> LoanId;

        for(int i = 0; i < loansList.size(); i++)       {
                if(loansList.at(i).GetLoanId()  == LoanId)  {

			int bookId = loansList.at(i).GetBookId();

                        patss.EditPatron2(patss.FindPatron2(loansList.at(i).GetPatron()));
			patss.EditPatron4(patss.FindPatron2(loansList.at(i).GetPatron()),bookId,itemss);
                        itemss.EditItem3(itemss.FindItem2(loansList.at(i).GetBookId()));

                        loansList.erase(loansList.begin() + i);
                }
        }
}

void Loans::StoreLoans()	{

	ofstream outfile("loans.dat");

	outfile << loansList.size() << endl;

	for(int i = 0; i < loansList.size(); i++)       {

                outfile << loansList.at(i).GetPatron() << endl;
                outfile << loansList.at(i).GetLoanId() << endl;
                outfile << loansList.at(i).GetStatus() << endl;
                outfile << loansList.at(i).GetDueDate() << endl;
                outfile << loansList.at(i).GetBookId() << endl;
		outfile << loansList.at(i).GetDueDateSec() << endl;
        }
	outfile.close();
}

void Loans::LoadLoans()	{

	Loan curr;
	ifstream infile("loans.dat");

	int patron;
	int id;
	string status;
	//char* due;
	string due;
	int bookid;
	int dueSec;
	int count = 0;

	infile >> count;
	infile.ignore();

	for(int i = 0; i < count; i++)	{

		infile >> patron;
                infile.ignore();

		infile >> id;
		infile.ignore();

		getline(infile,status);

		getline(infile,due);

		infile >> bookid;
		infile.ignore();

		infile >> dueSec;
                infile.ignore();

		curr.SetPatronId(patron);
        	curr.SetBookId(bookid);
        	curr.SetStatus(status);
        	curr.SetLoanId(id);
		curr.SetDueDate(due);
		curr.SetDueDateSec(dueSec);

		loansList.push_back(curr);
	}
	infile.close();
}

void Loans::UpdateLoanStatus(Patrons &patss, LibrayItems &itemss)	{

	time_t now = time(0);

	for(int i = 0; i < loansList.size(); i++)       {

		int secOver = now - loansList.at(i).GetDueDateSec();

		if(loansList.at(i).GetDueDateSec() > now && secOver > 86400 )	{

			loansList.at(i).SetStatus("Late");

			patss.EditPatron3(patss.FindPatron2(loansList.at(i).GetPatron()), secOver);
		}
        }
}

void Loans::PrintOverdue()     {

	cout << "ALL OVERDUE CHECK OUTS:" << endl << endl;

        for(int i = 0; i < loansList.size(); i++)       {
                if(loansList.at(i).GetStatus()  == "Late")  {

                        cout << "Patron ID: " << loansList.at(i).GetPatron() << ", ";
                	cout << "Loan ID: " << loansList.at(i).GetLoanId() << ", ";
                	cout << "Loan Status: " << loansList.at(i).GetStatus() << ", ";
                	cout << "Book ID: " << loansList.at(i).GetBookId() << ", ";
                	cout << "Loan Due Date: " << loansList.at(i).GetDueDate() << endl << endl;
                }
        }
}
