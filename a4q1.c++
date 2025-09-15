#include <iostream>
#include <cstdlib>  
using namespace std;

class SimpleQueue {
    int *queue;
    int front, rear, size;

public:
    SimpleQueue(int s) {
        size = s;
        queue = new int[size];
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % size;
        queue[rear] = data;
        cout << "Enqueued: " << data << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        int data = queue[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size;
        }
        cout << "Dequeued: " << data << endl;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Front element: " << queue[front] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter size of the queue: ";
    cin >> size;
    SimpleQueue q(size);

    int choice, value;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. isEmpty\n6. isFull\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
        }
        else if (choice == 2) {
            q.dequeue();
        }
        else if (choice == 3) {
            q.peek();
        }
        else if (choice == 4) {
            q.display();
        }
        else if (choice == 5) {
            cout << (q.isEmpty() ? "Queue is empty" : "Queue is not empty") << endl;
        }
        else if (choice == 6) {
            cout << (q.isFull() ? "Queue is full" : "Queue is not full") << endl;
        }
        else if (choice == 7) {
            cout << "Exiting program." << endl;
            exit(0);
        }
        else {
            cout << "Invalid choice, try again." << endl;
        }
    }
    return 0;
}
