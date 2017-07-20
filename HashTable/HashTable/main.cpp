/*
*	Taylor Caldwell
*	July 10, 2017
*	Hash Table implementation
*
*/

#include "HashTable.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

void TestHashTable();

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	TestHashTable();

	return 0;
}

void TestHashTable()
{
	HashTable hash;

	//name, favorite food
	hash.AddItem("Paul", "sandwiches");
	hash.AddItem("John", "pasta");
	hash.AddItem("Kim", "cookies");
	hash.AddItem("Sally", "chips");
	hash.AddItem("Jeremy", "pizza");
	hash.AddItem("Sam", "ice cream");
	hash.AddItem("Sarah", "salad");
	hash.AddItem("Alton", "toast");
	hash.AddItem("George", "pancakes");
	hash.AddItem("Gus", "cake");
	hash.AddItem("Thor", "soup");
	hash.AddItem("Hobbs", "candy");

	hash.PrintTable();
	system("pause");
	//hash.PrintItemsAtIndex(9);

	//using the hash function to quickly find a users fav food
	//hash.FindFood("Sam");
}