#include <iostream>
using namespace std;

void heapify(int a[], int n, int i, bool maxH) {
    int x = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (maxH) {
        if (l < n && a[l] > a[x]) x = l;
        if (r < n && a[r] > a[x]) x = r;
    } else {
        if (l < n && a[l] < a[x]) x = l;
        if (r < n && a[r] < a[x]) x = r;
    }

    if (x != i) {
        swap(a[i], a[x]);
        heapify(a, n, x, maxH);
    }
}

void heapSort(int a[], int n, bool increasing) {
    bool maxH = increasing;

    for (int i = n/2 - 1; i >= 0; i--)
        heapify(a, n, i, maxH);

    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0, maxH);
    }
}

int main() {
    int n;
    cin >> n;
    int a[100];
    for (int i = 0; i < n; i++) cin >> a[i];

    heapSort(a, n, true);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    heapSort(a, n, false);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
}
