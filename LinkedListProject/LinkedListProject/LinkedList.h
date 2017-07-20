#include <iostream>
#include "Node.h"

#ifndef LINKED_LIST
#define LINKED_LIST

class LinkedList
{
	public:
		LinkedList();	//ctor
		~LinkedList();	//dtor
		void AddToHead(string n, int id);
		void AddToTail(string n, int id); 
		Node * CreateNode(string n, int id);
		void DeleteHead();
		void DeleteTail();
		void Display();
		void Reverse();
		void DeleteList();
	private:
		Node * head;
		Node * tail; 
};

#endif