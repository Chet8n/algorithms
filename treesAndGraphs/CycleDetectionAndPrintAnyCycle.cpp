/**
 *    author:  Chet8n
 *    created: 31.10.2024 12:16:07
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

    function<bool(int, int, vector<int> &)> cycleCheck = [&](int curNode, int parentNode,
                                                             vector<int> &dfsPath) {
        visited[curNode] = 1;
        dfsPath.push_back(curNode);
        for (int childNode : g[curNode]) {
            if (childNode == parentNode) {
                continue;
            }
            if (!visited[childNode]) {
                bool foundCycle = cycleCheck(childNode, curNode, dfsPath);
                if (foundCycle) {
                    return foundCycle;
                }
            } else if (visited[childNode] == 1) {
                dfsPath.push_back(childNode);
                return true;
            }
        }
        dfsPath.pop_back();
        visited[curNode] = 2;
        return false;
    };

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            vector<int> cyclePath;
            bool cycleFound = cycleCheck(i, -1, cyclePath);
            if (cycleFound) {
                int index = -1;
                for (int i = 0; i < cyclePath.size(); i++) {
                    if (cyclePath[i] == cyclePath.back()) {
                        index = i;
                        break;
                    }
                }
                assert(index != -1 && index != cyclePath.size() - 1);
                cout << cyclePath.size() - index << endl;
                for (int i = index; i < cyclePath.size(); i++) {
                    cout << cyclePath[i] << " ";
                }
                cout << endl;
                return;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

int32_t main() {
    fastio;
    int testCases = 1;
    // cin >> testCases;
    for (int i = 1; i <= testCases; i++) {
        solve();
    }
}