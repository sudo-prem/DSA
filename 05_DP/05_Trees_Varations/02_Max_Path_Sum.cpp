// Problem Link:
// https://leetcode.com/problems/binary-tree-maximum-path-sum/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

class TreeNode
{
public:
    TreeNode *left;
    int val;
    TreeNode *right;

    TreeNode(int _val) : val(_val) {}
};

// Approach 1:
// Recursion
int helper1(TreeNode *root, int &res)
{
    if (!root)
        return 0;

    int leftMax = helper1(root->left, res);
    int rightMax = helper1(root->right, res);
    int currMax = max(root->val, root->val + max(leftMax, rightMax));

    res = max(res, max(currMax, leftMax + root->val + rightMax));
    return currMax;
}

int maxPathSum1(TreeNode *root)
{
    int res{INT_MIN};

    helper1(root, res);
    return res;
}

// Approach 2:
// Recursion + Memoization
int helper2(TreeNode *root, int &res, unordered_map<TreeNode *, int> &nodeHash)
{
    if (!root)
        return 0;

    if (nodeHash.find(root) != nodeHash.end())
        return nodeHash[root];

    int leftMax = helper2(root->left, res, nodeHash);
    int rightMax = helper2(root->right, res, nodeHash);
    int currMax = max(root->val, root->val + max(leftMax, rightMax));

    res = max(res, max(currMax, leftMax + root->val + rightMax));
    return nodeHash[root] = currMax;
}

int maxPathSum2(TreeNode *root)
{
    int res{INT_MIN};
    unordered_map<TreeNode *, int> nodeHash;

    helper2(root, res, nodeHash);
    return res;
}

void solve()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    cout << maxPathSum1(root) << endl;
    cout << maxPathSum2(root) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t{1};
    // cin >> t;
    while (t--)
        solve();
    return 0;
}