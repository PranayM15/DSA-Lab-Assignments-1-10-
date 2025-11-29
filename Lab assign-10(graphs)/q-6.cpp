#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int g[100][100];
int dista[100], vis[100];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    int src;
    cin >> src;

    for (int i = 0; i < n; i++) {
        dista[i] = INT_MAX;
        vis[i] = 0;
    }

    dista[src] = 0;

    for (int k = 0; k < n - 1; k++) {
        int u = -1;
        for (int i = 0; i < n; i++)
            if (!vis[i] && (u == -1 || dista[i] < dista[u]))
                u = i;

        vis[u] = 1;

        for (int v = 0; v < n; v++) {
            if (g[u][v] && dista[u] + g[u][v] < dista[v])
                dista[v] = dista[u] + g[u][v];
        }
    }

    for (int i = 0; i < n; i++)
        cout << dista[i] << " ";
}
