
#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* reverseLinkedList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

void printLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    
    std::cout << "Arin Zingade" << std::endl;
    std::cout << "0801IT221035" << std::endl;

    Node* head = nullptr;
    Node* second = nullptr;
    Node* third = nullptr;

    head = new Node;
    second = new Node;
    third = new Node;

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = nullptr;

    std::cout << "Original Linked List: ";
    printLinkedList(head);

    head = reverseLinkedList(head);

    std::cout << "Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}
