#include <iostream>
#include <string>
#include <array>
#include "Book.h"
#include "Library.h"
#include "User.h"
#include "Student.h"
#include "Faculty.h"

//program that mangaes a city library by adding memebers, books, and making transactions
//classes are in header files and added to the main program using #include

using namespace std;

//function protypes
void mainMenu();
void manageBooksMenu();
void manageMemebersMenu();
void makeTransactionMenu();

int main()
{
	//varaiables 
	Library cityLibrary;
	vector<Book> libraryBooks;
	vector<User> libraryMemeber;
	int mainMenuChoice;
	int menuChoice;

	//welcome message the user
	cout << "Welcome to the city Library" << endl;

	//do-while loop to show main menu while going through the options until user decides to quit
	do
	{
		mainMenu();
		cin >> mainMenuChoice;
		//if-else if statemnts used to move through the menu choices
		if (mainMenuChoice == 1)
		{
			//do-while loop for the first menu giving options to add books and get a list of the books at the library
			do
			{
				manageBooksMenu();
				cin >> menuChoice;

				//switch statement to move through the possible chocies 
				switch (menuChoice)
				{
				case 1:
					cityLibrary.addBook();
					cout << endl;
					break;

				case 2:
					cityLibrary.printOutBooks();
					cout << endl;
					break;
				case 3:
					cout << "Returning to Main Menu" << endl << endl;
					break;
				}

			} while (menuChoice != 3);
		}

		else if(mainMenuChoice == 2)
		{
			//do-while loop for the memenber menu showing options to add memebers and get a list of memebers
			do
			{
				manageMemebersMenu();
				cin >> menuChoice;

				//switch statment to go through menu choices 
				switch (menuChoice)
				{
				case 1: 
					cityLibrary.addUser();
					cout << endl;
					break;
					
				case 2:
					cityLibrary.printOutMemebers();
					cout << endl;
					break;

				case 3:
					cout << "Returning to Main Menu" << endl << endl;
					break;
				}

			} while (menuChoice != 3);
		}

		else if (mainMenuChoice == 3)
		{
			//do-while loop to go through the transction menu of either checking out a book or checking in one
			do 
			{
				makeTransactionMenu();
				cin >> menuChoice;

				//switch statment to go through menu choices
				switch (menuChoice)
				{
				case 1:
					cityLibrary.bookCheckOut(cityLibrary);
					break;
					
				case 2:
					cityLibrary.bookCheckIn(cityLibrary);
					break;
					
				case 3:
					cout << "Returning to Main Menu" << endl << endl;
				}

			} while (menuChoice != 3);
		}

		//last else to display a message when ending the program
		else
		{
			cout << "Thank you for visting the city library" << endl;
		}
		
		

	} while (mainMenuChoice != 4);
	
	return 0;
}

//main menu function to ask what the user wants to do and gives them options of managing books, managing memebers, making transactions, or leaving the program
void mainMenu()
{
	cout << "What would you like to do?" << endl;
	cout << "1. Manage Books" << endl;
	cout << "2. Manage Memebers" << endl;
	cout << "3. Make Transaction" << endl;
	cout << "4. Leave Program" << endl;
}

//manage books menu funciton with the options of adding a book, seeing a list of books or returning to the main menu
void manageBooksMenu()
{
	cout << "Manage Books" << endl;
	cout << "____________" << endl;
	cout << "1. Add Book" << endl;
	cout << "2. List Books" << endl;
	cout << "3. Return to Main Menu" << endl;
}

//manage memebers menu function with options to add memebers, seeing a list of memebers or returning to the main menu
void manageMemebersMenu()
{
	cout << "Manage Memebers" << endl;
	cout << "_______________" << endl;
	cout << "1. Add Memeber" << endl;
	cout << "2. List Memebers" << endl;
	cout << "3. Return to Main Menu" << endl;
}

//make transaction menu function with options to check out a book, check in a book, or return to the main menu
void makeTransactionMenu()
{
	cout << "Make a Transction" << endl;
	cout << "_________________" << endl;
	cout << "1. Check out a book" << endl;
	cout << "2. Check in a book" << endl;
	cout << "3. Return to Main Menu" << endl;
}