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

void preorder(Node * root){
    if (root != NULL){
        cout << root->data << ",";
        preorder(root->left);
        preorder(root->right);
    }
}


void inorder(Node * root){
    if (root != NULL){

        inorder(root->left);
        cout << root->data << ",";
        inorder(root->right);
    }
}
void postorder(Node * root){
    if (root != NULL){

        postorder(root->left);
        postorder(root->right);cout << root->data << ",";
    }
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
    cout << "preorder : " ;preorder(root);cout<<endl;
    cout << "Inorder : " ;inorder(root);cout<<endl;
    cout << "postorder : ";postorder(root);cout<<endl;
    return 0; 
}