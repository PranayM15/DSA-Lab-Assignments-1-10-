#include<iostream>
using namespace std;

int binSearch(int arr[], int n, int key) {
  int l = 0, h = n - 1;
  while(l <= h) {
    int mid = (l + h) / 2;
    if(arr[mid] == key) return mid;
    else if(arr[mid] < key) l = mid + 1;
    else h = mid - 1;
  }
  return -1;
}

int main() {
  int arr[] = {11,12,22,25,34,64,90};
  int n = 7, x;
  cout << "Enter element: ";
  cin >> x;
  int pos = binSearch(arr, n, x);
  if(pos == -1) cout << "Not found";
  else cout << "Found at index " << pos;
}
