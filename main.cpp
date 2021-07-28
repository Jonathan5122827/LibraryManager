#include <iostream>
//#include "patron.h"
//#include "patrons.h"
//#include "books.h"
#include "loans.h"

using namespace std;


void PrintMenu();

void PrintMenu()	{

	cout << "MENU" << endl;
	cout << "Select an charactar option:" << endl;
	cout << " a - Add A Patron" << endl;
	cout << " b - Add A Item" << endl;
	cout << " o - Check Out" << endl;
	cout << " i - Check In" << endl;
	cout << " l - Report Lost Item" << endl;
	cout << " y - Pay Patron Fine Balance" << endl;
	cout << " r - Remove A Patron" << endl;
	cout << " t - Remove A Item" << endl;
	cout << " p - Print All Patrons" << endl;
	cout << " k - Print All Items" << endl;
	cout << " j - Print All Check Outs" << endl;
	cout << " z - Print All Information" << endl;
	cout << " q - Quit" << endl << endl;
	cout << " Choose an option: ";
}

int main()	{

	Patrons pats;
	LibrayItems items;
	Loans loans;

	char uc;

	pats.LoadPatrons();
        items.LoadItems();
        loans.LoadLoans();
	loans.UpdateLoanStatus(pats,items);

	while( uc != 'q')	{

		PrintMenu();
		cin >> uc;
		cin.ignore();

		cout << endl << endl;

		switch(uc)	{


			case 'a':
				//PrintMenu();
				pats.AddPatron();
				break;

			case 'b':
				items.AddItem();
				break;

			case 'o':
				loans.CheckOut(pats,items);
				break;

			case 'i':
				loans.CheckIn(pats,items);
				break;

			case 'l':
				loans.ReportLost(pats,items);
				break;

			case 'y':

				int idy;
				pats.PrintPatrons();

				cout << "Enter Patron's Id who is paying fines: ";
				cin >> idy;
				cin.ignore();

				pats.PayFines(idy);
				break;

			case 'r':
                                int id;

				pats.PrintPatrons();

				cout << "Enter Patron's who is to be removed: ";
				cin >> id;
				cin.ignore();

				pats.DeletePatron(id);
                                break;

			case 't':
				int idi;

				items.PrintItems();

				cout << "Enter Item's Id that is to be removed: ";
				cin >> idi;
				cin.ignore();

				items.DeleteItem(idi);
				break;

			case 'p':
				pats.PrintPatrons();
				break;

			case 'k':
				items.PrintItems();
				break;

			case 'j':
				loans.PrintPatronCheckOuts();

			case 'z':
				pats.PrintPatrons();
        			items.PrintItems();
        			loans.PrintPatronCheckOuts();
				break;

			case 'q':
				break;

			default :
				cout << "Not An Options" << endl;
				break;
		}

	}

	pats.StorePatrons();
        items.StoreItems();
        loans.StoreLoans();


	//pats.LoadPatrons();
	//books.LoadBooks();
	//pats.LoadPatrons();
	//loans.LoadLoans();
	//pats.SetPatronCount(0);
	//pats.SetPatronCap(2);
	//pats.AddPatron();
	//pats.AddPatron();
	//pats.AddPatron();
	//pats.FindPatron();
	//pats.PrintPatrons();

	//books.SetBooksCount(0);
	//books.SetBooksCap(1);

	//books.AddBook();
	//books.AddBook();
	//books.AddBook();
	//books.AddBook();
        //books.AddBook();
        //books.AddBook();
	//books.AddBook();
	//books.AddBook();
	//books.PrintBooks();

	//loans.SetLoansCount(0);
	//loans.SetLoansCap(2);
	//loans.CheckOut(pats,books);
	//loans.CheckOut(pats,books);
	//loans.CheckOut(pats,books);
        //loans.CheckOut(pats,books);
	//loans.CheckOut(pats,books);
        //loans.CheckOut(pats,books);
	//loans.CheckOut(pats,books);
        //loans.CheckOut(pats,books);
	//loans.PrintPatronCheckOuts();
	//pats.PrintPatrons();
	//books.PrintBooks();

	//loans.CheckIn(pats,books);
        //loans.CheckIn(pats,books);
        //loans.PrintPatronCheckOuts();
        //pats.PrintPatrons();
        //books.PrintBooks();
	//loans.PrintPatronCheckOuts();

	//pats.StorePatrons();
	//books.StoreBooks();
	//loans.StoreLoans();





	return 0;

}
