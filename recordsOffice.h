// File: recordsOffice.h
// Programmer: Eric Howard
// Description: Records Office Object Header File

#include "student.h"
#include "faculty.h"
#include "administrator.h"
#include "person.h"
#include "hashTable.h"
#include <iostream>
#include <string>
#include <list>
#include <fstream>

#ifndef RECORDSOFFICE_H
#define RECORDSOFFICE_H

using namespace std;

class recordsOffice
{
	public:
			recordsOffice(){}; // constructor
			~recordsOffice(){}; // destructor
			void importRecords(string filename); // use filename to import student records
	
	private:
			// Declare list
			hashTable<Person> newTable;
};
#endif


