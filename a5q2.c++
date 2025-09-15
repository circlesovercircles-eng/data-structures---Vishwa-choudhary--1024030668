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
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << "->";
            temp = temp->next;
        }
        cout << "\n";
    }

    int countOccurrences(int key) {
        int count = 0;
        Node* temp = head;
        while (temp) {
            if (temp->data == key)
                count++;
            temp = temp->next;
        }
        return count;
    }

    void deleteAllOccurrences(int key) {
        // Delete from the beginning if head contains key
        while (head && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        if (!head) return;

        Node* curr = head;
        while (curr->next) {
            if (curr->next->data == key) {
                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                curr = curr->next;
            }
        }
    }
};

int main() {
    SinglyLinkedList list;
    // Input Linked List: 1->2->1->2->1->3->1
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(1);
    list.insertAtEnd(3);
    list.insertAtEnd(1);

    int key = 1;

    cout << "Original Linked List: ";
    list.displayList();

    int count = list.countOccurrences(key);
    cout << "Count of " << key << ": " << count << "\n";

    list.deleteAllOccurrences(key);

    cout << "Updated Linked List: ";
    list.displayList();

    return 0;
}
