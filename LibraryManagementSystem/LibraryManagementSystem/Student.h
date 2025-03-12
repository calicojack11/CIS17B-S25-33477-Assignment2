#pragma once
#include <iostream>
#include <string>
#include "User.h"

// Student class inheirts from User

using namespace std;

class Student: public User
{
private:
	//private varaibles of a bool to set a user as student and to know what kind of student
	bool isStudent;
	string kindOfStudent;

public:

	//construtors: defualt and one with paramenters using the User class varaibles
	Student()
	{

	}

	Student(string n, int id)
	{
		name = n;
		userID = id;
	
	}
	
	//function to determine the kind of student
	void setKindOfStudent()
	{
		string gradeChoice;

		cout << "What grade level are you? (Enter number)" << endl;
		cout << "1. Elemetary school student (1 - 5 grade)" << endl;
		cout << "2. Middle school student (6 - 8 grade)" << endl;
		cout << "3. High school student (9 - 12 grade)" << endl;
		cout << "4. College student" << endl;
		cin >> gradeChoice;

		if (gradeChoice == "1")
		{
			kindOfStudent = "Elemntary Student";
		}
		else if (gradeChoice == "2")
		{
			kindOfStudent = "Middle School Student";
		}
		else if (gradeChoice == "3")
		{
			kindOfStudent = "High School Student";
		}
		else
		{
			kindOfStudent = "College Student";
		}
	}

	//function to return the kind of student 
	string getKindOfStudent ()
	{
		return kindOfStudent;
	}

	//function to set isStudent to true
	void setAsStudent()
	{
		isStudent = true;
	}	
};

