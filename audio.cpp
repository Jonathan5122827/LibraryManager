#include <string>
#include <iostream>
//#include "LibraryItem.h"
#include "audio.h"

using namespace std;

void Audio::SetArtist(string artist)	{

	this->artist = artist;
}

void Audio::SetTitle(string title)	{

	this->title = title;
}

void Audio::SetTracks(int tracks)	{

	this->tracks = tracks;
}

void Audio::SetReleaseDate(string releaseDate)	{

	this->releaseDate = releaseDate;
}

void Audio::SetGenre(string genre)	{

	this->genre = genre;
}

string Audio::GetArtist()	{

	return artist;
}

string Audio::GetTitle()	{

	return title;
}

int Audio::GetTracks()	{

	return tracks;
}

string Audio::GetReleaseDate()	{

	return releaseDate;
}

string Audio::GetGenre()	{

	return genre;
}

Audio::Audio()	{



}

void Audio::PrintInfo()	{

	cout << "   CD ID #: " << GetId() << " , Cost: $" << GetCost() << " , Max Loan Period: " << GetLoanPeriod() << " , Status: " <<  GetStatus();

        cout << " , Title: " << GetTitle() << " , Artist: " << GetArtist() << " , Genre: " << GetGenre() << " , Tracks: " << GetTracks() << " , Release Date: " << GetReleaseDate() << endl << endl;

}

void Audio::PrintRawInfo()	{

	int t = 2;

	ofstream out("items.dat", std::ios_base::app);

	out << t << endl << GetId() << endl << GetCost() << endl << GetLoanPeriod() << endl <<  GetStatus() << endl;

        out << GetTitle() << endl << GetArtist() << endl << GetGenre() << endl << GetTracks() << endl << GetReleaseDate() <<  endl;
}

