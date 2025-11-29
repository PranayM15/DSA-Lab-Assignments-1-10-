//Write a program to check if a doubly linked list of characters is palindrome or not:
// doubly linked list:
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    char data;
    Node* next;
    Node* prev;
    Node(int val){
        data = val;
        next = NULL;
        prev=NULL;
    }

};

class DLL{

    Node* head;
    Node* tail;
    public:
    DLL(){
        head = NULL;
        tail = NULL;
    }

    void insert_head(int val){
        Node* newnode = new Node(val);
        if(head==NULL and tail==NULL) {
            head=tail=newnode;
        }
        else{
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
        }
        
    }
    void insert_tail(int val){
        Node* newnode = new Node(val);
        if(head==NULL and tail==NULL) {
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
    }
    bool check_palin(){
        Node* temp1=head;
        Node* temp2=tail;
        if (!head) return true;
        while(temp1 && temp2 && temp1 != temp2 && temp1->prev != temp2){
            if(temp1->data!=temp2->data){
                return false;
            }
            temp1=temp1->next;
            temp2=temp2->prev;
        }
        return true;
    }
    void print(){
        if(head==NULL) return;
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"  ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    DLL dl;
    dl.insert_head('a');
    dl.insert_tail('c');
    dl.insert_tail('f');
    dl.insert_tail('g');
    dl.insert_tail('c');
    dl.insert_tail('a');
    dl.insert_tail('a');
    dl.print();
    cout<<dl.check_palin()<<endl;
}