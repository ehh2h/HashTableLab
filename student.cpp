#include "student.h"
// Function: print
// Purpose: Print out all data members from student.
// Before: 
// After: Student prints out all of its data members fomatted correctly.
void Student::print()
{
	// print out student id #
	cout << "Student:" << endl;
	cout << "\tFull Name:" << setw(12) << name << endl;
	cout << "\tM Number:" << setw(13) << Mnumber << endl;
	cout << "\tEmail Addr:" << setw(20) << email << endl;
	cout << "\tGrade:" << setw(13) << Year << endl;
	cout << "\tMajor:" << setw(19) << major << endl;
	cout << endl;
}

// Get and Set methods for each data member begin
/////////////////////////////////////////////////

// Get student grade
int Student::getYear()
{
	return Year;
}

// Set student grade
void Student::setYear(int newYear)
{
	Year = newYear;
}


// Get student major
string Student::getMajor()
{
	return major;
}

// Set student major
void Student::setMajor(string newMajor)
{
	major = newMajor;
}
