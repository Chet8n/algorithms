/**
 *    author:  Chet8n
 *    created: 31.10.2024 22:16:57
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

struct Edge {
    int u, v, wt;
    Edge() {};
    Edge(int u, int v, int wt) : u(u), v(v), wt(wt) {};
};

/**
 * populates the dist vector with the distances from the source to resp nodes
 * return value : -1 --> not negetive cycle
 *                 x --> negetive cycle found and node x is part of negative cycle.
 **/
vector<int> bellmannFord(int nodeCount, vector<Edge> &edges, int source, vector<long long> &dist) {
    dist = vector<long long>(nodeCount + 1, infl);
    dist[source] = 0;

    vector<int> negativeEdges;
    for (int relax = 1; relax <= nodeCount; relax++) {
        for (Edge edge : edges) {
            if (dist[edge.u] < infl && dist[edge.u] + edge.wt < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.wt;
                if (relax == nodeCount) {
                    negativeEdges.push_back(edge.u);
                }
            }
        }
    }
    return negativeEdges;
}

void solve() {

    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    vector<pair<int, int>> g[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        wt = -wt;
        g[u].push_back({v, wt});
        edges[i] = Edge(u, v, wt);
    }

    vector<long long> dist;
    vector<int> negativeEdges = bellmannFord(n, edges, 1, dist);
}

int32_t main() {
    fastio;
    int testCases = 1;
    // cin >> testCases;
    for (int i = 1; i <= testCases; i++) {
        solve();
    }
}