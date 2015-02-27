// File: Person.h
// Programmer: Eric Howard
// Description: Abstract Base Class Person

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include "keyedItem.h"
using namespace std;

class Person : public keyedItem
{
	public:
			Person(): name("Default"), email("unknown"), Mnumber(0) {}; // default constructor
			Person::Person(string newName, int newID, string newEmail) : keyedItem(newName), name(newName), email(newEmail), Mnumber(newID) {};
			~Person(){}; // default desctructor
			virtual void print() = 0; // *** pure virtual method *** //

			// get and set methods for person class
			int getID(){ return Mnumber; }; 
			void setID(int id){ Mnumber = id; }; 
			
			string getName(){ return name; }; 
			void setName(string newName){ name = newName; };  

			string getEmail(){ return email; };  
			void setEmail(string newEmail){ email = newEmail; };  

	protected:
			string name,email;
			int Mnumber;
			
};

#endif


