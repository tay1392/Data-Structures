/*
Taylor Caldwell
July 10, 2017
Hash Table implementation
*/
#include <iostream>
using std::string;

#ifndef HASHTABLE
#define HASHTABLE

class HashTable
{
	public:
		HashTable();
		~HashTable();
		int Hash(string key);
		void AddItem(string n, string ID);
		int NumberOfItemsInIndex(int index);
		void PrintTable();
		void PrintItemsAtIndex(int idx);
		void FindFood(string name);

	private:
		static const int TableSize = 20;
		struct Item
		{
			string name;
			string id;
			Item * next;
		};

		Item * Htable[TableSize];
};

#endif