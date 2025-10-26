#include <iostream>
using namespace std;
// vishwa choudhary 1024030668

#define SIZE 15

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
    char word[SIZE] = "DataStructure";
    // reverse the string using stack
    for (int i = 0; word[i] != '\0'; i++) {
        push(word[i]); 
    }
    cout << "Reversed string: ";
    while (top >= 0) {
        peek();
        pop();
    }    
    printf("\n");
}