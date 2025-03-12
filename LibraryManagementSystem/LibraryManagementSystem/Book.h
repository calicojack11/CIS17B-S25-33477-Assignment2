#pragma once
#include <iostream>
#include <string>

//Book class for creating a book object

using namespace std;

class Book
{
private:

	//private varaibles 
	string title;
	string author;
	string isbn;
	bool availablity;

public:

	//constructors: default and one with paramenters for title, author and isbn relating to Book object
	Book()
	{

	}

	Book(string t, string name, string num)
	{
		title = t;
		author = name;
		isbn = num;
	}

	//functions to set title, author and ibsn varaible
	void setTitle(string t)
	{
		title = t;
	}
	void setAuthor(string name)
	{
		author = name;
	}
	void setIsbn(string num)
	{
		isbn = num;
	}

	//functions to set availbity to either false or true depending on if the book is checked in or out
	void bookCheckOut()
	{
		availablity = false;
	}

	void bookCheckIn()
	{
		availablity = true;
	}

	//functions to print out Book object variables of title, author and ibsn
	void bookTitle()
	{
		cout << title;
	}

	void bookAuthor()
	{
		cout << author;
	}

	void bookIbsn()
	{
		cout << isbn;
	}		

	//funciton to return availablity
	bool checkAvailablity()
	{
		return availablity;
	}
};

