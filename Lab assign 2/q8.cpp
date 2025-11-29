#include<iostream>
#include<set>
using namespace std;

int main() {
  int arr[] = {1,2,2,3,4,4,5};
  int n = 7;

  set<int> s;
  for(int i=0; i<n; i++) {s.insert(arr[i]);
  }
  cout <<"Distinct count: "<< s.size();
}
