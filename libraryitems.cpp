//#include "LibraryItem.h"
//#include "book.h"
using namespace std;
//#include "libraryitems.h"
//#include "book.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <fstream>
#include <vector>
#include "LibraryItem.h"
#include "book.h"
#include "audio.h"
#include "dvd.h"
#include "libraryitems.h"


//using namespace std;

void LibrayItems::AddItem()	{

	Book* currBook;
	Audio* cd;
	Dvd* dvd;

	cout << "What Type is the Item (1 - Book, 2 - Audio CD, 3 - DVD): ";

	int type;
	cin >> type;
	cin.ignore();

	srand (time(0));

	if(type == 1)	{

		currBook = new Book();

		string title;
        	string author;
		string genre;

        	cout << "Enter name of Book to add: ";
        	getline(cin,title);
        	cout << "Enter name of Book's author: ";
        	getline(cin,author);
		cout << "Enter Book's Genre: ";
                getline(cin,genre);

        	currBook->SetTitle(title);
        	currBook->SetAuthor(author);
        	currBook->SetId(rand () % 9999 + 1000);
        	currBook->SetIsbn(rand () % 1000000 + 1000000);
        	currBook->SetCost(rand () % 47 + 2);
        	currBook->SetStatus("In");
		currBook->SetCat(genre);
		currBook->SetLoanPeriod(0);

        	libItems.push_back(currBook);
	}

	else if(type == 2)	{

		cd = new Audio();

		string title;
                string artist;
                string genre;

		time_t rd = time(0) - rand() % 946708560  + 10000;
		char* dt = ctime(&rd);

		string rd2(dt);

                cout << "Enter Title Of CD To Add: ";
                getline(cin,title);
                cout << "Enter name of CD's Artist: ";
                getline(cin,artist);
                cout << "Enter CD's Genre: ";
                getline(cin,genre);

                cd->SetTitle(title);
                cd->SetArtist(artist);
		cd->SetTracks(rand () % 10 + 2);
		cd->SetReleaseDate(rd2);
                cd->SetId(rand () % 9999 + 1000);
                cd->SetCost(rand () % 47 + 2);
                cd->SetStatus("In");
                cd->SetGenre(genre);
                cd->SetLoanPeriod(0);

                libItems.push_back(cd);
	}

	else if(type == 3)	{

		dvd = new Dvd();

		string title;
                string studio;
                string genre;

		time_t rd = time(0) - rand() % 946708560  + 10000;
                char* dt = ctime(&rd);

                string rd2(dt);

                cout << "Enter Name Of DVD To Add: ";
                getline(cin,title);
                cout << "Enter Name Of DVD's Studio: ";
                getline(cin,studio);
                cout << "Enter DVD's Genre: ";
                getline(cin,genre);

                dvd->SetTitle(title);
                dvd->SetStudio(studio);
                dvd->SetId(rand () % 9999 + 1000);
                dvd->SetCost(rand () % 47 + 2);
                dvd->SetStatus("In");
                dvd->SetCat(genre);
                dvd->SetLoanPeriod(0);
		dvd->SetRunTime(rand () % 100 + 60);
		dvd->SetReleaseDate(rd2);

                libItems.push_back(dvd);
	}

	else{

		cout << "Not A Choice Type." << endl;
	}

}

LibrayItems::LibrayItems()	{



}

void LibrayItems::EditItem(int i)	{

	libItems.at(i)->SetStatus("Out");
}

void LibrayItems::EditItem2(int id)	{

	libItems.at(id)->SetStatus("In");
}

void LibrayItems::EditItem3(int id)	{

	libItems.at(id)->SetStatus("Lost");
}

void LibrayItems::DeleteItem(int id)	{

	ItemIdCheck(id);

	int i = FindItem2(id);

	if(libItems.at(i)->GetStatus() == "In" && ItemIdCheck(id) == true)	{

		if (i == 0)	{

			libItems.erase(libItems.begin());
		}

		else if (i != 0 && i != libItems.size())	{

			libItems.erase(libItems.begin() + i);
		}

		else if (i == libItems.size())     {

                        libItems.erase(libItems.end());
                }
	}

	else	{

		if(libItems.at(i)->GetStatus() != "In" && ItemIdCheck(id) == true)	{

			cout << "Item Is Still Checked Out. Please Check Back In." << endl;
		}

		else if	(ItemIdCheck(id) != true)	{

			cout << "Not a Item Id" << endl;
		}
	}

}

int LibrayItems::FindItem(string title)	{




}

int LibrayItems::FindItem2(int id)	{

	for(int i = 0; i < libItems.size(); ++i)	{
		if(libItems.at(i)->GetId() == id)	{

			return i;
		}
	}
}

