// circular linked list:
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

class CLL{

    Node* head;
    Node* tail;
    public:
    CLL(){
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
    void insert_pos(int val, int pos){
        Node* newnode = new Node(val);
        if(head==NULL and tail==NULL) {
           head = tail = newnode;
           tail->next=head;

        }
        else{
            if(pos==1) insert_head(val);
            else{
                Node* temp =head;
                for( int i=1; i<pos-1; i++){
                    temp=temp->next;
                }
                newnode->next=temp->next;
                temp->next=newnode;
            }
        }
        
    }

    int size_ll(){
        int cnt=1;
        Node* temp=head;
        while(temp->next!=tail->next){
            temp=temp->next;
            cnt++;
        }
        return cnt;
    }

};

int main(){

    CLL cl;
    cl.insert_head(2);
    cl.insert_head(1);
    cl.insert_head(0);
    cl.insert_tail(3);
    cl.insert_tail(4);
    cl.insert_pos(6,4);
    cl.insert_pos(7,6);
    cout<<cl.size_ll();

}