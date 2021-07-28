#include <string>

using namespace std;

class Loan	{

	private:

		int loanId;
		int patronId;
		int bookId;
		int dueDateSec;
		string dueDate;
		string dueDate2;
		string status;

	public:

		Loan();
		void SetLoanId(int loanId);
		void SetPatronId(int patronId);
		void SetBookId(int bookId);
		void SetDueDateSec(int dueDateSec);
		void SetDueDate(string due);
		void SetDueDate2(string due);
		void SetStatus(string status);
		int GetLoanId();
		int GetPatron();
		int GetBookId();
		int GetDueDateSec();
		string GetDueDate();
		string GetStatus();

};
