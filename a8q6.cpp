#include <iostream>
using namespace std;

class PriorityQueue {
private:
    int* heap;
    int capacity, size;
    
public:
    PriorityQueue(int cap) {
        capacity = cap;
        size = 0;
        heap = new int[cap];
    }
    
    ~PriorityQueue() { delete[] heap; }
    
    void insert(int key) {
        if (size == capacity) {
            cout << "Queue is full!" << endl;
            return;
        }
        heap[size] = key;
        int i = size++;
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[parent] < heap[i]) {
                swap(heap[parent], heap[i]);
                i = parent;
            } else break;
        }
    }
    
    int extractMax() {
        if (size <= 0) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int max = heap[0];
        heap[0] = heap[--size];
        if (size > 0) heapify(0);
        return max;
    }
    
    void printQueue() {
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
    
    bool isEmpty() { return size == 0; }
    
private:
    void heapify(int i) {
        int largest = i;
        int left = 2 * i + 1, right = 2 * i + 2;
        
        if (left < size && heap[left] > heap[largest])
            largest = left;
        if (right < size && heap[right] > heap[largest])
            largest = right;
            
        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }
};

int main() {
    PriorityQueue pq(10);
    
    cout << "Inserting elements: 10, 30, 20, 5, 40" << endl;
    pq.insert(10); pq.insert(30); pq.insert(20);
    pq.insert(5); pq.insert(40);
    
    cout << "Priority Queue: ";
    pq.printQueue();
    
    cout << "Extract Max: " << pq.extractMax() << endl;
    cout << "Extract Max: " << pq.extractMax() << endl;
    
    cout << "Remaining Queue: ";
    pq.printQueue();
    
    return 0;
}
