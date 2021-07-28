lib : main.o loans.o patrons.o libraryitems.o loan.o patron.o book.o audio.o dvd.o LibraryItem.o
	g++ main.o loans.o patrons.o libraryitems.o loan.o patron.o book.o audio.o dvd.o LibraryItem.o -o lib

main.o : main.cpp loans.h loan.h patrons.h libraryitems.h
	g++ -c -Wall main.cpp

loans.o : loans.cpp loans.h loan.h patrons.h libraryitems.h
	g++ -c -Wall loans.cpp

patrons.o : patrons.cpp patrons.h patron.h LibraryItem.h
	g++ -c -Wall patrons.cpp

libraryitems.o : libraryitems.cpp LibraryItem.h book.h audio.h dvd.h libraryitems.h
	g++ -c -Wall libraryitems.cpp

loan.o : loan.cpp loan.h 
	g++ -c -Wall loan.cpp

patron.o : patron.cpp patron.h
	g++ -c -Wall patron.cpp

book.o	: book.cpp LibraryItem.h
	g++ -c -Wall book.cpp

audio.o	: audio.cpp audio.h LibraryItem.h
	g++ -c -Wall audio.cpp

dvd.o	: dvd.cpp dvd.h LibraryItem.h
	g++ -c -Wall dvd.cpp

LibraryItem.o	: LibraryItem.cpp LibraryItem.h
	g++ -c -Wall LibraryItem.cpp
