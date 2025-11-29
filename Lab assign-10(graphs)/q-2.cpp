#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> g[100];
int vis[100];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    vis[s] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int x : g[u]) {
            if (!vis[x]) {
                vis[x] = 1;
                q.push(x);
            }
        }
    }
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
    bfs(s);
}
