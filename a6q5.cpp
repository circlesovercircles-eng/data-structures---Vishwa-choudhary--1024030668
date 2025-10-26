#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

bool isCircular(Node* head) {
    if (!head) return true; // empty list can be considered circular
    Node* temp = head->next;
    while (temp != nullptr && temp != head) {
        temp = temp->next;
    }
    return (temp == head);
}

int main() {
    // Example 1: Circular Linked List
    Node* head1 = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);
    head1->next = n2;
    n2->next = n3;
    n3->next = head1;  // makes it circular

    if (isCircular(head1))
        cout << "The linked list is circular." << endl;
    else
        cout << "The linked list is not circular." << endl;

    // Example 2: Non-circular linked list
    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);

    if (isCircular(head2))
        cout << "The linked list is circular." << endl;
    else
        cout << "The linked list is not circular." << endl;

    return 0;
}