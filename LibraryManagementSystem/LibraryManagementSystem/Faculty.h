#pragma once
#include <iostream>
#include "User.h"

//faculty class inheirts from User class

using namespace std;

class Faculty: public User
{
private:

	//private variables for Fauclty class 
	bool isFaculty;
	string kindOfTeacher;
	
public:
	//constructors: defualt and one with paramenters from the User class variables
	Faculty()
	{

	}

	Faculty(string n, int id)
	{
		name = n;
		userID = id;
	}

	//function to determine kind of teacher
	void setKindOfTeacher()
	{
		char answer;
		cout << "Do you teach college? y/n" << endl;
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{
			kindOfTeacher = "College Professor";
		}
		else
		{
			kindOfTeacher = "Teacher";
		}
	}

	//function to return kind of teacher
	string getKindOfTeacher()
	{
		return kindOfTeacher;
	}

	//function to set isFaculty to true
	void setAsFaculty()
	{
		isFaculty = true;
	}
};