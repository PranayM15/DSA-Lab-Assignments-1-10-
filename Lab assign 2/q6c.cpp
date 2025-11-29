#include<iostream>
using namespace std;
struct term{int r,c,v;};
int main(){
 int t1,t2;
 cout<<"Enter terms in A: ";cin>>t1;
 term a[20]; for(int i=0;i<t1;i++) cin>>a[i].r>>a[i].c>>a[i].v;

 cout<<"Enter terms in B: ";cin>>t2;
 term b[20]; for(int i=0;i<t2;i++) cin>>b[i].r>>b[i].c>>b[i].v;

 term c[50]; int k=0;
 for(int i=0;i<t1;i++){
  for(int j=0;j<t2;j++){
   if(a[i].c==b[j].r){
    c[k].r=a[i].r;
    c[k].c=b[j].c;
    c[k].v=a[i].v*b[j].v;
    k++;
    }
   }
 }
 cout<<"Product:"<<endl;
 for(int i=0;i<k;i++) cout<<c[i].r<<" "<<c[i].c<<" "<<c[i].v<<endl;
}
