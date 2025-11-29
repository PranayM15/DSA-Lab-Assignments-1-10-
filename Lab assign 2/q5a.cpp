#include<iostream>
using namespace std;
int main(){
 int n; 
 cout<<"Enter size: ";
 cin>>n;
 int d[n];
 cout<<"Enter "<<n<<" diagonal elements: ";
 for(int i=0;i<n;i++) cin>>d[i];

 cout<<"Matrix:"<<endl;
 for(int i=0;i<n;i++){
  for(int j=0;j<n;j++){
   if(i==j) cout<<d[i]<<" ";
   else cout<<"0 ";
  }
  cout<<endl;
  }
}
