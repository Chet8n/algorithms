/**
 *    author:  Chet8n
 *    created: 01.11.2024 08:29:03
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

#define int ll

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> g[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
    }

    // assume there is node A* which has an edge to all nodes with wt = 0
    // A* is the source node.
    vector<int> dist(n + 1, 0);
    vector<int> relaxedBy(n + 1, -1);

    int neg = -1;
    for (int relax = 1; relax <= 2 * (n + 1); relax++) {
        for (int node = 1; node <= n; node++) {
            for (auto [childNode, wt] : g[node]) {
                if (dist[node] != infl && dist[node] + wt < dist[childNode]) {
                    dist[childNode] = dist[node] + wt;
                    relaxedBy[childNode] = node;
                    if (relax == n + 1) {
                        neg = childNode;
                    }
                }
            }
        }
    }
    if (neg == -1) {
        no;
        return;
    }
    // neg might not actually be part of cycle, could just be some node reachable by negative cycle
    // so trace back;
    set<int> seen;
    int cur = neg;
    while (seen.find(cur) == seen.end()) {
        seen.insert(cur);
        cur = relaxedBy[cur];
        assert(cur != -1);
    }
    vector<int> cycle;
    int node = cur;
    while (cycle.size() == 0 || node != cur) {
        cycle.push_back(node);
        node = relaxedBy[node];
    }
    cycle.push_back(node);
    reverse(all(cycle));
    yes;
    for (auto x : cycle) {
        cout << x << " ";
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