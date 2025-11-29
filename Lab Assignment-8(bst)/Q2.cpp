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
// recursive search:
bool search(Node* root,int val){
    if(root==NULL) return false;
    if(root->data==val){
        return true;
    }
    else if(root->data<val){
        return search(root->right,val);
    }
    else return search(root->left,val);
}
//iterative search:
bool search(Node* root,int val){
    while(root!=NULL){
        if(root->data==val){
            return true;
        }
        else if(val<root->data){
            root = root->left;
        } 
        else {
            root = root->right;
        }
    }
    return false;
}
void max_val(Node* root){
    Node* temp =root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    cout<<"Max value is: "<<temp->data<<endl;
}
void min_val(Node* root){
    Node* temp =root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    cout<<"Min value is: "<<temp->data<<endl;
}
int inorderSuccessor(Node* root, Node* target) {
    if (target->right != NULL){
        Node* successor = target->right;
        while(successor->left!=NULL) successor = successor->left;
        return successor->data;
    }
        

    Node* successor = NULL;
    while (root != NULL) {
        if (target->data < root->data) {
            successor = root; 
            root = root->left;
        } else if (target->data > root->data) {
            root = root->right;
        } else
            break;
    }
    if(successor!=NULL){
    return successor->data;
}
}
int inorderPredecessor(Node* root, Node* target) {
    if (target->left != NULL){
        Node* predecessor = target->left;
        while(predecessor->right!=NULL) predecessor = predecessor->right;
        return predecessor->data;
    }
        

    Node* predecessor = NULL;
    while (root != NULL) {
        if (target->data > root->data) {
            predecessor = root;  
            root = root->right;
        } else if (target->data < root->data) {
            root = root->left;
        } else
            break;
    }
    if(predecessor!=NULL){
    return predecessor->data;
    }
}
int main(){
    Node* root = NULL;
    root = insert(root,10);
    insert(root,6);
    insert(root,12);
    insert(root,7);
    insert(root,9);
    cout<<search(root,12)<<endl;
    max_val(root);
    min_val(root);
    cout<<inorderSuccessor(root,root->left)<<endl;
    cout<<inorderPredecessor(root,root->left->right)<<endl;
}