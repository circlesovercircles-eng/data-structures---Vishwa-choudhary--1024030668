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
    CircularLinkedList() {
        head = nullptr;
    }

    void insertEnd(int val) {
        CNode* newNode = new CNode(val);
        if (head == nullptr) {
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

    void insertBeginning(int val) {
        CNode* newNode = new CNode(val);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }
        CNode* temp = head;
        while (temp->next != head)
            temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    void insertAfterNode(int target, int val) {
        if (!head) return;
        CNode* temp = head;
        do {
            if (temp->data == target) {
                CNode* newNode = new CNode(val);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node " << target << " not found!" << endl;
    }

    void deleteNode(int key) {
        if (!head) return;
        CNode* curr = head;
        CNode* prev = nullptr;
        do {
            if (curr->data == key) {
                if (prev) {
                    prev->next = curr->next;
                    if (curr == head) head = curr->next;
                } else { // deleting head
                    CNode* last = head;
                    while (last->next != head) last = last->next;
                    if (last == head) head = nullptr;
                    else {
                        last->next = head->next;
                        head = head->next;
                    }
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);
        cout << "Node " << key << " not found!" << endl;
    }

    void searchNode(int key) {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        CNode* temp = head;
        do {
            if (temp->data == key) {
                cout << "Node " << key << " found!" << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node " << key << " not found!" << endl;
    }

    void display() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        CNode* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << endl; // repeat head at end
    }
};

int main() {
    CircularLinkedList cll;
    int choice, data, target;

    while (true) {
        cout << "\nCircular Linked List Operations\n";
        cout << "1. Insert at beginning\n2. Insert at end\n3. Insert after node\n";
        cout << "4. Delete node\n5. Search node\n6. Display\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            cll.insertBeginning(data);
            break;
        case 2:
            cout << "Enter data: ";
            cin >> data;
            cll.insertEnd(data);
            break;
        case 3:
            cout << "Enter target node: ";
            cin >> target;
            cout << "Enter data: ";
            cin >> data;
            cll.insertAfterNode(target, data);
            break;
        case 4:
            cout << "Enter node to delete: ";
            cin >> data;
            cll.deleteNode(data);
            break;
        case 5:
            cout << "Enter node to search: ";
            cin >> data;
            cll.searchNode(data);
            break;
        case 6:
            cll.display();
            break;
        case 7:
            exit(0);
        default:
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
