#include "SingleLinkedList.cpp"
#include <string>
int main()
{
	LinkedList<int> l1;
	LinkedList<std::string> l2;
	l1.addAtFront(10);
	l1.addAtFront(20); l1.addAtFront(40); l1.addAtFront(50); l1.addAtFront(60);
	l2.addAtFront("Winter");
	l2.addAtFront("Summer");
	l1.addATEnd(30);
	l2.addATEnd("Spring");
	l1.removeFirst();
	std::cout << "Size of LinkedList = "<< l1.ListSize() << std::endl;
	l1.displayList();
	std::cout << std::endl;
	l2.removeLast();
	std::cout << "Size of LinkedList = " << l2.ListSize() << std::endl;
	l2.displayList();
	std::cout  << std::endl;
	std::cout << "Pointer of this value is " << l1.find(50) << std::endl;

	std::cout << std::endl;
	std::cout << "Pointer of this value is " << l1.find(100) << std::endl;

	std::cout << std::endl;
	std::cout << "Pointer of this value is " << l2.find("Summer") << std::endl;
}