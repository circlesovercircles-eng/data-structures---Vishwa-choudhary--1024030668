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
        cout << "\n";
    }

    int findMiddle() {
        if (!head) {
            cout << "List is empty\n";
            return -1;
        }
        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }
};

int main() {
    SinglyLinkedList list;
    // Input: 1->2->3->4->5
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);

    cout << "Linked List: ";
    list.displayList();

    int middle = list.findMiddle();
    if (middle != -1)
        cout << "Middle element: " << middle << "\n";

    return 0;
}
