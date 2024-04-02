#include <iostream>
#include "LinkedList.h"

using namespace std;

void main() {
	LinkedList ll(123);

	ll.prepend(0);
	ll.deleteLast();

	ll.printList();
}