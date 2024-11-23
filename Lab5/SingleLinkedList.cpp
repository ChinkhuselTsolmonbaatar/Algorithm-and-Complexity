#include <iostream>
template <typename T>
class Node {
public:
	T data;
	Node* next;
	
};
template <typename T>
class LinkedList {
private:
	Node<T>* head;
public:
	LinkedList() {
		head = nullptr;
	}
	void addAtFront(T value) {
		Node <T>* newNode = new Node<T>;
		newNode->data = value;
		newNode->next = head;
		head = newNode;
	}
	void addATEnd(T value) {
		Node <T>* newNode = new Node<T>;
		newNode->data = value;
		newNode->next = nullptr;
		if (head == nullptr)
		{
			head = newNode;
			return;
		}
		Node<T>* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
	void displayList() {
		Node <T>* temp = head;
		while (temp != nullptr)
		{
			std::cout << temp->data <<" ";
			temp = temp->next;
		}
	}
	void removeFirst()
	{
		if (head == nullptr)
			std::cout << "You can't remove element from the list - list is empty";
		Node<T>* temp = head;
		T value = head->data;
		head = head->next;
	}

	void removeLast()
	{
		if (head == nullptr)
		{
			std::cout << "You can't remove element from the list - list is empty";
			
		}
			
		if (head->next == nullptr)
		{
			return removeFirst();
		}
		
		Node<T>* temp = head;
		while (temp->next-> next!= nullptr)
		{
			temp = temp->next;
		}
		temp->next = nullptr;
	}




	int ListSize() {
		int count = 0; 
		Node<T>* temp = head; 
		while (temp != nullptr) {
			count++;        
			temp = temp->next; 
		}
	
		return count;
	}


	Node <T>* find(T value) {
		Node<T>* temp = head;
		while (temp != nullptr) {
			if (temp->data == value)
				return temp;
			temp = temp->next;
		}
			return nullptr;
	}
};