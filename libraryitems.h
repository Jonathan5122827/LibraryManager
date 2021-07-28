#ifndef LIBS
#define LIBS


#include "LibraryItem.h"
//#include "book.h"
//using namespace std;
#include <vector>
#include <string>
using namespace std;

class LibrayItems{

        private:

                vector <LibraryItem*> libItems;

        public:
		LibrayItems();
                void AddItem();
                void EditItem(int i);
                void EditItem2(int id);
                void EditItem3(int id);
                void DeleteItem(int id);
                int FindItem(string title);
                int FindItem2(int id);
                void PrintItem();
                void PrintInItems();
                void PrintItems();
                int GetItemId2(string title);
                int GetItemId3(int id);
                float GetItemCost2(int id);
                bool ItemIdCheck(int id);
                void StoreItems();
                void LoadItems();
};
#endif
