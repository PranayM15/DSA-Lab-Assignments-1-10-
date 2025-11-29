#include <iostream>
using namespace std;

int main() {
    int r, c;

    cout << "Enter number of r and columns: ";
    cin >> r >> c;
    int a[r][c];

    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }

    cout << "\nSum of each row:\n";
    for (int i = 0; i < r; i++) {
        int r = 0;
        for (int j = 0; j < c; j++) {
            r += a[i][j];
        }
        cout << "Row " << i + 1 << " sum = " << r << endl;
    }

    cout << "\nSum of each column:\n";
    for (int j = 0; j < c; j++) {
        int c = 0;
        for (int i = 0; i < r; i++) {
            c += a[i][j];
        }
        cout << "Column " << j + 1 << " sum = " << c << endl;
    }
}
