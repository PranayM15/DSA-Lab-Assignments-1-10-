#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int g[100][100];
int key[100], vis[100], parent[100];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        vis[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int k = 0; k < n - 1; k++) {
        int u = -1;
        for (int i = 0; i < n; i++)
            if (!vis[i] && (u == -1 || key[i] < key[u]))
                u = i;

        vis[u] = 1;

        for (int v = 0; v < n; v++) {
            if (g[u][v] && !vis[v] && g[u][v] < key[v]) {
                key[v] = g[u][v];
                parent[v] = u;
            }
        }
    }

    for (int i = 1; i < n; i++)
        cout << parent[i] << " " << i << " " << g[parent[i]][i] << endl;
}
