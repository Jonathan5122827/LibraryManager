#ifndef LIB
#define LIB

#include <fstream>
#include <iostream>
#include <string>
//#include <iostream>
//#include "book.h"

using namespace std;

class LibraryItem	{


	protected:

		int id;
		float cost;
		string status;
		int loanPeriod;

	public:

		LibraryItem();
		void SetId(int id);
		void SetCost(float cost);
		void SetStatus(string status);
		void SetLoanPeriod(int loanPeriod);
		int GetId();
		float GetCost();
		string GetStatus();
		int GetLoanPeriod();
		virtual void PrintInfo();
		virtual void PrintRawInfo();
		friend ostream& operator<<(ostream& st, LibraryItem* it);
};

#endif
