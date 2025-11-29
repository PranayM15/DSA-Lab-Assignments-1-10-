// linear:
#include<iostream>
using namespace std;

int main() {
  int arr[] = {1,2,4,5,6};
  int n = 5;
  int sum = (n+1)*(n+2)/2;

  for(int i=0; i<n; i++) sum -= arr[i];

  cout << "Missing number is " << sum;
}


// binary:
#include<iostream>
using namespace std;

int main() {
  int arr[] = {1,2,3,5,6};
  int n = 5;
  int l=0,h=n-1;

  while(l<=h) {
    int mid = (l+h)/2;
    if(arr[mid] != mid+1) h = mid-1;
    else l = mid+1;
  }
  cout << "Missing number is " << l+1;
}
