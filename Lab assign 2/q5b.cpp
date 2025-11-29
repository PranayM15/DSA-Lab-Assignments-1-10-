#include<iostream>
using namespace std;
int main(){
 int n;
 cout<<"Enter size: ";
 cin>>n;
 int a[3*n-2];
 cout<<"Enter "<<3*n-2<<" elements: ";
 for(int i=0;i<3*n-2;i++) cin>>a[i];

 cout<<"Matrix:"<<endl;
 for(int i=0;i<n;i++){
  for(int j=0;j<n;j++){
   if(abs(i-j)<=1){
    if(j==i-1) cout<<a[i-1]<<" ";
    else if(j==i) cout<<a[n-1+i]<<" ";
    else cout<<a[2*n-1+i]<<" ";
   }else cout<<"0 ";
  }
  cout<<endl;
  }
}