void LibrayItems::PrintItem()	{



}

void LibrayItems::PrintInItems()	{

	cout << "ALL AVAILABLE LIBRARY ITEMS: " << endl << endl;

	for(int i = 0; i < libItems.size(); ++i)        {
                if(libItems.at(i)->GetStatus() == "In")       {

                        libItems.at(i)->PrintInfo();
                }
        }
}

void LibrayItems::PrintItems()	{

	cout << "ALL LIBRARY ITEMS: " << endl << endl;

	for(int i = 0; i < libItems.size(); ++i)	{

		libItems.at(i)->PrintInfo();
		//libItems.at(i)->PrintRawInfo();
	}
}

int LibrayItems::GetItemId2(string title)	{




}

int LibrayItems::GetItemId3(int id)	{

	return libItems.at(FindItem2(id))->GetId();
}

float LibrayItems::GetItemCost2(int id)	{

	return libItems.at(FindItem2(id))->GetCost();
}

bool LibrayItems::ItemIdCheck(int id)	{

	for(int i = 0; i < libItems.size(); ++i)        {
                if(libItems.at(i)->GetId() == id)       {

                        return true;
                }
        }
}

void LibrayItems::StoreItems()	{

	ofstream outfile("items.dat");

	outfile << libItems.size() << endl;

	//outfile << "TEST" << endl;

	//outfile.close();

	for(int i = 0; i < libItems.size(); ++i)	{

		outfile << libItems.at(i);
	}
	outfile.close();
}

void LibrayItems::LoadItems()	{

	ifstream infile("items.dat");

	int size = 0;

	infile >> size;
	infile.ignore();

	for(int i = 0; i < size; ++i)	{

		int type = 0;

		infile >> type;
		infile.ignore();

			if(type == 1)	{

				Book* book;

				int id;
				float cost;
				int lp;
				string stat;

				string title;
				string author;
				string cat;
				int isbn;

				infile >> id;
				infile.ignore();

				infile >> cost;
				infile.ignore();

				infile >> lp;
				infile.ignore();

				getline(infile,stat);
                		getline(infile,title);
                		getline(infile,author);
                		getline(infile,cat);

				infile >> isbn;
				infile.ignore();

				book = new Book();

				book->SetTitle(title);
                		book->SetAuthor(author);
                		book->SetId(id);
                		book->SetIsbn(isbn);
                		book->SetCost(cost);
                		book->SetStatus(stat);
                		book->SetCat(cat);
                		book->SetLoanPeriod(lp);

                		libItems.push_back(book);
			}

			else if(type == 2)	{

				Audio* cd;

                                int id;
                                float cost;
                                int lp;
                                string stat;

                                string title;
                                string artist;
                                string cat;
                                int tracks;
				string rd;

                                infile >> id;
                                infile.ignore();

                                infile >> cost;
                                infile.ignore();

                                infile >> lp;
                                infile.ignore();

                                getline(infile,stat);
                                getline(infile,title);
                                getline(infile,artist);
                                getline(infile,cat);

				infile >> tracks;
				infile.ignore();

                                getline(infile,rd);

				cd = new Audio();

				cd->SetTitle(title);
                		cd->SetArtist(artist);
                		cd->SetTracks(tracks);
                		cd->SetReleaseDate(rd);
                		cd->SetId(id);
                		cd->SetCost(cost);
                		cd->SetStatus(stat);
                		cd->SetGenre(cat);
                		cd->SetLoanPeriod(lp);

                		libItems.push_back(cd);
			}

			else if(type == 3)	{

				Dvd* dvd;

				int id;
                                float cost;
                                int lp;
                                string stat;

                                string title;
                                string studio;
                                string cat;
                                int run;
                                string rd;

                                infile >> id;
                                infile.ignore();

                                infile >> cost;
                                infile.ignore();

                                infile >> lp;
                                infile.ignore();

                                getline(infile,stat);
                                getline(infile,title);
                                getline(infile,studio);
                                getline(infile,cat);

                                infile >> run;
                                infile.ignore();

                                getline(infile,rd);

				dvd = new Dvd();

				dvd->SetTitle(title);
                		dvd->SetStudio(studio);
                		dvd->SetId(id);
                		dvd->SetCost(cost);
                		dvd->SetStatus(stat);
                		dvd->SetCat(cat);
                		dvd->SetLoanPeriod(lp);
                		dvd->SetRunTime(run);
                		dvd->SetReleaseDate(rd);

                		libItems.push_back(dvd);
			}

			else	{

				cout << "nothing" << endl;
			}
	}
}
