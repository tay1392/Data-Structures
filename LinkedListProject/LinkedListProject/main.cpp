/*
*	Author: Taylor Caldwell
*	Date: July 17, 2017
*	Porject: Linked list implementation
*/

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

#include <iostream>
#include "LinkedList.h"
using std::cout;
using std::endl;

void TestList();

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	TestList();
	return 0;
}

void TestList()
{
	LinkedList ll;
	LinkedList ll2;

	cout << "Displaying head to tail" << endl << endl;
	ll.AddToHead("Bob", 1);
	ll.AddToHead("Casey", 2);
	ll.AddToHead("Joe", 3);
	ll.AddToHead("Sam", 4);
	ll.AddToHead("Thor", 5);
	ll.AddToHead("Gus", 6);	
	ll.AddToHead("Jim", 7);
	ll.Display();

	cout << "\n\nDisplaying tail to head" << endl << endl;
	ll2.AddToTail("James", 1);
	ll2.AddToTail("Connor", 2);
	ll2.AddToTail("Justyn", 3);
	ll2.AddToTail("Cameron", 4);
	ll2.AddToTail("Jose", 5);
	ll2.AddToTail("Zach", 6);
	ll2.AddToTail("Max", 7);
	ll2.Display();
}