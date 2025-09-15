#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int val) : data(val), next(NULL) {}
};

class SinglyLinkedList {
    Node *head;

public:
    SinglyLinkedList() : head(NULL) {}

    // Insertion at the beginning
    void insertAtBeginning(int val) {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        cout << val << " inserted at the beginning\n";
    }

    // Insertion at the end
    void insertAtEnd(int val) {
        Node *newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << val << " inserted at the end\n";
    }

    // Insertion before or after a node having a given value
    void insertBeforeAfter(int target, int val, bool insertBefore) {
        if (!head) {
            cout << "List is empty\n";
            return;
        }

        // If inserting before the head node
        if (insertBefore && head->data == target) {
            insertAtBeginning(val);
            return;
        }

        Node *prev = NULL;
        Node *curr = head;
        while (curr && curr->data != target) {
            prev = curr;
            curr = curr->next;
        }

        if (!curr) {
            cout << "Node with value " << target << " not found\n";
            return;
        }

        Node *newNode = new Node(val);
        if (insertBefore) {
            // Insert before curr
            prev->next = newNode;
            newNode->next = curr;
            cout << val << " inserted before " << target << "\n";
        } else {
            // Insert after curr
            newNode->next = curr->next;
            curr->next = newNode;
            cout << val << " inserted after " << target << "\n";
        }
    }

    // Deletion from beginning
    void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        cout << temp->data << " deleted from the beginning\n";
        delete temp;
    }

    // Deletion from end
    void deleteFromEnd() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }

        if (!head->next) {
            cout << head->data << " deleted from the end\n";
            delete head;
            head = NULL;
            return;
        }

        Node *temp = head;
        Node *prev = NULL;
        while (temp->next) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        cout << temp->data << " deleted from the end\n";
        delete temp;
    }

    // Deletion of a specific node by value
    void deleteNode(int val) {
        if (!head) {
            cout << "List is empty\n";
            return;
        }

        if (head->data == val) {
            deleteFromBeginning();
            return;
        }

        Node *prev = NULL;
        Node *curr = head;
        while (curr && curr->data != val) {
            prev = curr;
            curr = curr->next;
        }

        if (!curr) {
            cout << "Node with value " << val << " not found\n";
            return;
        }

        prev->next = curr->next;
        cout << curr->data << " deleted from the list\n";
        delete curr;
    }

    // Search for a node and display its position (1-based index)
    void searchNode(int val) {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node *temp = head;
        int pos = 1;
        while (temp && temp->data != val) {
            temp = temp->next;
            pos++;
        }
        if (!temp) {
            cout << "Node with value " << val << " not found\n";
            return;
        }
        cout << "Node with value " << val << " found at position " << pos << "\n";
    }

    // Display all node values
    void displayList() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        cout << "List elements: ";
        Node *temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    SinglyLinkedList list;
    int choice, val, target;
    char beforeAfter;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert before/after specific value\n";
        cout << "4. Delete from beginning\n";
        cout << "5. Delete from end\n";
        cout << "6. Delete specific node\n";
        cout << "7. Search for node\n";
        cout << "8. Display list\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> val;
                list.insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> val;
                list.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> val;
                cout << "Enter target node value: ";
                cin >> target;
                cout << "Insert before or after target node? (b/a): ";
                cin >> beforeAfter;
                if (beforeAfter == 'b' || beforeAfter == 'B') {
                    list.insertBeforeAfter(target, val, true);
                } else if (beforeAfter == 'a' || beforeAfter == 'A') {
                    list.insertBeforeAfter(target, val, false);
                } else {
                    cout << "Invalid choice, please enter 'b' or 'a'\n";
                }
                break;
            case 4:
                list.deleteFromBeginning();
                break;
            case 5:
                list.deleteFromEnd();
                break;
            case 6:
                cout << "Enter value of node to delete: ";
                cin >> val;
                list.deleteNode(val);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> val;
                list.searchNode(val);
                break;
            case 8:
                list.displayList();
                break;
            case 9:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
