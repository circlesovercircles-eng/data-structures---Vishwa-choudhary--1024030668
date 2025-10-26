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

    int size() {
        if (!head) return 0;
        int count = 1;
        CNode* temp = head->next;
        while (temp != head) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    CircularLinkedList cll;
    int arr[] = {10, 20, 30, 40, 50};
    for (int val : arr)
        cll.insertEnd(val);

    cout << "Size of Circular Linked List: " << cll.size() << endl;
    return 0;
}