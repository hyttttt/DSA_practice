#pragma once
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Node.h"

class LinkedList {
private:
	Node* head;
	Node* tail;
	int len;

public:
	/*constructors& destructors*/
	LinkedList(int value);
	~LinkedList();

	/*get value*/ 
	int getHead();
	Node* get(int index);
	void printList();

	/*add node*/ 
	void append(int value);
	void prepend(int value);
	bool set(int index, int value);
	bool insert(int index, int value);

	/*remove node*/
	void deleteLast();
	void deleteFirst();
};

#endif // !LINKED_LIST_H