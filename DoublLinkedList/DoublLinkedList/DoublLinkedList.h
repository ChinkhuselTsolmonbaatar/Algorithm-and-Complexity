#include <iostream>
#include <stdexcept>
template <typename T>
class Node {
public:
	T data;
	Node* next;
	Node* previous;
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
		newNode->previous = nullptr;
		if (head != nullptr) {
			head->previous = newNode;   
		}
		head = newNode;
	}
	void addAtEnd(T value) {
		Node<T>* newNode = new Node<T>; // Create a new node
		newNode->data = value;          // Set the data value
		newNode->next = nullptr;        // New node will be the last, so its next is null

		if (head == nullptr) {
			// If the list is empty, initialize the head
			newNode->previous = nullptr; // No previous node
			head = newNode;
			return;
		}

		Node<T>* temp = head;
		while (temp->next != nullptr) {
			// Traverse to the last node
			temp = temp->next;
		}

		temp->next = newNode;       // Link the last node to the new node
		newNode->previous = temp;   // Set the previous pointer of the new node
	}
	void displayList() {
		Node <T>* temp = head;
		while (temp != nullptr)
		{
			std::cout << temp->data << " ";
			temp = temp->next;
		}
	}
	void removeFromFront() {
		if (head == nullptr) {
			// The list is empty, nothing to remove
			std::cout << "List is empty. Nothing to remove." << std::endl;
			return;
		}

		Node<T>* temp = head;     // Temporary pointer to the current head
		head = head->next;        // Move the head to the next node

		if (head != nullptr) {
			head->previous = nullptr; // Set the new head's previous to nullptr
		}

		delete temp;              // Free the memory of the removed node
	}

	void removeFromEnd()
	{
		if (head == nullptr)
		{
			std::cout << "You can't remove element from the list - list is empty";

		}

		if (head->next == nullptr)
		{
			return removeFromFront();
		}
		Node<T>* temp = head;
		while (temp->next->next != nullptr)
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
};