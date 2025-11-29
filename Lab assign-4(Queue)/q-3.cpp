// interleave:
#include<iostream>
#include<queue>
using namespace std;

queue<int> interleave(queue<int> q){
        int n=q.size();
        queue<int> f,ans;
        for(int i=0;i<n/2;i++){
            f.push(q.front());
            q.pop();
        }
        
        while(!f.empty()){
            ans.push(f.front());
            f.pop();
            ans.push(q.front());
            q.pop();
        }
        return ans;
    }

int main(){
    queue<int> q;
    int x;
    cout<<"Enter size of queue: ";
    cin>>x;
    cout<<"Enter "<<x<<" elements: ";
    for(int i=0; i<x; i++){
        int y;
        cin>>y;
        q.push(y);
    }
    queue<int> r= interleave(q);
    while(!r.empty()){
        cout<<r.front()<<"  ";
        r.pop();
    }
}
