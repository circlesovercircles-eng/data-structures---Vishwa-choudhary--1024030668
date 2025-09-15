#include <iostream>
using namespace std;

const int MAX = 256; // For all ASCII chars

class CharQueue {
    char *arr;
    int front, rear, size, capacity;

public:
    CharQueue(int cap) {
        capacity = cap;
        arr = new char[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(char x) {
        if (size == capacity) return; // ignore if full
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        size++;
    }

    char dequeue() {
        if (isEmpty()) return '\0';
        char c = arr[front];
        front = (front + 1) % capacity;
        size--;
        return c;
    }

    char getFront() {
        if (isEmpty()) return '\0';
        return arr[front];
    }
};

void firstNonRepeatingChars(char input[], int n) {
    int freq[MAX] = {0};
    CharQueue q(n);

    for (int i = 0; i < n; i++) {
        char ch = input[i];
        freq[(int)ch]++;
        q.enqueue(ch);

        while (!q.isEmpty() && freq[(int)q.getFront()] > 1) {
            q.dequeue();
        }

        if (!q.isEmpty())
            cout << q.getFront() << " ";
        else
            cout << -1 << " ";
    }
    cout << "\n";
}

int main() {
    // Sample input: a a b c
    char input[] = {'a','a','b','c'};
    int n = sizeof(input)/sizeof(input[0]);

    firstNonRepeatingChars(input, n);

    return 0;
}
