#include <iostream>
#include "LinkedList.h"

using namespace std;

void main() {
	LinkedList ll(123);

	ll.deleteLast();

	ll.printList();
}