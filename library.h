/**
 *  @file    library.h
 *  @author  Mahmoud Ahmed Tawfik (20160227) - Sara Zakareia Adam (20170384) - Lamya Raed Aly (20170339)
 *  @date    31/03/2019
 *  @version 1.0
 *
 *  @Problem library(P1)
 *
 */

#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

class FCILibraryBooks
{
public:
    char AuthorName[50];
    char Name[50];
    char Publishyear[5];
    int NumOfversions;


	void AddBook();
	void SearchByName();
	void SearchByAuthor();
	void ListInAlpha();
	void UpdateBook();
	void HighestNumberOfVersions();

	int getMaxInt(vector<int>& v);
	void printMenu();
};




#endif // LIBRARY_H_INCLUDED
