#include "DoublLinkedList.h"
#include <string>
int main()
{
	LinkedList<int> l1;
	LinkedList<std::string> l2;
	l1.addAtFront(10);
	l1.addAtFront(20); l1.addAtFront(40); l1.addAtFront(50); l1.addAtFront(60);
	l2.addAtFront("Winter");
	l2.addAtFront("Summer");
	l2.addAtFront("Autumn");

	l1.addAtEnd(30);
	l2.addAtEnd("Spring");
	l1.removeFromFront();
	std::cout << "Size of LinkedList = " << l1.ListSize() << std::endl;
	l1.displayList();
	std::cout << std::endl;
	l2.removeFromEnd();
	std::cout << "Size of LinkedList = " << l2.ListSize() << std::endl;
	l2.displayList();

	std::cout << std::endl;
}