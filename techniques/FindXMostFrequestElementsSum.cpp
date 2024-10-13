/**
 *    author:  Chet8n
 *    created: 13.10.2024 19:59:39
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<long long, long long> pi;
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

vector<long long> findXSum(vector<int> &nums, int k, int x) {

    int n = nums.size();

    map<long long, long long> freq;
    set<pair<long long, long long>> first;
    set<pair<long long, long long>> sec;
    long long sum = 0;

    auto balance = [&]() {
        while (first.size() > x) {
            pair<long long, long long> firstPair = *first.begin();
            first.erase(firstPair);
            sum -= (firstPair.first * firstPair.second);
            sec.insert(firstPair);
        }

        while (first.size() < x && sec.size()) {
            pair<long long, long long> lastPair = *(--sec.end());
            sec.erase(lastPair);
            first.insert(lastPair);
            sum += (lastPair.first * lastPair.second);
        }

        while (first.size() && sec.size()) {
            pair<long long, long long> pair1 = *first.begin();
            pair<long long, long long> pair2 = *(--sec.end());
            if (pair1 < pair2) {
                first.erase(pair1);
                sum -= (pair1.first * pair1.second);
                sec.insert(pair1);
                sec.erase(pair2);
                first.insert(pair2);
                sum += (pair2.first * pair2.second);
            } else {
                break;
            }
        }
    };

    auto add = [&](int x) {
        pair<long long, long long> cur = {freq[x], x};
        if (first.find(cur) != first.end()) {
            sum -= cur.first * cur.second;
        }
        first.erase(cur);
        sec.erase(cur);
        freq[x]++;
        cur.first = freq[x];
        first.insert(cur);
        sum += (cur.first * cur.second);
        balance();
    };

    auto remove = [&](int x) {
        pair<long long, long long> cur = {freq[x], x};
        if (first.find(cur) != first.end()) {
            sum -= (cur.first * cur.second);
        }
        first.erase(cur);
        sec.erase(cur);
        freq[x]--;
        cur.first = freq[x];
        if (freq[x]) {
            first.insert(cur);
            sum += (1LL * cur.first * cur.second);
        }
        balance();
    };

    for (int i = 0; i < k - 1; i++) {
        add(nums[i]);
    }

    vector<long long> ans;
    for (int i = k - 1; i < n; i++) {
        add(nums[i]);
        ans.push_back(sum);
        remove(nums[i - k + 1]);
    }

    return ans;
}

void solve() {

    vector<int> nums = {1, 1, 2, 2, 3, 4, 2, 3};
    int k = 6;
    int x = 2;
    vector<long long> result = findXSum(nums, k, x);
    for (auto x : result) {
        cout << x << " ";
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