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

void inorder(Node* root){
    if (root == nullptr) return;
    inorder(root->left);
    cout<<root->data <<"  ";
    inorder(root->right);
}
void preorder(Node* root) {
    if (root == nullptr) return;
    cout<<root->data <<"  ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data <<"  ";
}


int main(){
    Node* root = NULL;
    root = insert(root,10);
    insert(root,6);
    insert(root,12);
    insert(root,7);
    insert(root,9);
    insert(root,11);
    insert(root,15);
    cout<<"Inorder traversal: ";
    inorder(root);
    cout<<endl;
    cout<<"Pre-rder traversal: ";
    preorder(root);
    cout<<endl;
    cout<<"Post-order traversal: ";
    postorder(root);
    cout<<endl;

}