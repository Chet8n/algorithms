/**
 *    author:  Chet8n
 *    created: 29.09.2024 09:33:36
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pi;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define pb push_back
#define mp make_pair
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

// https://cses.fi/problemset/task/1687/

void solve() {

    int n, q;
    cin >> n >> q;
    vector<int> g[n + 5];
    for (int i = 2; i <= n; i++) {
        int u = i;
        int v;
        cin >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    const long long LOG = 20;
    vector<vector<int>> up(n + 5, vector<int>(LOG));

    function<void(int, int)> dfs = [&](int cur, int par) {
        up[cur][0] = par;
        for (int i = 1; i < 20; i++) {
            if (up[cur][i - 1] != -1) {
                int midNode = up[cur][i - 1];
                up[cur][i] = up[midNode][i - 1];
            } else {
                up[cur][i] = -1;
            }
        }
        for (auto v : g[cur]) {
            if (v != par) {
                dfs(v, cur);
            }
        }
    };

    function<int(int, int)> getKthAncestor = [&](int node, int k) {
        for (int i = 19; i >= 0 && node >= 0 && k > 0; i--) {
            int mask = (1 << i);
            if (k & mask) {
                node = up[node][i];
                k -= (mask);
            }
        }
        return node;
    };
    dfs(1, -1);
    while (q--) {
        int u, k;
        cin >> u >> k;
        cout << getKthAncestor(u, k) << endl;
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