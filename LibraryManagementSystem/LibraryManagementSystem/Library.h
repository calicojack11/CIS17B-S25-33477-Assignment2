#pragma once
#include <iostream>
#include <array>
#include <vector>
#include <string>
#include "Book.h"
#include "User.h"

//library class

using namespace std;

class Library
{
private:

	//private varaibles for the library class
	//commented out varaibles unable to make work for the moment 

	vector <User> libraryMemebers; //vectors used so that memebers and books can be added while program is running
	vector <Book> libraryBooks;
	//vector <Student> studentMemeber; 
	//vector <Faculty> facultyMemeber;
	int numberOfMemebers; //ints to keept track of the number of books or memebers added to the library system
	int numberOfBooks;
	//int numberOfStudents;
	//static Library* libraryInstance;

//protected not working for use of singleton method for the library class so commented out for the moment

//protected:
//	Library()
//	{
//		
//	}
//
//	~Library()
//	{
//
//	}

public:

	//defalut constructor
	Library()
	{

	}

	//add book function to add a new book to the vector<Book> libraryBooks
	void addBook()
	{
		string bookTitle;
		string bookAuthor;
		string bookIbsn;

		cin.ignore(255, '\n');
		cin.sync();
		cin.clear();

		cout << "Book Title: ";
		cin >> bookTitle;

		cin.ignore(255, '\n');
		cin.sync();
		cin.clear();

		cout << "Book Author: ";
		cin >> bookAuthor;

		cin.ignore(255, '\n');
		cin.sync();
		cin.clear();

		cout << "Book IBSN: ";
		cin >> bookIbsn;

		Book newBook(bookTitle, bookAuthor, bookIbsn);
		newBook.bookCheckIn();
		libraryBooks.push_back(newBook);
		numberOfBooks++;

		cout << "New Book added!" << endl << endl;
	}
	
	//addUser function to add a new memeber to the libraryMemeber vector
	void addUser()
	{
		string userName;
		int id;
		char answer;
		string gradeLevel;
		string teacherLevel;
				
		cout << "Library User Name: ";
		cin >> userName;

		cin.ignore(255, '\n');
		cin.sync();
		cin.clear();

		int min = 1000;
		int max = 1000000;
		int seed = time(0);
		srand(seed);

		id = min + (rand() % max);
		cout << "Your User ID: " << id << endl;

		User memeber(userName, id);

		//unable to make adding as student or faculty so commneted out for the moment

		/*cout << "Are you a student? y/n" << endl;
		cin >> answer;*/

		/*if (answer == 'y' || answer == 'Y')
		{
			Student student(userName, id);
			student.setKindOfStudent();
			student.setAsStudent();
			studentMemeber.push_back(student);
			numberOfStudents++;
		}*/

		/*cout << "Are you a teacher? y/n" << endl;
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			Faculty faculty;
			faculty.setKindOfTeacher();
			teacherLevel = faculty.getKindOfTeacher();
			Faculty newFaculty(userName, id, teacherLevel);
			newFaculty.setAsFaculty();
			facultyMemeber.push_back(newFaculty);
		}*/
		
		libraryMemebers.push_back(memeber);
		numberOfMemebers++;
		cout << "New Library Member added!" << endl;
	}

	//function to print out the list of Books in the library
	void printOutBooks()
	{
		bool isAvailable;
		cout << "List of Library Books" << endl;
		cout << "_______________________" << endl;
		for (int i = 0; i < numberOfBooks; i++)
		{
			cout << "Book " << (i + 1) << ": " << endl;
			cout << "Title: ";
			libraryBooks[i].bookTitle();
			cout << endl;
			cout << "Author: ";
			libraryBooks[i].bookAuthor();
			cout << endl;
			cout << "IBSN: ";
			libraryBooks[i].bookIbsn();
			cout << endl;
			cout << "Book Availablity: ";
			isAvailable = libraryBooks[i].checkAvailablity();
			if (isAvailable == true)
			{
				cout << "Checked in" << endl;
			}
			else
			{
				cout << "Checked out" << endl;
			}
			cout << endl;
 		}
	}

	//function to print out the list of memebers
	void printOutMemebers()
	{
		cout << "List of Memebers" << endl;
		cout << "_________________" << endl;
		for (int i = 0; i < numberOfMemebers; i++)
		{
			cout << "Library Memeber " << (i + 1) << endl;
			cout << "Memeber Name: ";
 			libraryMemebers[i].printName();
			cout << endl;
			cout << "Memeber ID: ";
			libraryMemebers[i].printUserID();
			cout << endl;
		}
	}

	//function to check out a book from the library and for it to be mark within the program
	void bookCheckOut(Library library)
	{
		int bookNum;
		library.printOutBooks();

		cout << endl << endl;
		cout << "What book do you what to check out from the list above? (Please enter number for the book; ie Book 1 = 1)" << endl;
		cin >> bookNum;
		libraryBooks[bookNum - 1].bookCheckOut();
	}

	//function to check in a book and for it to be marked within the program
	void bookCheckIn(Library library)
	{
		int bookNum;
		library.printOutBooks();

		cout << endl << endl;
		cout << "What book are you checking in from list of above? (Please enter a number for the book; ie Book 1 = 1" << endl;
		cin >> bookNum;
		libraryBooks[bookNum - 1].bookCheckIn();
	}
};

