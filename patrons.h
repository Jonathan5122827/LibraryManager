#include "patron.h"
#include "libraryitems.h"
//#include "books.h"
#include <vector>

using namespace std;

class Patrons{

        private:
		vector <Patron> PatronList;

        public:
		void AddPatron();
		void EditPatron(int i);
		void EditPatron2(int id);
		void EditPatron3(int id, int sec);
		void EditPatron4(int id, int bookId, LibrayItems &items);
		void DeletePatron(int id);
		int FindPatron(string name);
		int FindPatron2(int id);
		void PrintPatron(int id);
		void PrintPatrons();
		void PayFines(int id);
		int GetPatronId2(string name);
		int GetPatronId3(int id);
		bool PatronIdCheck(int id);
		int GetBooksOut2(int id);
		void LoadPatrons();
		void StorePatrons();
};
