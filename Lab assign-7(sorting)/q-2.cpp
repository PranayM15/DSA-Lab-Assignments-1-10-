#include <iostream>
using namespace std;
// optimized:
void SelectionSort(int a[], int n) {
    for (int i = 0; i < n/2; i++) {
        int minI = i;
        int maxI = i;

        for (int j = i; j < n - i; j++) {
            if (a[j] < a[minI]) minI = j;
            if (a[j] > a[maxI]) maxI = j;
        }

        swap(a[i], a[minI]);

        if (maxI == i) maxI = minI;

        swap(a[n - i - 1], a[maxI]);
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int a[1000];
    for (int i = 0; i < n; i++) cin >> a[i];

    SelectionSort(a, n);
    printArray(a, n);
}
