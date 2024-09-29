/**
 *    author:  Chet8n
 *    created: 29.09.2024 14:55:14
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

class Trie {
  public:
    struct Node {
        Node *arr[26];
        bool isEnd;

        Node() {
            for (int i = 0; i < 26; i++) {
                arr[i] = NULL;
            }
            isEnd = false;
        }
    };

    char base = 'a';
    Node *root;
    Trie() { root = new Node(); }

    void insert(const string &s) {
        Node *cur = root;
        for (char ch : s) {
            if (!cur->arr[ch - base])
                cur->arr[ch - base] = new Node();
            cur = cur->arr[ch - base];
        }
        cur->isEnd = true;
    }

    bool search(const string &s) {
        Node *cur = root;
        for (char ch : s) {
            if (!cur->arr[ch - base])
                return false;
            cur = cur->arr[ch - base];
        }
        return (cur != NULL and cur->isEnd);
    }
};

void solve() {}

int32_t main() {
    fastio;
    int testCases = 1;
    // cin >> testCases;
    for (int i = 1; i <= testCases; i++) {
        solve();
    }
}