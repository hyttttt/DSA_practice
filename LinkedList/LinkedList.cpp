#include <iostream>
#include "LinkedList.h"

using namespace std;

/*constructors& destructors*/

LinkedList::LinkedList(int value) {
	Node* newNode = new Node(value);
	
	this->head = newNode;
	this->tail = newNode;
	this->len = 1;
}

LinkedList::~LinkedList() {
	Node* temp = this->head;

	while (this->head) {
		this->head = this->head->next;
		delete temp;
		temp = this->head;
	}
}

/*get value*/

int LinkedList::getHead() {
	return this->head->value;
}

void LinkedList::printList() {
	Node* temp = this->head;
	while (temp) {
		cout << temp->value << endl;
		temp = temp->next;
	}
}

/*add node*/

void LinkedList::append(int value) {
	Node* newNode = new Node(value);
	
	// check if linked list is empty
	if (this->len == 0) {
		this->head = newNode;
		this->tail = newNode;
	}
	else {
		this->tail->next = newNode;
		this->tail = newNode;
	}
	
	this->len++;
}

/*remove node*/

void LinkedList::deleteLast() {
	if (this->len == 0) {
		return;
	}
	else if (this->len == 1) {
		delete this->tail;

		this->head = nullptr;
		this->tail = nullptr;
		this->len = 0;
	}
	else {
		// find the node before tail
		Node* pre = this->head;
		while (pre->next != this->tail) {
			pre = pre->next;
		}

		// delete the last node
		Node* temp = this->tail;
		this->tail = pre;
		this->tail->next = nullptr;
		delete temp;

		this->len--;
	}
}