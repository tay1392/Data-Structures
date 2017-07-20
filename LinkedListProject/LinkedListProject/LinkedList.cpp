#include <iostream>
#include "LinkedList.h"
#include "String"
using std::cout;
using std::endl;
using std::string;

LinkedList::LinkedList()
{
	head = nullptr;
	tail = nullptr;
}

void LinkedList::AddToHead(string n, int i)
{
	//create the new node with data
	Node * nn = CreateNode(n, i);

	//empty list
	if (head == nullptr)
	{
		head = nn;
		tail = nn;
	}
	else //non-empty list
	{
		nn->Next = head;
		head = nn;
	}
}

void LinkedList::AddToTail(string n, int i)
{
	Node * nn = CreateNode(n, i);

	//empty list, first node
	if (tail == nullptr)
	{
		tail = nn;
		head = nn;
	}
	else
	{
		nn->Next == nullptr; //redundant but just in case
		tail->Next = nn;
		tail = nn;
	}
}

void LinkedList::Display()
{
	Node * tmp;// = new Node();
	tmp = head;

	while (tmp != nullptr)
	{
		cout << "Name: " << tmp->name << endl;
		cout << "ID: " << tmp->id << endl;
		cout << "-----------------------------" << endl;

		tmp = tmp->Next;
	}
}

Node * LinkedList::CreateNode(string n, int i)
{
	Node * nn = new Node();
	nn->name = n;
	nn->id = i;

	return nn;
}

void LinkedList::DeleteList()
{
	/* deref head_ref to get the real head */
	Node * current = head;
	Node * nxt;

	while (current != NULL)
	{
		nxt = current->Next;
		delete current;
		current = nxt;
	}

	/* deref head_ref to affect the real head back
	in the caller. */
	head = nullptr;
}

LinkedList::~LinkedList()
{
	DeleteList();
}