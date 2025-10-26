#include <iostream>
#include <cmath>
#include <cctype> 

using namespace std;

#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int value) {
    if (top < SIZE - 1) {
        stack[++top] = value;
    } else {
        cout << "Stack overflow" << endl;
    }
}

int pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        cout << "Stack underflow" << endl;
        return -1; // Indicate error
    }
}

int main() {
    char exp[SIZE] = "23*54*+9-";
    // Evaluate postfix expression using stack
    for (int i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i])) {
            push(exp[i] - '0'); // Convert char to int and push to stack
        } else {
            int val2 = pop(); // Pop top two elements
            int val1 = pop();
            switch (exp[i]) {
                case '+':
                    push(val1 + val2);
                    break;
                case '-':
                    push(val1 - val2);
                    break;
                case '*':
                    push(val1 * val2);
                    break;
                case '/':
                    push(val1 / val2);
                    break;
                case '^':
                    push(pow(val1, val2));
                    break;
            }
        }
    }
    cout << "Result of postfix expression: " << stack[top] << endl; // Final result
    return 0;
}
