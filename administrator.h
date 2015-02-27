// File: administrator.h
// Programmer: Eric Howard
// Description: Administrator Object Header File

#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include <iostream>
#include <string>
#include "person.h"
#include <iomanip>
using namespace std;

class Administrator : public Person
{
	public:
			Administrator(){} ; // default constructor
			Administrator(string newName, int newID, string newEmail, int newYear, string newMajor, string newTitle) 
				: Person(newName, newID, newEmail){
				title = newTitle; };  
			~Administrator(){}; // default desctructor
			void print();
	
			// get and set methods for Administrator class

			string getTitle(); // get current Administrator title
			void setTitle(string newTitle); // set current Administrator title


	private:
			string title;
			
};
#endif