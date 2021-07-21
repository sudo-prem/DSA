// Problem Link:
// https://practice.geeksforgeeks.org/problems/maximum-path-sum/1#

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

    if (!root->left)
        return root->val + rightMax;
    else if (!root->right)
        return root->val + leftMax;

    res = max(res, leftMax + root->val + rightMax);
    return root->val + max(leftMax, rightMax);
}

int maxPathSum1(TreeNode *root)
{
    int res{INT_MIN};
    int currMax = helper1(root, res);

    return (res == INT_MIN) ? currMax : res;
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

    if (!root->left)
        return root->val + rightMax;
    else if (!root->right)
        return root->val + leftMax;

    res = max(res, leftMax + root->val + rightMax);
    return nodeHash[root] = root->val + max(leftMax, rightMax);
}

int maxPathSum2(TreeNode *root)
{
    int res{INT_MIN};
    unordered_map<TreeNode *, int> nodeHash;
    int currMax = helper2(root, res, nodeHash);

    return (res == INT_MIN) ? currMax : res;
}

void solve()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(-10);
    root->left->right = new TreeNode(4);

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