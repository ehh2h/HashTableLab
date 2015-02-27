// File: hashTable.h
// Programmer: Eric Howard
// Description: Templated Hash Table header file

#include <cmath>
#include <string>
#include <sstream> 
#include <iostream>
#include <list>

using namespace std;

#ifndef HASHTABLE_H
#define HASHTABLE_H

template<class T>
class hashTable
{
	public:
			hashTable<T>(); // Default constructor to create the hash table
			hashTable<T>(int newSize);
			~hashTable<T>(); // Default destructor deletes all elements in hashtable

			void insertP(T*); // Insert a new person in the hash table.

			void deleteP(string); // Delete a person from the hash table.
			void printP(string); // Print person from the hash table.
			void dump(); // Print all

			float loadFactor();
	private:
			list<T*>* newTablePtr; // Pointer needed to dynamically allocated table size with NEW
			int tableSize; // keep track of table size
			int hash(string searchKey); // Search key used for has function in table.
			int numOfItems; // keep track of # of items in table
};


#endif HASHTABLE_H

// Default Constructor
template<class T>
hashTable<T>::hashTable()
{
	numOfItems = 0;
	tableSize = 100; // Default is table size 100
	newTablePtr = new list<T*>[100];
}

// Dynamic Hashtable Constructor
template<class T>
hashTable<T>::hashTable(int newSize)
{
	numOfItems = 0;
	tableSize = newSize; // Table size is defined by user
	newTablePtr = new list<T*>[newSize];
}

// Default Destructor
template<class T>
hashTable<T>::~hashTable()
{
	list<T*>::iterator it, stop;
	int i = 0;
	while (i < tableSize)
	{
		it = newTablePtr[i].begin();
		stop = newTablePtr[i].end();
		while (it != stop)
		{
			newTablePtr[i].pop_back(); // Clean em up
			it = newTablePtr[i].begin();
			stop = newTablePtr[i].end();
		}
		i++;
	}
}
// ****** HASH FUNCTION ******* //
// Description: Calculate the hash by taking the username, converting to an integer, then MOD it by the tablesize.
// Returns: Attempts to evenly distribute items in the hash table.
template<class T>
int hashTable<T>::hash(string searchKey)
{
	int temp = 1337;
	unsigned int hashNUM = 0; // MUST BE UNSIGNED to allow for huge #'s that could be calculated
	
	for(int i = 0; i < searchKey.length(); i++)
	{
      hashNUM = (hashNUM * temp) + searchKey[i]; // So hashNUM calculates it by multiuplying by the seed and the nadding the VALUE of the letter at searchkey[i]
	}

	return (hashNUM % tableSize); // Hash Function : Attempts to distribute items evenly in the table.
}

// Insert Function
// Description: Insert an item into the table.
template<class T>
void hashTable<T>::insertP(T* Person)
{
	int hashLocation;
	hashLocation = hash((Person->getKey()));
	newTablePtr[hashLocation].push_back(Person);
	numOfItems++; // keep track of items in table
}

// Delete Function
// Description: Deletes an item from the table.
template<class T>
void hashTable<T>::deleteP(string name)
{
	
	int visited = 0;
	int hashLocation = hash(name);
	list<T*>::iterator it, stop;

	it = newTablePtr[hashLocation].begin();
	stop = newTablePtr[hashLocation].end();
	if (numOfItems == 0)
	{
		cout << "ALERT: " << "\"" << name << "\" " << "not found!" << endl;
	}
	else if(it != stop)
	{
		visited++;
		while(((*it)->getKey() != name) && (it != stop))
		{
			visited++;
			it++;
		}

		if(*it != NULL)
		{
			newTablePtr[hashLocation].erase(it);
		}
		else
		{
			cout << "ALERT: " << "\"" << name << "\" " << "not found!" << endl;
		}
	}
	else
	{
		cout << "ALERT: " << "\"" << name << "\" " << "not found!" << endl;
	}
	cout << visited << " items visited for remove()" << endl;
}

// Dump Function
// Description: Dumps all items from the hash table to stdout.
template<class T>
void hashTable<T>::dump()
{
	if(numOfItems > 0)
	{
		list<T*>::iterator it, stop;
		int i = 0;
		while (i < tableSize)
		{
			it = newTablePtr[i].begin();
			stop = newTablePtr[i].end();
			while (it != stop)
			{
				if (*it != NULL)
				{
					int tempIndex;
					tempIndex = hash((*it)->getKey()); // grab the index
					cout << "Bucket index " << tempIndex << ":" << endl;

					(*it)->print();
				}
			it++;
			}
			i++;
		}
	}
}

// Print Function
// Description: Prints specific item from the hash table.
template<class T>
void hashTable<T>::printP(string searchKey)
{
	int visited = 0;
	int hashLocation = hash(searchKey); // grab location to look up
	list<T*>::iterator it, stop;

	it = newTablePtr[hashLocation].begin();
	stop = newTablePtr[hashLocation].end();

	if(it != stop)
	{
		visited++; 
		while(((*it)->getKey() != searchKey) && (it != stop))
		{
			visited++; // keep track of visits
			it++;
		}
		cout << visited << " items visited for find()" << endl; // Didn't find a need for find function
		if(*it != NULL)
		{
			(*it)->print(); // print em!
		}
		else
		{
			cout << "ALERT: " << "\"" << searchKey << "\" " << "not found!" << endl;
		}
	}
}

// Load Factor Function
// Description: Calculate the load factor of the table at the current time the function is called.
// Returns: ALPHA
template<class T>
float hashTable<T>::loadFactor()
{
	float factorA = (numOfItems/tableSize);
	return factorA;
}



