#include "loan.h"

Loan::Loan()	{

	loanId = 0;
	patronId = 0;
	bookId = 0;
	//dueDate = "XXXX";
	status = "None";
}

void Loan::SetLoanId(int loanId)	{

	this->loanId = loanId;
}

void Loan::SetPatronId(int patronId)	{

	this->patronId = patronId;
}

void Loan::SetBookId(int bookId)	{

	this->bookId = bookId;
}

void Loan::SetDueDateSec(int dueDateSec)	{

	this->dueDateSec = dueDateSec;
}

void Loan::SetDueDate(string due)	{

	this->dueDate = due;
}

void Loan::SetDueDate2(string due)	{

	this->dueDate2 = due;
}

void Loan::SetStatus(string status)	{

	this->status = status;
}

int Loan::GetDueDateSec()	{

	return dueDateSec;
}

int Loan::GetLoanId()	{

	return loanId;
}

int Loan::GetPatron()	{

	return patronId;
}

int Loan::GetBookId()	{

	return bookId;
}

string Loan::GetDueDate()	{

	return dueDate;
}

string Loan::GetStatus()	{

	return status;
}
