/**
 *    author:  Chet8n
 *    created: 31.10.2024 12:03:22
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pi;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define ceill(x, y) ((x + y - 1) / y)
#define setbits(x) __builtin_popcountll(x)

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const long long infl = 2e18 + 5;
double PI = 3.14159265358979323846;

/**
 * https://cses.fi/problemset/task/1668/
 **/

void solve() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> g[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> visited(n + 1, 0);
    function<bool(int, int)> bipartiteCheck = [&](int curNode, int curColor) {
        visited[curNode] = curColor;
        bool here = true;
        for (int childNode : g[curNode]) {
            if (visited[childNode] == 0) {
                here &= bipartiteCheck(childNode, 3 - curColor);
            } else if (visited[childNode] == curColor) {
                here = false;
            }
        }
        return here;
    };

    bool isBipartite = true;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            isBipartite &= bipartiteCheck(i, 1);
        }
    }
    if (!isBipartite) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int i = 1; i <= n; i++) {
            cout << visited[i] << " ";
        }
        cout << endl;
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