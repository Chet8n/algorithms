/**
 *    author:  Chet8n
 *    created: 20.10.2024 18:48:00
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

class Manacher {
    vector<int> p;

  public:
    void constructArray(string s) {
        int n = s.length();
        p = vector<int>(n, 1);

        for (int i = 1, L = 0, R = 0; i < n; i++) {
            int radius = (i > R) ? 1 : min(p[L + R - i], R - i);
            while (0 <= i - radius && i + radius < n && s[i - radius] == s[i + radius]) {
                radius++;
            }
            p[i] = radius--;
            if (i + radius > R) {
                L = i - radius;
                R = i + radius;
            }
        }
    }

    void build(string s) {
        string mString;
        for (char c : s) {
            mString += '#';
            mString += c;
        }
        mString += '#';
        constructArray(mString);
    }

    int getLongestRadius(int at, bool isCenter) {
        int position = 2 * at + 1;
        if (!isCenter)
            position++;
        return p[position] / 2;
    }

    bool isPalindrome(int l, int r) {
        int mid = (l + r) / 2;
        int len = (r - l + 1);
        if (l % 2 == r % 2) {
            // odd manacher
            return (getLongestRadius(mid, true) * 2 - 1) >= len;
        } else {
            // even manacher
            return (getLongestRadius(mid, false) * 2) >= len;
        }
        return false;
    }
};

void solve() {

    string s = "aabcbaa";
    Manacher m;
    m.build(s);

    cout << m.isPalindrome(0, s.length() - 1) << endl;
    cout << m.getLongestRadius(3, true) << endl;
    cout << m.getLongestRadius(3, false) << endl;
}

int32_t main() {
    fastio;
    int testCases = 1;
    // cin >> testCases;
    for (int i = 1; i <= testCases; i++) {
        solve();
    }
}