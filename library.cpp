#include "library.h"

int FCILibraryBooks::getMaxInt(vector<int>& v)
{
	return *max_element(v.begin(), v.end());
}

void FCILibraryBooks::printMenu()
{
	cout<<"0 - Exit."<<endl;
	cout<<"1 - Add Book."<<endl;
	cout<<"2 - Search by name."<<endl;
	cout<<"3 - Search by author."<<endl;
	cout<<"4 - List books in alphabetical order (Ascending)"<<endl;
	cout<<"5 - Update available number of versions of a book (user enters book name and the new number)"<<endl;
	cout<<"6 - Find the books which have the highest number of versions and print books information."<<endl;
	cout << ">> ";
}

void FCILibraryBooks::AddBook()
{
	FCILibraryBooks b;
	fstream book;
	book.open("Library.txt", ios::app);
	cin.ignore();
	cout<<"Enter Author name : ";
	cin.getline(b.AuthorName,50);
	cout<<"Enter The name of the book : ";
	cin.getline(b.Name,50);
	cout<<"Enter Publish Year : ";
	cin.getline(b.Publishyear,5);
	cout<<"Enter Number of versions : ";
	cin>>b.NumOfversions;
	book<<b.AuthorName<<'|'<<b.Name<<'|'<<b.Publishyear<<'|'<<b.NumOfversions;
	cout<< "done !\n";
	book.close();
}

void FCILibraryBooks::SearchByName()
{
    fstream book;
    FCILibraryBooks b;

    book.open("Library.txt",ios::in);
    cin.ignore();
    char NameToSearh[50];
    cout<<"Enter the Book's Name to search about it : ";

    cin.getline(NameToSearh,50);
    int x=0;

    cout<< "Author name   Book's Name   Publish Year   Number of versions "<<endl;
    while(!book.eof())
    {
        book.getline(b.AuthorName,50,'|');
        book.getline(b.Name,50,'|');
        book.getline(b.Publishyear,5,'|');
        book>>b.NumOfversions;

        if(strcmp(b.Name, NameToSearh)==0)
        {
            cout<< b.AuthorName <<"  "<<b.Name<<"  "<<b.Publishyear<<"  "<<b.NumOfversions<<endl;
            x=1;
            break;
        }
    }
    if(x==0)
    {
        cout<<"not found\n";
    }
    book.close();
}

void FCILibraryBooks::SearchByAuthor()
{
    fstream book;
    FCILibraryBooks b;

    book.open("Library.txt",ios::in);
    cin.ignore();
    char AuthorToSearh[50];
    cout<<"Enter the Book's Author Name to search about it : ";

    cin.getline(AuthorToSearh,50);
    int x=0;

    cout<< "Author name   Book's Name   Publish Year   Number of versions "<<endl;
    while(!book.eof())
    {
        book.getline(b.AuthorName,50,'|');
        book.getline(b.Name,50,'|');
        book.getline(b.Publishyear,5,'|');
        book>>b.NumOfversions;

        if(strcmp(b.AuthorName, AuthorToSearh)==0)
        {
            cout<< b.AuthorName <<"  "<<b.Name<<"  "<<b.Publishyear<<"  "<<b.NumOfversions<<endl;
            x=1;
            break;
        }
    }
    if(x==0)
    {
        cout<<"not found\n";
    }
    book.close();
}

bool cmp(const FCILibraryBooks &n1,const FCILibraryBooks &n2)
{
	return n1.Name > n2.Name;
}

void FCILibraryBooks::ListInAlpha()
{
    fstream book;
    fstream temp;
    FCILibraryBooks b;

    vector<FCILibraryBooks> list;

    cin.ignore();
    cout<<"The books listed by Alphabetical order according to its name."<<endl;
    book.open("Library.txt",ios::in);
    while(!book.eof())
    {
		FCILibraryBooks t;
		
        book.getline(t.AuthorName,50,'|');
        book.getline(t.Name,50,'|');
        book.getline(t.Publishyear,5,'|');
        book>>t.NumOfversions;
        list.push_back(t);
    }
	sort(list.begin(),list.end(),cmp);
    book.close();
	book.open("Library.txt",ios::out|ios::trunc);
	for(int i = 0;i < list.size();i++)
	{
		cout<<list[i].AuthorName<<'|'<<list[i].Name<<'|'<<list[i].Publishyear<<'|'<<list[i].NumOfversions<<endl;
		book<<list[i].AuthorName<<'|'<<list[i].Name<<'|'<<list[i].Publishyear<<'|'<<list[i].NumOfversions;
	}
    book.close();
}

void FCILibraryBooks::UpdateBook()
{
    fstream book;
    fstream temp;
    FCILibraryBooks b;
    book.open("Library.txt",ios::in);
    temp.open("temp.txt",ios::out);
    char NameToUpdate[50];
    cin.ignore();
    cout<<"Enter the book's name to update record : ";
    cin.getline(NameToUpdate,50);
    while(!book.eof())
    {
        book.getline(b.AuthorName,50,'|');
        book.getline(b.Name,50,'|');
        book.getline(b.Publishyear,5,'|');
        book>>b.NumOfversions;
        if(strcmp(b.Name,NameToUpdate)==0)
        {
            cout<<"Enter the new number of versions : ";
            cin>>b.NumOfversions;

            temp<<b.AuthorName<<'|'<<b.Name<<'|'<<b.Publishyear<<'|'<<b.NumOfversions;
        }
        else
        {
            temp<<b.AuthorName<<'|'<<b.Name<<'|'<<b.Publishyear<<'|'<<b.NumOfversions;
        }

    }
    temp.close();
    book.close();

    book.open("Library.txt",ios::out);
    temp.open("temp.txt",ios::in);
    while(!temp.eof())
    {
        temp.getline(b.AuthorName,50,'|');
        temp.getline(b.Name,50,'|');
        temp.getline(b.Publishyear,5,'|');
        temp>>b.NumOfversions;
        book<<b.AuthorName<<'|'<<b.Name<<'|'<<b.Publishyear<<'|'<<b.NumOfversions;
    }
    temp.close();
    book.close();
    remove("temp.txt");
}

void FCILibraryBooks::HighestNumberOfVersions()
{
    fstream book;
    FCILibraryBooks b;
    vector<int> NOV;
    cin.ignore();
    cout<<"The book of the highest number of versions ."<<endl;
    book.open("Library.txt",ios::in);
    while(!book.eof())
    {
        book.getline(b.AuthorName,50,'|');
        book.getline(b.Name,50,'|');
        book.getline(b.Publishyear,5,'|');
        book>>b.NumOfversions;

        NOV.push_back(b.NumOfversions);
    }
    int MAX = this->getMaxInt(NOV);
    book.close();

    book.open("Library.txt",ios::in);
    while(!book.eof())
    {
        book.getline(b.AuthorName,50,'|');
        book.getline(b.Name,50,'|');
        book.getline(b.Publishyear,5,'|');
        book>>b.NumOfversions;
        if(b.NumOfversions==MAX)
        {
            cout<<b.AuthorName<<'|'<<b.Name<<'|'<<b.Publishyear<<'|'<<b.NumOfversions<<endl;
        }

    }
    book.close();
}