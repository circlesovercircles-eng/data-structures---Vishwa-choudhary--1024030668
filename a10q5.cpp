#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

bool hasCycle(Node* head) {
    unordered_set<Node*> seen;
    Node* curr = head;
    
    while (curr) {
        if (seen.count(curr)) return true;
        seen.insert(curr);
        curr = curr->next;
    }
    return false;
}

int main() {
    // Create: 1→2→3→4→2 (cycle)
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next; // Cycle
    
    cout << "Input: 1→2→3→4→2 (cycle)" << endl;
    cout << "Output: " << (hasCycle(head) ? "true" : "false") << endl;
    return 0;
}
