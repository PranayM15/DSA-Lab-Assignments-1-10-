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
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            Node* mini = root->right;
            while (mini->left != NULL)
                mini = mini->left;
            root->data = mini->data;

            root->right = deleteNode(root->right, mini->data);
        }
    }
    return root;
}
int maxDepth(Node* root) {
    if (root == NULL) return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return 1 + max(leftDepth, rightDepth);
}
int minDepth(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL)
        return 1 + minDepth(root->right);
    if (root->right == NULL)
        return 1 + minDepth(root->left);
    
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

int main(){
    Node* root = NULL;
    root = insert(root,10);
    insert(root,6);
    insert(root,12);
    insert(root,7);
    insert(root,9);
    cout<<"Max depth: "<<maxDepth(root)<<endl;
    cout<<"Min depth: "<<minDepth(root)<<endl;
    deleteNode(root,9);
    
    
}