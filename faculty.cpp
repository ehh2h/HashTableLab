#include "faculty.h"
void Faculty::print()
{
	// print out faculty id #
	cout << "Faculty:" << endl;
	cout << "\tFull Name:" << setw(12) << name << endl;
	cout << "\tM Number:" << setw(13) << Mnumber << endl;
	cout << "\tEmail Addr:" << setw(20) << email << endl;
	cout << "\tDepartment:" << setw(10) << department << endl;
	cout << "\tTenured:" << setw(20) << tenured << endl;
	cout << endl;
}

string Faculty::getDepartment()
{
	return department;
}
// Set faculty department
void Faculty::setDepartment(string newDepartment)
{
	department = newDepartment;
}
// Get faculty tenure
string Faculty::getTenured()
{
	return tenured;
}
// Set faculty tenure
void Faculty::setTenured(string newTenured)
{
	tenured = newTenured;
}
