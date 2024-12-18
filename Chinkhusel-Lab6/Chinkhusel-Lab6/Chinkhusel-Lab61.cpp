#include "Chinkhusel-Lab6.cpp"
#include<iostream>
int main() {
	Stack<int> s1;
	s1.push(5);
	s1.push(10);
	s1.push(2);
	s1.pop();
	s1.push(1);
	s1.push(3);
	// i pushed 5 elements and popped 1 element, which is size must be 4
	
	std::cout << "Is this list empty?: ";
	std::cout << s1.isEmpty() << std::endl;
	std::cout << "Is this list empty?: ";

	Stack<int> s2;
	std::cout << s2.isEmpty() << std::endl;
	// an empty list

	std::cout << "Size of list is " << s1.getSize() << std::endl;
}