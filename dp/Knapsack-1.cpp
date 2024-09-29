/**
 *    author:  Chet8n
 *    created: 29.09.2024 20:00:38
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

void solve() {
    vector<int> A = {60, 100, 120};
    vector<int> B = {10, 20, 30};
    int C = 50;
    int n = (int)A.size();

    /**
     * dp[i][j] ==> max value that can be acheived with first i elements and a knapsack of total
     * capacity j
     **/
    vector<vector<int>> dp(n + 1, vector<int>(C + 1, 0));
    for (int elements = 1; elements <= n; elements++) {
        for (int capacity = 1; capacity <= C; capacity++) {
            // do not consider current element;
            dp[elements][capacity] = dp[elements - 1][capacity];
            // check if we can consider current element
            if (B[elements - 1] <= capacity) {
                dp[elements][capacity] =
                    max(dp[elements][capacity],
                        A[elements - 1] + dp[elements - 1][capacity - B[elements - 1]]);
            }
        }
    }

    cout << dp[n][C] << endl;

    /**
     * You can see that everytime you calculate dp[i][j] value, you only need previous array,
     * i.e, dp[i-1][some J]
     **/

    vector<int> dp2(C + 1, 0);
    for (int elements = 1; elements <= n; elements++) {
        for (int capacity = C; capacity >= 1; capacity--) {
            if (B[elements - 1] <= capacity) {
                dp2[capacity] =
                    max(dp2[capacity], A[elements - 1] + dp2[capacity - B[elements - 1]]);
            }
        }
    }
    cout << dp2[C] << endl;
}

int32_t main() {
    fastio;
    int testCases = 1;
    // cin >> testCases;
    for (int i = 1; i <= testCases; i++) {
        solve();
    }
}