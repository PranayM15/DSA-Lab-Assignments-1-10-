#include <iostream>
using namespace std;

int h[1000];
int hs = 0;

void up(int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h[p] < h[i]) swap(h[p], h[i]);
        else break;
        i = p;
    }
}

void down(int i) {
    while (true) {
        int l = 2*i + 1;
        int r = 2*i + 2;
        int x = i;

        if (l < hs && h[l] > h[x]) x = l;
        if (r < hs && h[r] > h[x]) x = r;

        if (x == i) break;
        swap(h[i], h[x]);
        i = x;
    }
}

void insertPQ(int v) {
    h[hs] = v;
    up(hs);
    hs++;
}

int getMaxPQ() {
    if (hs == 0) return -1;
    return h[0];
}

int extractMaxPQ() {
    if (hs == 0) return -1;
    int x = h[0];
    h[0] = h[hs-1];
    hs--;
    down(0);
    return x;
}

int main() {
    insertPQ(40);
    insertPQ(10);
    insertPQ(90);
    insertPQ(70);

    cout << getMaxPQ() << endl;
    cout << extractMaxPQ() << endl;
    cout << getMaxPQ() << endl;
}
