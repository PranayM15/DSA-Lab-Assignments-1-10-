#include<iostream>
using namespace std;
struct term{int r,c,v;};
int main(){
 int t1,t2;
 cout<<"Enter terms in A: ";cin>>t1;
 term a[20]; cout<<"Enter row col val:"<<endl;
 for(int i=0;i<t1;i++) cin>>a[i].r>>a[i].c>>a[i].v;

 cout<<"Enter terms in B: ";cin>>t2;
 term b[20]; cout<<"Enter row col val:"<<endl;
 for(int i=0;i<t2;i++) {
    cin>>b[i].r>>b[i].c>>b[i].v;
 }
 term c[40]; int k=0;
 for(int i=0;i<t1;i++){ c[k++]=a[i];
 }
 for(int i=0;i<t2;i++) {c[k++]=b[i];
 }

 cout<<"Result (not merged duplicate terms for simplicity):"<<endl;
 for(int i=0;i<k;i++){ cout<<c[i].r<<" "<<c[i].c<<" "<<c[i].v<<endl;
 }
}
