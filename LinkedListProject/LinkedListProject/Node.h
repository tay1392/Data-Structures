#include <iostream>
using std::string;

#ifndef NODE
#define NODE

class Node
{
	public:
		Node(); 
		Node * Next;
		string name; //some sort of data to keep inside
		int id;
};

#endif