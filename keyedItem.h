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
