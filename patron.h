#include <string>

using namespace std;

class Patron{

	private:

		int patronID;
		int booksOut;
		float fineBal;
		string name;

	public:

		Patron();
		Patron(int patronID,int booksOut,float fineBal,string name);

		void SetId(int patronID);
		void SetBooksOut(int booksOut);
		void SetFineBal(float fineBal);
		void SetName(string name);
		int GetId();
                int GetBooksOut();
                float GetFineBal();
                string GetName();


};
