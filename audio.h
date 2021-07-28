#include "LibraryItem.h"
using namespace std;

#include <string>


//#include <string>

//using namespace std;

class Audio : public LibraryItem	{

	private:
		string artist;
		string title;
		int tracks;
		string releaseDate;
		string genre;

	public:

		Audio();
		void SetArtist(string artist);
		void SetTitle(string title);
		void SetTracks(int tracks);
		void SetReleaseDate(string releaseDate);
		void SetGenre(string genre);
		string GetArtist();
		string GetTitle();
		int GetTracks();
		string GetReleaseDate();
		string GetGenre();
		void PrintInfo() override;
		void PrintRawInfo() override;
};
