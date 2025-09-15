#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int front, rear, size, capacity;

public:
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue full\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue empty\n";
            return -1;
        }
        int x = arr[front];
        front = (front + 1) % capacity;
        size--;
        return x;
    }

    int getSize() {
        return size;
    }
};

class StackTwoQueues {
    Queue q1, q2;

public:
    StackTwoQueues(int cap) : q1(cap), q2(cap) {}

    void push(int x) {
        // Move all elements from q1 to q2
        while (!q1.isEmpty()) {
            int val = q1.dequeue();
            q2.enqueue(val);
        }
        // Add new element to q1
        q1.enqueue(x);
        // Move back all elements from q2 to q1
        while (!q2.isEmpty()) {
            int val = q2.dequeue();
            q1.enqueue(val);
        }
    }

    void pop() {
        if (q1.isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        int val = q1.dequeue();
        cout << "Popped: " << val << "\n";
    }
};

int main() {
    StackTwoQueues s(10);

    s.push(10);
    s.push(20);
    s.push(30);

    s.pop(); // Should print 30
    s.pop(); // Should print 20
    s.pop(); // Should print 10
    s.pop(); // Stack is empty

    return 0;
}
