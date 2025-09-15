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

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        int count = size;
        int i = front;
        while (count--) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << "\n";
    }
};

void interleaveQueue(Queue &q) {
    int n = q.getSize();
    if (n % 2 != 0) {
        cout << "Queue size should be even for interleaving\n";
        return;
    }

    int half = n / 2;
    int *firstHalf = new int[half];
    int *secondHalf = new int[half];

    // Dequeue first half
    for (int i = 0; i < half; i++) {
        firstHalf[i] = q.dequeue();
    }
    // Dequeue second half
    for (int i = 0; i < half; i++) {
        secondHalf[i] = q.dequeue();
    }

    // Enqueue interleaved elements
    for (int i = 0; i < half; i++) {
        q.enqueue(firstHalf[i]);
        q.enqueue(secondHalf[i]);
    }

    delete[] firstHalf;
    delete[] secondHalf;
}

int main() {
    Queue q(10);
    // Sample input: 4 7 11 20 5 9
    q.enqueue(4);
    q.enqueue(7);
    q.enqueue(11);
    q.enqueue(20);
    q.enqueue(5);
    q.enqueue(9);

    cout << "Original queue: ";
    q.display();

    interleaveQueue(q);

    cout << "Interleaved queue: ";
    q.display();

    return 0;
}
