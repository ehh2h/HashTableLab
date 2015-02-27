// File: faculty.h
// Programmer: Eric Howard
// Description: Faculty Object Header File

#ifndef FACULTY_H
#define FACULTY_H

#include <string>
#include "person.h"
#include <iomanip>

using namespace std;

class Faculty : public Person
{
	public:
			Faculty(){} ; // default constructor
			Faculty(string newName, int newID, string newEmail, int newYear, string newMajor, string newTitle, string newDepartment, string newTenured) 
				: Person(newName, newID, newEmail){
				department = newDepartment;
				tenured = newTenured; };  
			~Faculty(){}; // default desctructor
			void print();
			
			string getDepartment(); // get current faculty year
			void setDepartment(string newDepartment);  // set current faculty year
			
			string getTenured(); // get current faculty major
			void setTenured(string newTenured); // set current faculty major


	private:
			string department,tenured;
			
};
#endif