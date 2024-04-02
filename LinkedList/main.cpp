#include <iostream>
#include "LinkedList.h"

using namespace std;

void main() {
	LinkedList ll(123);

	ll.prepend(0);
	ll.append(456);
	ll.set(1, 888);

	ll.printList();
	//cout << ll.get(2)->value;
}