// doubly linked list:
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
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
    void insert_pos(int val, int pos){
        Node* newnode = new Node(val);
        if(head==NULL and tail==NULL) {
            head=tail=newnode;
        }
        else if(pos==1) insert_head(val);
        else{
            Node* temp=head;
            for(int i=1; i<pos-1; i++){
                temp=temp->next;
            }
            newnode->next=temp->next;
            temp->next->prev=newnode;
            temp->next=newnode;
            newnode->prev=temp;
        }
        
    }
 
    int size_ll(){
        int cnt=1;
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
            cnt++;
        }
        return cnt;
    }

    
};

int main(){
    DLL dl;
    dl.insert_head(1);
    dl.insert_head(2);
    dl.insert_head(3);
    dl.insert_tail(4);
    dl.insert_tail(5);
    dl.insert_pos(6,4);
    dl.insert_pos(7,3);
    cout<<dl.size_ll()<<endl;

}