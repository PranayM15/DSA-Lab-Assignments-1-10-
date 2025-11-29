#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

int par[100];

int findP(int x) {
    if (par[x] == x) return x;
    return par[x] = findP(par[x]);
}

void unite(int a, int b) {
    a = findP(a);
    b = findP(b);
    par[b] = a;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);

    for (int i = 0; i < n; i++) par[i] = i;

    for (int i = 0; i < m; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges.begin(), edges.end(), [](Edge &a, Edge &b){
        return a.w < b.w;
    });

    int total = 0;
    for (auto &e : edges) {
        if (findP(e.u) != findP(e.v)) {
            unite(e.u, e.v);
            total += e.w;
            cout << e.u << " " << e.v << " " << e.w << endl;
        }
    }
    cout << total;
}
