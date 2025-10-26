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
    DoublyLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        if (head != nullptr) head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAfterNode(int target, int val) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == target) {
                Node* newNode = new Node(val);
                newNode->next = temp->next;
                newNode->prev = temp;
                if (temp->next != nullptr)
                    temp->next->prev = newNode;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }
        cout << "Node " << target << " not found!" << endl;
    }

    void deleteNode(int key) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key) {
                if (temp->prev != nullptr)
                    temp->prev->next = temp->next;
                else
                    head = temp->next;
                if (temp->next != nullptr)
                    temp->next->prev = temp->prev;
                delete temp;
                return;
            }
            temp = temp->next;
        }
        cout << "Node " << key << " not found!" << endl;
    }

    void searchNode(int key) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key) {
                cout << "Node " << key << " found!" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Node " << key << " not found!" << endl;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << " <-> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    int choice, data, target;

    while (true) {
        cout << "\nDoubly Linked List Operations\n";
        cout << "1. Insert at beginning\n2. Insert at end\n3. Insert after node\n";
        cout << "4. Delete node\n5. Search node\n6. Display\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            dll.insertAtBeginning(data);
            break;
        case 2:
            cout << "Enter data: ";
            cin >> data;
            dll.insertAtEnd(data);
            break;
        case 3:
            cout << "Enter target node: ";
            cin >> target;
            cout << "Enter data: ";
            cin >> data;
            dll.insertAfterNode(target, data);
            break;
        case 4:
            cout << "Enter node to delete: ";
            cin >> data;
            dll.deleteNode(data);
            break;
        case 5:
            cout << "Enter node to search: ";
            cin >> data;
            dll.searchNode(data);
            break;
        case 6:
            dll.display();
            break;
        case 7:
            exit(0);
        default:
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}