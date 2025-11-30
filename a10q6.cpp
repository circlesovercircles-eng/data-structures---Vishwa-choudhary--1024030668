#include <iostream>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

bool hasDuplicate(TreeNode* root, unordered_set<int>& seen) {
    if (!root) return false;
    
    if (seen.count(root->val)) return true;
    seen.insert(root->val);
    
    return hasDuplicate(root->left, seen) || hasDuplicate(root->right, seen);
}

bool hasDuplicateValues(TreeNode* root) {
    unordered_set<int> seen;
    return hasDuplicate(root, seen);
}

int main() {
    // Tree with duplicate 5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5); // Duplicate
    
    cout << "Binary Tree with duplicate 5" << endl;
    cout << "Duplicates Found: " << (hasDuplicateValues(root) ? "YES" : "NO") << endl;
    return 0;
}
