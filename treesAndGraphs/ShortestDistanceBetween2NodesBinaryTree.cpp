/**
 *    author:  Chet8n
 *    created: 06.11.2024 22:01:04
 **/
#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define all(x) (x).begin(), (x).end()
#define ceill(x, y) ((x + y - 1) / y)
#define setbits(x) __builtin_popcountll(x)

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const long long infl = 2e18 + 5;
double PI = 3.14159265358979323846;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  public:
    int findShortestDistance(TreeNode *root, int node1, int node2) {
        int distance = -1;

        function<pair<bool, int>(TreeNode *, int, int)> dfs = [&](TreeNode *cur, int node1,
                                                                  int node2) -> pair<bool, int> {
            if (cur == NULL) {
                return {false, 0};
            }

            bool current = (cur->val == node1 || cur->val == node2);
            pair<bool, int> left = dfs(cur->left, node1, node2);
            pair<bool, int> right = dfs(cur->right, node1, node2);

            if (current) {
                if (left.first) {
                    distance = left.second;
                    return {false, 0};
                } else if (right.first) {
                    distance = right.second;
                    return {false, 0};
                }
                return {true, 1};
            }
            if (left.first && right.first) {
                distance = left.second + right.second;
                return {false, 0};
            }

            if (left.first) {
                return {true, left.second + 1};
            }
            if (right.first) {
                return {true, right.second + 1};
            }
            return {false, 0};
        };

        dfs(root, node1, node2);
        return distance;
    }
};

#ifdef LOCAL
int32_t main() {
    fastio;
    int testCases = 1;
    // cin >> testCases;
    for (int i = 1; i <= testCases; i++) {
        Solution s;

        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);
        root->right->left = new TreeNode(6);
        root->right->right = new TreeNode(7);
        root->right->left->right = new TreeNode(8);

        int node1 = 4;
        int node2 = 1;

        auto ans = s.findShortestDistance(root, node1, node2);
        cout << ans << endl;
    }
}
#endif