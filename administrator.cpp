#include "administrator.h"
void Administrator::print()
{
	// print out Administrator id #
	cout << "Administrator:" << endl;
	cout << "\tFull Name:" << setw(12) << name << endl;
	cout << "\tM Number:" << setw(13) << Mnumber << endl;
	cout << "\tEmail Addr:" << setw(20) << email << endl;
	cout << "\tTitle:" << setw(13) << title << endl;
	cout << endl;
}

string Administrator::getTitle()
{
	return title;
}
// Set Administrator title
void Administrator::setTitle(string newTitle)
{
	title = newTitle;
}
