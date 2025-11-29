#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }

};

class LL{

    Node* head;
    Node* tail;
    public:
    LL(){
        head = NULL;
        tail = NULL;
    }

    void insert_head(int val){
        Node* newnode = new Node(val);
        if(head==NULL and tail==NULL) {
           head = tail = newnode;
           tail->next=head;

        }
        else{
        newnode->next = head;
        head =  newnode;
        tail->next = head;
        }
    }
    void insert_tail(int val){
        Node* newnode = new Node(val);
        if(head==NULL and tail==NULL) {
           head = tail = newnode;
           tail->next=head;

        }
        else{
        newnode->next = head;
        tail->next=newnode;
        tail=newnode;
        }
    }
    bool check(){
        if(tail->next==NULL) return false;
        return true;
    }
    void print(){
        if(head==NULL) return;
        Node* temp=head;
        do{
            cout<<temp->data<<" --> ";
            temp=temp->next;
        }
        while(temp!=head);
        cout<<head->data<<endl;
    }

};

int main(){

    LL ll;
    ll.insert_head(2);
    ll.insert_head(1);
    ll.insert_head(0);
    ll.insert_tail(3);
    ll.insert_tail(4);
    cout<<ll.check();

}