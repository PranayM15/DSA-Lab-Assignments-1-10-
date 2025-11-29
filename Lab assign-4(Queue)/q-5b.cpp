// stack using queue:
#include<iostream>
#include<queue>
using namespace std;

class Stack{
    queue<int> q;
public:
    void push(int x){
        q.push(x);
        int k=q.size()-1;
        while(k--){
            q.push(q.front());
            q.pop();
        }
    }
    int pop(){
        if(q.empty()) return -1;
        int x=q.front();
        q.pop();
        return x;
    }
};

int main(){
    Stack s;
    int c;
    while(true){
        cin>>c;
        if(c==1){
            int x; cin>>x;
            s.push(x);
        }else if(c==2){
            cout<<s.pop()<<"\n";
        }
        else{
            break;
        }
    }
}
