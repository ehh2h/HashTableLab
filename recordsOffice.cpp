#include "recordsOffice.h"
// Function: importRecords
// Purpose: Read in commands from file to populate records.
// Before: Take in filename
// After: File has been read and list has been populated with correct student records.
void recordsOffice::importRecords(string filename)
{
	ifstream inData;
	string line,newName,newEmail,newMajor,newDepartment,newTenured,newTitle;
	float loadFactor = 0.0;
	int newID = 0,newYear = 0,bucketSize = 0;
	Person* currPerson;
	char temp;
	inData.open(filename);
	inData >> bucketSize; 
	while (!inData.eof()) 
	{
		while(inData >> temp)
		{
			switch(temp)
			{
			
				case('S'): // Add a student
				{
					inData >> newName >> newID >> newEmail >> newYear >> newMajor;
					cout << "Adding " << newID << "..." << endl;
					cout << endl;
					Student* currStudent;
					currStudent = new Student(newName,newID,newEmail,newYear,newMajor);
					currPerson = currStudent;
					currPerson->print();
					newTable.insertP(currPerson);
					loadFactor = newTable.loadFactor();
					cout << "Alpha: " << loadFactor << endl;
					cout << endl;
				
					break;
				}
				case('F'): // Add a faculty member
				{
					inData >> newName >> newID >> newEmail >> newDepartment >> newTenured;
					cout << "Adding " << newID << "..." << endl;
					cout << endl;
					Faculty* currFaculty;
					currFaculty = new Faculty(newName,newID,newEmail,newYear,newMajor,newTitle,newDepartment,newTenured);
					currPerson = currFaculty;
					currPerson->print();
					newTable.insertP(currPerson);
					loadFactor = newTable.loadFactor();
					cout << "Alpha: " << loadFactor << endl;
					cout << endl;
				
					break;
				}
				case('A'): // Add a administrator member
				{
					inData >> newName >> newID >> newEmail >> newTitle;
					cout << "Note: Adding " << newID << "..." << endl;
					cout << endl;
					Administrator* currAdmin;
					currAdmin = new Administrator(newName,newID,newEmail,newYear,newMajor,newTitle);
					currPerson = currAdmin;
					currPerson->print();
					newTable.insertP(currPerson);
					loadFactor = newTable.loadFactor();
					cout << "Alpha: " << loadFactor << endl;
					cout << endl;
				
					break;
				}
				case('D'): // Delete a person
				{
					inData >> newName;
					cout << "Removing " << newName << " ..." << endl;
					newTable.deleteP(newName);
					loadFactor = newTable.loadFactor();
					cout << "Alpha: " << loadFactor << endl;
					cout << endl;
					break;
				}
				case('P'): // Print a person
				{
					inData >> newName;
					cout << "Finding " << newName << "..." << endl;
					newTable.printP(newName);

					break;
				
				}
				case('L'): // Print a person
				{
					cout << "Dumping ..." << endl;
					cout << endl;
					newTable.dump();
				
					break;
				
				}
			}
		}
	}

	inData.close();

}