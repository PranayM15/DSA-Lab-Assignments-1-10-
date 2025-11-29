#include <iostream>
#include <vector>
using namespace std;

int adjM[100][100];
vector<int> adjL[100];

void addEdge(int u, int v) {
    adjM[u][v] = 1;
    adjM[v][u] = 1;
    adjL[u].push_back(v);
    adjL[v].push_back(u);
}

int degree(int v, int n) {
    int d = 0;
    for (int i = 0; i < n; i++)
        if (adjM[v][i]) d++;
    return d;
}

void adjacentVertices(int v) {
    for (int x : adjL[v]) cout << x << " ";
    cout << endl;
}

int countEdges(int n) {
    int c = 0;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            if (adjM[i][j]) c++;
    return c;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }
    int v;
    cin >> v;
    cout << degree(v, n) << endl;
    adjacentVertices(v);
    cout << countEdges(n) << endl;
}
