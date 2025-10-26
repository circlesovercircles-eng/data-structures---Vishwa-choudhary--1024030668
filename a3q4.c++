// Write a program to convert an Infix expression into a Postfix expression.
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
int main() {
    char exp[SIZE] = "a+b*c";
    // convert infix to postfix using stack
    for (int i = 0; exp[i] != '\0'; i++) {
        if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z')) {
            cout << exp[i];
        } else if (exp[i] == '(') {
            push(exp[i]);
        } else if (exp[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                peek();
                pop();
            }
            pop(); 
        } else {
            while (top != -1 && ((exp[i] == '+' || exp[i] == '-') && (stack[top] == '+' || stack[top] == '-' || stack[top] == '*' || stack[top] == '/' || stack[top] == '^')) ||
                   ((exp[i] == '*' || exp[i] == '/') && (stack[top] == '*' || stack[top] == '/' || stack[top] == '^')) ||
                   ((exp[i] == '^') && (stack[top] == '^'))) {
                peek();
                pop();
            }
            push(exp[i]);
        }
    }
    while (top != -1) {
        peek();     
        pop();
    }
    cout << endl;
    return 0;           

}