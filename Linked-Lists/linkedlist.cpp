/*
Create a linked list data type
*/
#include <iostream>

// make the node structure
template <typename T>
struct Node {
    Node* nextNode;
    T value;
};

// define the functions
template <typename T>
Node<T>* createLinkedList(T* arr, int size);
template <typename T>
void traverseLinkedList(Node<T>* node);
template <typename T>
Node<T>* insertHead(Node<T>* head, T value);
template <typename T>
Node<T>* insertTail(Node<T>* head, T value);

int main() {
    int test[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = 10;

    Node<int>* head = createLinkedList(test, size);
    traverseLinkedList(head);
    std::cout << std::endl;

    head = insertHead(head, -1);
    traverseLinkedList(head);
    std::cout << std::endl;

    insertTail(head, 10);
    traverseLinkedList(head);
    std::cout << std::endl;

    return 0;
}

template <typename T>
// function for creating new obj from array and returning the header
Node<T>* createLinkedList(T* arr, int size) {
    Node<T>* head = new Node<T>();
    Node<T>* current = head;

    for (int i = 0; i < size; i++) {
        current->value = *(arr+i);
        
        if (i == size-1) current->nextNode = nullptr;
        else {
            current->nextNode = new Node<T>();
            current = current->nextNode;
        }
    }

    return head;
}

template <typename T>
// function for traversing linked list
void traverseLinkedList(Node<T>* node) {
    while (node != nullptr) {
        std::cout << node->value << " ";
        node = node->nextNode;
    }
}

template <typename T>
// function to insert at the begining and return new head ptr
Node<T>* insertHead(Node<T>* head, T value) {
    Node<T>* newNode = new Node<T>;
    newNode->value = value;
    newNode->nextNode = head;
    return newNode;
}

template <typename T>
// function to insert at the end and return new tail ptr
Node<T>* insertTail(Node<T>* start, T value) {
    Node<T>* tail = start;

    while (tail->nextNode != nullptr) {
        tail = tail->nextNode;
    }

    tail->nextNode = new Node<T>;
    tail = tail->nextNode;
    tail->value = value;

    return tail;
}