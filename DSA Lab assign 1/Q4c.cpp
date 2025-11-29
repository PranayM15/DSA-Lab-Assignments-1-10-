#include <iostream>
using namespace std;

int main() {
    int r, c;

    cout << "Enter rows and columns of matrix: ";
    cin >> r >> c;
    int a[r][c], b[c][r];

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> a[i][j];

     for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            b[j][i] = a[i][j];
        }
    }

    cout << "Transpose of matrix:\n";
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++)
            cout << b[i][j] << " ";
        cout << endl;
    }
}
