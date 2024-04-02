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

Node* LinkedList::get(int index) {
	if (index >= this->len || index < 0) return nullptr;
	
	Node* temp = this->head;

	for (int i = 0; i < index; i++) {
		temp = temp->next;
	}

	return temp;
	
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

void LinkedList::prepend(int value) {
	Node* newNode = new Node(value);

	// check if linked list empty
	if (this->len == 0) {
		this->head = newNode;
		this->tail = newNode;
	}
	else {
		newNode->next = this->head;
		this->head = newNode;
	}

	this->len++;
}

bool LinkedList::set(int index, int value) {
	Node* temp = this->get(index);

	if (temp) {
		temp->value = value;
		return true;
	}

	return false;
}

bool LinkedList::insert(int index, int value) {
	if (index < 0 || index > this->len) {
		return false;
	}
	else if (index == 0) {
		this->prepend(value);
	}
	else if (index == this->len) {
		this->append(value);
	}
	else {
		Node* newNode = new Node(value);
		Node* pre = this->get(index - 1);

		newNode->next = pre->next;
		pre->next = newNode;
	}

	this->len++;
	return true;
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

void LinkedList::deleteFirst() {
	if (this->len == 0) {
		return;
	}
	else if (this->len == 1) {
		delete this->head;

		this->head = nullptr;
		this->tail = nullptr;
		this->len = 0;
	}
	else {
		Node* temp = this->head;
		this->head = this->head->next;

		delete temp;
		this->len--;
	}
}