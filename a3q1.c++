#include <iostream>
using namespace std;
// vishwa choudhary 1024030668

#define SIZE 7

int stack[SIZE];
int top = -1;

void push(int value) {
    if (top < SIZE - 1) {
        stack[++top] = value;
    } else {
        cout << "Stack overflow" << endl;
    }
}
void pop() {
    if (top >= 0) {
        top--;
    } else {
        cout << "Stack underflow" << endl;
    }
}
void isEmpty() {
    if (top == -1) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }
}
void isFull() {
    if (top == SIZE - 1) {
        cout << "Stack is full" << endl;
    } else {
        cout << "Stack is not full" << endl;
    }
}
void display() {
    if (top >= 0) {
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << stack[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Stack is empty" << endl;
    }
}
int peek() {
    if (top >= 0) {
        return stack[top];
    } else {
        cout << "Stack is empty" << endl;
        return -1; // Return an invalid value
    }
}

int main() {
    int choice, value;
    while (true) {
        cout << "1. Push\n2. Pop\n3. Check if empty\n4. Check if full\n5. Display\n6. Peek\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                isEmpty();
                break;
            case 4:
                isFull();
                break;
            case 5:
                display();
                break;
            case 6:
                cout << "Top element: " << peek() << endl;
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
    return 0;
}