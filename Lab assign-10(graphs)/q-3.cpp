#include <iostream>
#include <vector>
using namespace std;

vector<int> g[100];
int vis[100];

void dfs(int u) {
    vis[u] = 1;
    cout << u << " ";
    for (int x : g[u])
        if (!vis[x])
            dfs(x);
}

int main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int s;
    cin >> s;
    dfs(s);
}
