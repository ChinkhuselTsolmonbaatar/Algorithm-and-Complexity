#include<stdexcept>
    template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

template <typename T>
class Stack {
    Node<T>* top;
public:
    Stack() {
        top = nullptr;
    }
    void push(T value) {
        top = new Node<T>(value, top);
    }
    T pop() {
        if (top == nullptr) {
            throw std::underflow_error("Stack is empty - is not possible to remove element");
        }
        T val = top->data;
        Node<T>* oldtop = top;
        top = top->next;
        delete oldtop;
        return val;
    }
    bool isEmpty() {
        if (top == nullptr) {
            return true;
        }
        else
            return false;
    }
    int getSize() {
        int count = 0;
        Node<T>* temp = top;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        return count;
    }
};