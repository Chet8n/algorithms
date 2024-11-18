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

#ifdef LOCAL
#include "algo/debug.h"
#else
#define db(...) 20
#endif

/**
 * https://cses.fi/problemset/task/1682/
 **/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> g[n + 1], revG[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        revG[v].push_back(u);
    }

    vector<int> visited(n + 1, 0), nodes;
    function<void(int)> dfs = [&](int node) {
        visited[node] = 1;
        for (auto child : g[node]) {
            if (!visited[child]) {
                dfs(child);
            }
        }
        nodes.push_back(node);
    };

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    function<void(int, vector<int> &)> dfs2 = [&](int node, vector<int> &component) {
        visited[node] = 1;
        for (auto child : revG[node]) {
            if (!visited[child]) {
                dfs2(child, component);
            }
        }
        component.push_back(node);
    };

    vector<vector<int>> components;
    vector<int> componentNodes;
    fill(all(visited), 0);
    for (int i = (int)nodes.size() - 1; i >= 0; i--) {
        if (!visited[nodes[i]]) {
            vector<int> component;
            dfs2(nodes[i], component);
            components.push_back(component);
            componentNodes.push_back(nodes[i]);
        }
    }

    if (components.size() != 1) {
        cout << "NO" << endl;
        cout << componentNodes[1] << " " << componentNodes[0] << endl;
    } else {
        cout << "YES" << endl;
    }
}

int32_t main() {
    fastio;
    int testCases = 1;
    // cin >> testCases;
    for (int i = 1; i <= testCases; i++) {
        solve();
    }
}