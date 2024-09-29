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
     * Same as knapsack-1 but the constraints differ
     * 1 <= N <= 500
     * 1 <= C, B[i] <= 10^6
     * 1 <= A[i] <= 50
     *
     * Lets define dp[i][j] ==> minimum weight required to make the Value of 'j'
     * with first 'i' elements
     **/

    int maxValuePossible = (*max_element(A.begin(), A.end())) * n;
    vector<vector<int>> dp(n + 1, vector<int>(maxValuePossible + 1, inf));
    for (int elements = 0; elements <= n; elements++) {
        dp[elements][0] = 0;
    }

    for (int elements = 1; elements <= n; elements++) {
        for (int value = 1; value <= maxValuePossible; value++) {
            dp[elements][value] = dp[elements - 1][value];
            if (A[elements - 1] <= value) {
                dp[elements][value] =
                    min(dp[elements][value],
                        B[elements - 1] + dp[elements - 1][value - A[elements - 1]]);
            }
        }
    }

    int ans = -1;
    for (int value = maxValuePossible; value >= 0; value--) {
        if (dp[n][value] <= C) {
            ans = value;
            break;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    fastio;
    int testCases = 1;
    // cin >> testCases;
    for (int i = 1; i <= testCases; i++) {
        solve();
    }
}