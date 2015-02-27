// File: student.h
// Programmer: Eric Howard
// Description: Student Object Header File

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "person.h"
#include <iomanip>

using namespace std;

class Student : public Person
{
	public:
			Student(){} ; // default constructor
			Student(string newName, int newID, string newEmail, int newYear, string newMajor) 
				: Person(newName, newID, newEmail){
				major = newMajor;
				Year = newYear; };  //1. student parameters should contain person's parameters as well.
			~Student(){}; // default desctructor
			void print();

			// get and set methods for student class
			
			int getYear(); // get current student year
			void setYear(int newYear);  // set current student year
			
			string getMajor(); // get current student major
			void setMajor(string newMajor); // set current student major


	private:
			string major;
			int Year;
			
};

#endif

