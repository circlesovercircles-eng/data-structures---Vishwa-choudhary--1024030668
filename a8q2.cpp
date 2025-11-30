#include <iostream>
using namespace std;
class Node
{   public:
    int data;
    Node * left;
    Node * right;
    Node(): data(0),left(NULL),right(NULL){};
    Node(int d = 0) : data(d) , left(NULL) , right(NULL) {};
};
// 1
Node * BSTsearch1(Node * root , int key){
    if (root == NULL || root->data == key) return root;
    else{
        if (root->data < key){
            return BSTsearch1(root->right, key);
        }
        else{
            return BSTsearch1(root->left,key);
        }
    }
}
void  BSTsearch2(Node * root , int key){

    while (root !=NULL && root->data !=key){
        if (key < root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    if (root == NULL){
        cout << "the Key " << key << " is not present in the BST tree." << endl;
    }
    else{
        cout << "the Key "<< key << " is present in the BST tree by loops." << endl;
    }
}
// 2
Node * Max(Node * root){
    while (root->right != NULL){
        root = root->right;
    }
    //cout << "maximuim element "<<root->data<<endl;
    return root;
}

// 3

Node * Min(Node * root){
    while (root->left != NULL){
        root = root->left;
    }
   // cout << "minimuim element "<<root->data<<endl;
    return root;
}
 // 4
 Node* inorderSuccessor(Node* root, Node* node) {
    if (node->right) return Min(node->right);
    
    Node* succ = NULL;
    Node* ancestor = root;
    while (ancestor != node) {
        if (node->data < ancestor->data) {
            succ = ancestor;
            ancestor = ancestor->left;
        } else {
            ancestor = ancestor->right;
        }
    }
    return succ;
}
// 5
Node* inorderPredecessor(Node* root, Node* node) {
    if (node->left) return Max(node->left);
    
    Node* pred = NULL;
    Node* ancestor = root;
    while (ancestor != node) {
        if (node->data > ancestor->data) {
            pred = ancestor;
            ancestor = ancestor->right;
        } else {
            ancestor = ancestor->left;
        }
    }
    return pred;
}

int main(){
    Node * root = new Node(9);
    root->left = new Node(6);
    root->right = new Node(13);
    root->left->left = new Node(1);
    root->left->right = new Node(7);
    root->right->left = new Node(11);
    root->right->right = new Node(15);
    root->right->left->left = new Node(10);
    cout << "maximuim : " << Max(root)->data<< endl;
    cout << "minimuim : " << Min(root)->data<< endl;
    Node * s = BSTsearch1(root,15);
    if (s !=NULL){
        cout << "the key " << 15 << " is present in the BST tree by recursion" <<  endl;
    }
    else{ 
    cout << "not found"<<endl;}
    BSTsearch2(root,15);
    cout <<"inorder successor : " << inorderSuccessor(root , root->right)->data << endl;
    cout << "inorder predecessor : " << inorderPredecessor(root , root->right)->data<< endl;
    return 0; 
}