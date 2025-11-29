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
    void del_head(){
        if(head==NULL and tail==NULL) return;
        else if(head==tail){
            delete head; 
            head=tail=NULL;
        }
        else{
            Node* temp=head;
            tail->next=head->next;
            head=head->next;
            delete temp;
        }
    }
    void del_tail(){
        if(head==NULL and tail==NULL) return;
       else if(head==tail){
            delete head; 
            head=tail=NULL;
        }
        else{
            Node* prev=head;
            while(prev->next!=tail){
                prev=prev->next;
            }
            Node* temp=tail;
            prev->next=tail->next;
            tail=prev;
            delete temp;
        }
    }
    void del_node(int val){
        if(head==NULL and tail==NULL) return;
       else if(head==tail){
            if(head->data==val){
            delete head; 
            head=tail=NULL;
        }
    }
        else{
            Node* prev=head;
            while(prev->next->data!=val){
                prev=prev->next;
            }
            Node* temp=prev->next;
            prev->next=temp->next;
            temp->next=NULL;
            delete temp;

        }
    }
    bool search(int val){
    if(head == NULL) return false;
    Node* temp = head;
    do{
        if(temp->data == val) return true;
        temp = temp->next;
    } while(temp != head);
    return false;
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

    CLL cl;
    cl.insert_head(2);
    cl.insert_head(1);
    cl.insert_head(0);
    cl.insert_tail(3);
    cl.insert_tail(4);
    cl.insert_pos(6,4);
    cl.insert_pos(7,6);
    cl.del_head();
    cl.del_tail();
    cl.del_node(2);
    cout<<cl.search(7)<<endl;
    cl.print();
    cout<<cl.size_ll();

}