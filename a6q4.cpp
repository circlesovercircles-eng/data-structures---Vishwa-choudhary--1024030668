#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* prev;
    Node* next;
    Node(char val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    DoublyLinkedList() { head = nullptr; }

    void insertAtEnd(char val) {
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

    bool isPalindrome() {
        if (!head) return true;
        Node* left = head;
        Node* right = head;
        while (right->next != nullptr)  // move right to last node
            right = right->next;

        while (left != right && left->prev != right) {
            if (left->data != right->data)
                return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }
};

int main() {
    DoublyLinkedList dll;
    string str = "radar";
    for (char ch : str)
        dll.insertAtEnd(ch);

    if (dll.isPalindrome())
        cout << "The doubly linked list is a palindrome." << endl;
    else
        cout << "The doubly linked list is not a palindrome." << endl;

    return 0;
}