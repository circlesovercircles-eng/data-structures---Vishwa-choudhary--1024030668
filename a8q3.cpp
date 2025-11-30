#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node* bstInsert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data)
        root->left = bstInsert(root->left, key);
    else if (key > root->data)
        root->right = bstInsert(root->right, key);
    return root;
}

Node* bstDelete(Node* root, int key) {
    if (!root) return root;
    if (key < root->data)
        root->left = bstDelete(root->left, key);
    else if (key > root->data)
        root->right = bstDelete(root->right, key);
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = root->right;
        while (temp->left) temp = temp->left;
        root->data = temp->data;
        root->right = bstDelete(root->right, temp->data);
    }
    return root;
}

int maxDepth(Node* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    if (!root->left) return 1 + minDepth(root->right);
    if (!root->right) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

int main() {
    Node* root = NULL;
    root = bstInsert(root, 50);
    root = bstInsert(root, 30); root = bstInsert(root, 70);
    root = bstInsert(root, 20); root = bstInsert(root, 40);
    root = bstInsert(root, 60); root = bstInsert(root, 80);
    
    cout << "BST Inorder (before delete): ";
    inOrder(root); cout << endl;
    cout << "Max Depth: " << maxDepth(root) << endl;
    cout << "Min Depth: " << minDepth(root) << endl;
    
    root = bstDelete(root, 30);
    cout << "\nAfter deleting 30 - Inorder: ";
    inOrder(root); cout << endl;
    
    return 0;
}
