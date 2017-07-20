#include "HashTable.h"
#include <string>

using std::cout;
using std::endl;

HashTable::HashTable()
{
	for (int i = 0; i < TableSize; i++)
	{
		Htable[i] = new Item;
		Htable[i]->name = "";
		Htable[i]->id = "";
		Htable[i]->next = nullptr;
	}
}

int HashTable::Hash(string key)
{
	int total(0);
	int index;

	for (int i = 0; i < key.length(); i++)
	{
		total += (int)key[i];
	}
	
	index = total % TableSize;

	return index;
}

void HashTable::AddItem(string n, string ID)
{
	//hash the name to get an index/bucket
	int idx = Hash(n);

	//insert at that element in htable pointer array if available
	if (Htable[idx]->name == "")
	{
		//empty spot
		Htable[idx]->name = n;
		Htable[idx]->id = ID;
	}
	else
	{
		Item * ptr = Htable[idx];
		Item * newitem = new Item; 
		
		newitem->id = ID;
		newitem->name = n;
		newitem->next = nullptr;

		while (ptr->next != nullptr)
		{
			ptr = ptr->next;
		}
		ptr->next = newitem;
	}
}

int HashTable::NumberOfItemsInIndex(int index)
{
	int num = 0;
	if (Htable[index]->name == "")
	{
		//not currently used, return 0
		return num;
	}
	else
	{
		//contains at least one, count and return total
		num++;
		Item * p = Htable[index];
		while (p->next != nullptr)
		{
			num++;
			p = p->next;
		}
		return num;
	}
}

void HashTable::PrintTable()
{
	int numElements;

	for (int i = 0; i < TableSize; i++)
	{
		cout << "-----------------------\n";
		numElements = NumberOfItemsInIndex(i);
		cout << "Index: " << i << endl;
		cout << "Name: " << Htable[i]->name << endl;
		cout << "Favorite food " << Htable[i]->id << endl;
		cout << "Number of items: " << numElements << endl;
		//cout << "-----------------------\n";
	}
}

void HashTable::PrintItemsAtIndex(int idx)
{
	Item * ptr = Htable[idx];

	if (ptr->name == "")
	{
		//empty
		cout << "Index: " << idx << " is empty!" << endl;
	}
	else
	{
		cout << "Index: " << idx << " includes: " << endl;

		while (ptr != nullptr)
		{
			cout << "-----------------------\n";
			cout << "Name: " << ptr->name << endl;
			cout << "Favorite food: " << ptr->id << endl;
			cout << "-----------------------\n";
			ptr = ptr->next;
		}
	}
}

void HashTable::FindFood(string n)
{

	int i = Hash(n);

	if (Htable[i]->next == nullptr)
	{
		cout << n << "'s favorite food is: " << Htable[i]->id << endl;
	}
	else
	{
		Item * ptr = Htable[i];
		while (ptr != nullptr)
		{
			if (ptr->name == n)
			{
				cout << n << "'s favorite food is: " << ptr->id << endl;
				break;
			}
			ptr = ptr->next;
		}
	}
}

HashTable::~HashTable()
{
	//getting rid of memory leaks
	for (int i = 0; i < TableSize; i++)
	{
		if (Htable[i]->next != nullptr)
		{
			//more than one in current index
			Item * ptr = Htable[i];
			while (ptr != nullptr)
			{
				Item * tmp = ptr;
				ptr = ptr->next;
				delete tmp;
			}
			delete ptr;
		}
		else
		{
			delete Htable[i];
		}
	}
}