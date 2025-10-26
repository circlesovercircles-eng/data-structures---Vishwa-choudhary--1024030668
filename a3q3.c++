// 3. Write a program that checks if an expression has balanced parentheses.

#include <iostream>
using namespace std;
// vishwa choudhary 1024030668

#define SIZE 100

char stack[SIZE];
char top = -1;

void push(char value) {
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
        cout << stack[top];
        return 0;
    } else {
        cout << "Stack is empty" << endl;
        return -1; // Return an invalid value
    }
}

int main(){
    string exp;
    cout << "Enter an expression: ";
    cin >> exp;

    for (char ch : exp) {
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) {
                cout << "Unbalanced parentheses" << endl;
                return 0;
            }
            char topChar = stack[top];
            if ((ch == ')' && topChar == '(') ||
                (ch == '}' && topChar == '{') ||
                (ch == ']' && topChar == '[')) {
                pop();
            } else {
                cout << "Unbalanced parentheses" << endl;
                return 0;
            }
        }
    }

    if (top == -1) {
        cout << "Balanced parentheses" << endl;
    } else {
        cout << "Unbalanced parentheses" << endl;
    }
    return 0;
}