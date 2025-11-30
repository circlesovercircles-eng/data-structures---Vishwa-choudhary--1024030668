#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

bool isBST(Node* root, int min = INT_MIN, int max = INT_MAX) {
    if (!root) return true;
    if (root->data <= min || root->data >= max) return false;
    return isBST(root->left, min, root->data) && 
           isBST(root->right, root->data, max);
}

void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

int main() {
    // Valid BST
    Node* bst = NULL;
    int bst_arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++) bst = insert(bst, bst_arr[i]);
    
    cout << "Valid BST Inorder: ";
    inOrder(bst); cout << endl;
    cout << "Is BST: " << (isBST(bst) ? "YES" : "NO") << endl;
    
    // Invalid BST (modify to break BST property)
    Node* invalid = NULL;
    int invalid_arr[] = {50, 30, 70, 60, 40, 55, 80}; // 55 > 60 violates
    for (int i = 0; i < 7; i++) invalid = insert(invalid, invalid_arr[i]);
    
    cout << "\nInvalid BST Inorder: ";
    inOrder(invalid); cout << endl;
    cout << "Is BST: " << (isBST(invalid) ? "YES" : "NO") << endl;
    
    return 0;
}
