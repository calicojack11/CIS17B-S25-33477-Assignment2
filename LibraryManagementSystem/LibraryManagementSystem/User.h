#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>

// User class for creating a user with in the library system

using namespace std;

class User
{
protected:
	//varaibles protected to be allowed access from classes (student and fauclty) that inheirt from the user class

	string name;
	int userID;

public:

	//two constructors: defualt and one with parameters
	User()
	{

	}

	User(string n, int id)
	{
		name = n;
		userID = id;
	}

	//funcitons to set name and user id
	void setName(string n)
	{
		name = n;
	}

	void setUserID(int id)
	{
		//user of a random number generator to create randomoize user ids

		int min = 1000;
		int max = 1000000;
		int seed = time(0);
		srand(seed);

		id = min + (rand() % max);

		userID = id;
	}

	//two functions to print out the name and user id of User class objects
	void printName()
	{
		cout << name;
	}

	void printUserID()
	{
		cout << userID;
	}
};

