// File: keyedItem.h
// Taken from DR.CARROLS REPOSITORY (cs.mtsu.edu/~hcarrol/private)
// Description: Used as a base class from all persons to inherit a key item data member.

#include <string>

using namespace std;

typedef string KeyType;

class keyedItem{
	public:
			keyedItem() {}
			keyedItem(const KeyType& keyValue) : searchKey(keyValue) {}

			KeyType getKey() const{  return searchKey; }
	private:
			KeyType searchKey;
}; // end KeyedItem