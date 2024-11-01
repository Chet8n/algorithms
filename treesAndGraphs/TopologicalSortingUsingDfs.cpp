/**
 *    author:  Chet8n
 *    created: 01.11.2024 09:23:03
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
 * https://cses.fi/problemset/task/1679/
 **/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> g[n + 1];
    vector<int> indegree(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    bool cycle = false;
    vector<int> ans;
    vector<int> visited(n + 1, 0);
    function<void(int)> dfs = [&](int curNode) {
        visited[curNode] = 1;
        for (int childNode : g[curNode]) {
            if (!visited[childNode]) {
                dfs(childNode);
            } else if (visited[childNode] == 1) {
                cycle = true;
            }
        }
        visited[curNode] = 2;
        ans.push_back(curNode);
    };

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    if (cycle == true) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    reverse(all(ans));
    for (auto x : ans) {
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