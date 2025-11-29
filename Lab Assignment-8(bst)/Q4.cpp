// to check whether the given binary tree is bst or not:

#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root,int val){
    if(root==NULL) return new Node(val);

    if(val<root->data){
        root->left = insert(root->left,val);
    }
    else if(val>root->data){
        root->right = insert(root->right,val);
    }
    return root;
}
bool isBST(Node* root) {
    static Node* prev = NULL;
    if (root == NULL) return true;

    if (!isBST(root->left)) return false;

    if (prev != NULL && root->data <= prev->data)
        return false;

    prev = root;
    return isBST(root->right);
}

int main(){
    Node* root = NULL;
    root = insert(root,10);
    insert(root,6);
    insert(root,12);
    insert(root,7);
    insert(root,9);
    cout<<isBST(root)<<endl;
    
    
}