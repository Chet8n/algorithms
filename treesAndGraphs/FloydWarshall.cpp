/**
 *    author:  Chet8n
 *    created: 31.10.2024 18:47:19
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
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> distance(n + 1, vector<int>(n + 1, infl));
    for (int i = 1; i <= n; i++) {
        distance[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        distance[u][v] = min(distance[u][v], w);
        distance[v][u] = min(distance[v][u], w);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (distance[i][k] == infl || distance[k][j] == infl) {
                    /**
                     * this if condition is not required for +ve weights.
                     * required for negative weighs coz if initial distance = infl && wt = -x
                     * then distance + (-x) = distance - x gives lesser distance which is not true.
                     **/
                    continue;
                }
                if (distance[k][k] < 0) {
                    // there is a negative cycle
                }
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }

    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << (distance[u][v] == infl ? -1 : distance[u][v]) << endl;
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