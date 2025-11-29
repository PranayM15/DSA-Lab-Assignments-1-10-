// queue implementation:
#include<iostream>
using namespace std;

class Queue {
    int *a, n, front, rear;
public:
    Queue(int s){
        n=s;
        a=new int[n];
        front=rear=-1;
    }
    bool isEmpty(){ return front==-1; }
    bool isFull(){ return rear==n-1; }
    void enqueue(int x){
        if(isFull()){ cout<<"Queue Full\n"; return; }
        if(front==-1) front=0;
        a[++rear]=x;
    }
    int dequeue(){
        if(isEmpty()){ cout<<"Queue Empty\n"; return -1; }
        int x=a[front];
        if(front==rear) front=rear=-1;
        else front++;
        return x;
    }
    int peek(){
        if(isEmpty()) return -1;
        return a[front];
    }
    void display(){
        if(isEmpty()){ cout<<"Queue Empty\n"; return; }
        for(int i=front;i<=rear;i++) cout<<a[i]<<" ";
        cout<<"\n";
    }
};

int main(){
    int n;
    cout<<"Enter size of queue: ";
    cin>>n;
    Queue q(n);

    while(true){
        cout<<"|1 Enqueue|2 Dequeue|3 isEmpty|4 isFull|5 Display|6 Peek|7 Exit|\n";
        int c;
        cin>>c;
        if(c==1){
            int x; cin>>x;
            q.enqueue(x);
        }
        else if(c==2){
            cout<<q.dequeue()<<endl;
        }
        else if(c==3){
            cout<<q.isEmpty()<<endl;
        }
        else if(c==4){
            cout<<q.isFull()<<endl;
        }
        else if(c==5){
            q.display();
        }
        else if(c==6){
            cout<<q.peek()<<endl;
        }
        else break;
    }
}
