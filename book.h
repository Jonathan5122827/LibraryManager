#include "LibraryItem.h"
using namespace std;

#include <string>

//using namespace std;

class Book : public LibraryItem {

        private:

                //int bookID;
                //int cost;
                string title;
		string author;
		string cat;
		int isbn;

        public:

                Book();
                //book(int patronID,int booksOut,float fineBal,string name);

                //void SetBookId(int bookID);
                //void SetCost(int cost);
                void SetTitle(string title);
		void SetAuthor(string author);
		void SetCat(string cat);
		void SetIsbn(int isbn);
                //int GetBookId();
                //int GetCost();
                string GetTitle();
		string GetAuthor();
		string GetCat();
		int GetIsbn();
		void PrintInfo() override;
		void PrintRawInfo() override;
};
