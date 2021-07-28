#include "loan.h"
#include "patrons.h"
#include "libraryitems.h"


class Loans	{

	private:
		vector <Loan> loansList;

	public:
		void CheckOut(Patrons &patss, LibrayItems &itemss);
		void EditLoan();
		void UpdateLoanStatus(Patrons &patss, LibrayItems &itemss);
		void CheckIn(Patrons &patss, LibrayItems &itemss);
		void ReCheckOut();
		void ReportLost(Patrons &patss, LibrayItems &itemss);
		void PrintPatronCheckOuts();
		void PrintPatronCheckOuts2(int id);
		void PrintOverdue();
		void StoreLoans();
		void LoadLoans();

};
