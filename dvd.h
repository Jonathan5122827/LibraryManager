#include "LibraryItem.h"
using namespace std;

#include <string>

//#include <string>

//using namespace std;

class Dvd : public LibraryItem	{

	private:
		string title;
		string cat;
		int runTime;
		string studio;
		string releaseDate;

	public:
		Dvd();
		void SetTitle(string title);
		void SetCat(string cat);
		void SetRunTime(int runTime);
		void SetStudio(string studio);
		void SetReleaseDate(string releaseDate);
		string GetTitle();
		string GetCat();
		int GetRunTime();
		string GetStudio();
		string GetReleaseDate();
		void PrintInfo() override;
		void PrintRawInfo() override;
};
