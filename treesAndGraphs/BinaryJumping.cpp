/**
 *    author:  Chet8n
 *    created: 18.11.2024 10:36:40
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
 * https://cses.fi/problemset/task/1750/
 **/

void solve() {
    int n, q;
    cin >> n >> q;
    const int LOG = 30;
    vector<vector<int>> dp(n + 1, vector<int>(LOG, 0));
    for (int i = 1; i <= n; i++) {
        cin >> dp[i][0];
    }

    for (int i = 1; i < LOG; i++) {
        for (int node = 1; node <= n; node++) {
            dp[node][i] = dp[dp[node][i - 1]][i - 1];
        }
    }

    while (q--) {
        int node, k;
        cin >> node >> k;
        for (int i = LOG - 1; i >= 0 && node > 0 && k > 0; i--) {
            int mask = (1 << i);
            if (k & mask) {
                node = dp[node][i];
                k -= mask;
            }
        }
        cout << node << endl;
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