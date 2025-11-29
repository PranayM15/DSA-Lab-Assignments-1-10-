#include<iostream>
using namespace std;
struct term{int r,c,v;};
int main(){
 int t;
 cout<<"Enter no of non-zero terms: ";
 cin>>t;
 term a[20],b[20];
 cout<<"Enter row col val:"<<endl;
 for(int i=0;i<t;i++) cin>>a[i].r>>a[i].c>>a[i].v;

 int k=0;
 for(int i=0;i<t;i++){
  b[k].r=a[i].c;
  b[k].c=a[i].r;
  b[k].v=a[i].v;
  k++;
 }

 cout<<"Transpose:"<<endl;
 for(int i=0;i<k;i++) cout<<b[i].r<<" "<<b[i].c<<" "<<b[i].v<<endl;
}
