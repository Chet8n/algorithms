/**
 *    author:  Chet8n
 *    created: 31.10.2024 18:13:31
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

    vector<int> distance(n + 1, infl);
    vector<int> visited(n + 1, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.emplace(0, 1);
    distance[1] = 0;

    while (!q.empty()) {
        auto curNode = q.top();
        int node = curNode.second;
        int nodeDist = curNode.first;
        q.pop();

        if (visited[node]) {
            continue;
        }
        visited[node] = 1;

        for (pair<int, int> childNode : g[node]) {
            int vNode = childNode.first;
            int w = childNode.second;
            if (nodeDist + w < distance[vNode]) {
                distance[vNode] = nodeDist + w;
                q.emplace(distance[vNode], vNode);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << distance[i] << " ";
    }
    cout << endl;
}

int32_t main() {
    fastio;
    int testCases = 1;
    // cin >> testCases;
    for (int i = 1; i <= testCases; i++) {
        solve();
    }
}