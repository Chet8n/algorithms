#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define ceill(x, y) ((x + y - 1) / y)
#define setbits(x) __builtin_popcountll(x)

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const long long infl = 2e18 + 5;
double PI = 3.14159265358979323846;

/**
 * https://cses.fi/problemset/task/1675/
 **/

class Dsu {
    vector<int> parent, size;
    int components;

  public:
    Dsu(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        components = n;
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    bool unite(int u, int v) {
        int parU = findParent(u);
        int parV = findParent(v);
        if (parU == parV)
            return false;
        if (size[parU] > size[parV]) {
            parent[parV] = parU;
            size[parU] += size[parV];
        } else {
            parent[parU] = parV;
            size[parV] += size[parU];
        }
        components--;
        return true;
    }

    int findParent(int u) {
        if (parent[u] == u) {
            return u;
        }
        return parent[u] = findParent(parent[u]);
    }

    bool isSameComponent(int u, int v) {
        int parU = findParent(u);
        int parV = findParent(v);
        return parU == parV;
    }

    int getComponentsCount() { return components; }
};

struct Edge {
    int u, v, w;
    Edge() {};
    Edge(int u, int v, int w) : u(u), v(v), w(w) {};
};

void solve() {

    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }

    sort(all(edges), [&](Edge a, Edge b) { return a.w < b.w; });

    Dsu dsu(n);
    long long ans = 0;
    for (int i = 0; i < m; i++) {
        bool diffComponent = dsu.unite(edges[i].u, edges[i].v);
        if (diffComponent) {
            ans += edges[i].w;
        }
    }
    if (dsu.getComponentsCount() == 1)
        cout << ans << endl;
    else
        cout << "IMPOSSIBLE" << endl;
}

int32_t main() {
    fastio;
    int testCases = 1;
    // cin >> testCases;
    for (int i = 1; i <= testCases; i++) {
        solve();
    }
}