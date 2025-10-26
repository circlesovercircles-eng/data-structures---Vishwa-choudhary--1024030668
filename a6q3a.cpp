#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    DoublyLinkedList() { head = nullptr; }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    int size() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    DoublyLinkedList dll;
    int arr[] = {10, 20, 30, 40, 50};
    for (int val : arr)
        dll.insertAtEnd(val);

    cout << "Size of Doubly Linked List: " << dll.size() << endl;
    return 0;
}