#include <iostream>
using namespace std;

class CNode {
public:
    int data;
    CNode* next;
    CNode(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
public:
    CNode* head;
    CircularLinkedList() { head = nullptr; }

    void insertEnd(int val) {
        CNode* newNode = new CNode(val);
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }
        CNode* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    void displayWithHeadRepeat() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        CNode* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << endl; // repeat head at end
    }
};

int main() {
    CircularLinkedList cll;
    int arr[] = {20, 100, 40, 80, 60};
    for (int val : arr)
        cll.insertEnd(val);

    cout << "Circular Linked List (head repeated at end):" << endl;
    cll.displayWithHeadRepeat();

    return 0;
}