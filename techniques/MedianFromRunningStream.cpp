/**
 *    author:  Chet8n
 *    created: 13.10.2024 20:40:05
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
 * Problem : https://leetcode.com/problems/find-median-from-data-stream/description/
 **/

class MedianFinder {
  public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<>> right;
    const int inf = 1e9 + 7;
    MedianFinder() {
        left.push(-inf);
        right.push(inf);
    }

    void addNum(int num) {

        int leftMax = left.top();
        int rightMin = right.top();
        if (num <= leftMax) {
            left.push(num);
            if (left.size() > right.size()) {
                int topElement = left.top();
                left.pop();
                right.push(topElement);
            }
        } else {
            right.push(num);
            if (left.size() + 1 < right.size()) {
                int topElement = right.top();
                right.pop();
                left.push(topElement);
            }
        }
    }

    double findMedian() {

        if (left.size() == right.size()) {
            int leftTop = left.top();
            int rightTop = right.top();
            return (1.0 * leftTop + rightTop) / 2;
        }
        return right.top();
    }
};

void solve() {

    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << mf.findMedian() << endl;
    assert(1.5 == mf.findMedian());
    mf.addNum(3);
    cout << mf.findMedian() << endl;
    assert(2 == mf.findMedian());
}

int32_t main() {
    fastio;
    int testCases = 1;
    // cin >> testCases;
    for (int i = 1; i <= testCases; i++) {
        solve();
    }
}