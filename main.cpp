#include <iostream>
#include "library.h"

using namespace std;

int main()
{
	char c;
    FCILibraryBooks obj;

    while (true)
	{
		obj.printMenu();
        cin>>c;
        switch (c)
        {
        case '1' :
            obj.AddBook();
            break;
        case '2':
            obj.SearchByName();
            break;
        case '3':
            obj.SearchByAuthor();
            break;
        case '4':
            obj.ListInAlpha();
            break;
        case '5':
            obj.UpdateBook();
            break;
        case '6':
            obj.HighestNumberOfVersions();
            break;
		case '0':
			return 0;
        default :
            cout << "Error... Try Again." << endl;
			cin.ignore();
			cin.clear();
        } 
    }

    return 0;
}
