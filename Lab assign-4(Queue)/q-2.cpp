// circular queue:
#include<iostream>
using namespace std;

class Cir_Queue {
    int *a, n, front, rear;
public:
    Cir_Queue(int s){
        n=s;
        a=new int[n];
        front=rear=-1;
    }
    bool isEmpty(){ return front==-1; }
    bool isFull(){ return (rear+1)%n==front; }
    void enqueue(int x){
        if(isFull()){ cout<<"Queue Full\n"; return; }
        if(front==-1) front=0;
        rear=(rear+1)%n;
        a[rear]=x;
    }
    int dequeue(){
        if(isEmpty()){ cout<<"Queue Empty\n"; return -1; }
        int x=a[front];
        if(front==rear) front=rear=-1;
        else front=(front+1)%n;
        return x;
    }
    int peek(){
        if(isEmpty()) return -1;
        return a[front];
    }
    void display(){
        if(isEmpty()){ cout<<"Queue Empty\n"; return; }
        int i=front;
        while(true){
            cout<<a[i]<<" ";
            if(i==rear) break;
            i=(i+1)%n;
        }
        cout<<"\n";
    }
};

int main(){
    int n;
    cin>>n;
    Cir_Queue q(n);

    while(true){
        cout<<"|1 Enqueue|2 Dequeue|3 isEmpty|4 isFull|5 Display|6 Peek|7 Exit|\n";
        int c;
        cin>>c;
        if(c==1){
            int x; cin>>x;
            q.enqueue(x);
        }
        else if(c==2){
            cout<<q.dequeue()<<"\n";
        }
        else if(c==3){
            cout<<(q.isEmpty()?"Yes\n":"No\n");
        }
        else if(c==4){
            cout<<(q.isFull()?"Yes\n":"No\n");
        }
        else if(c==5){
            q.display();
        }
        else if(c==6){
            cout<<q.peek()<<"\n";
        }
        else break;
    }
}
