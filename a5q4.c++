#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class SinglyLinkedList {
    Node* head;

public:
    SinglyLinkedList() : head(NULL) {}

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void displayList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next)
                cout << "->";
            temp = temp->next;
        }
        cout << "->NULL\n";
    }

    void reverseList() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr) {
            next = curr->next;   // store next
            curr->next = prev;   // reverse current node's pointer
            prev = curr;         // move prev forward
            curr = next;         // move curr forward
        }
        head = prev;
    }
};

int main() {
    SinglyLinkedList list;
    // Input: 1->2->3->4->NULL
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);

    cout << "Original Linked List: ";
    list.displayList();

    list.reverseList();

    cout << "Reversed Linked List: ";
    list.displayList();

    return 0;
}
