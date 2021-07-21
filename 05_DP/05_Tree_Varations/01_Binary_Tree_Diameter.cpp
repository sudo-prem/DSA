// Problem Link:
// https://leetcode.com/problems/diameter-of-binary-tree/

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
    int currMax = 1 + max(leftMax, rightMax);

    res = max(res, leftMax + rightMax);
    return currMax;
}

int diameterOfBinaryTree1(TreeNode *root)
{
    int res{INT_MIN};

    helper1(root, res);
    return res;
}

// Approach 2:
// Recursion + Memoization
int helper2(TreeNode *root, int &res, unordered_map<TreeNode *, int> &dp)
{
    if (!root)
        return 0;

    if (dp.find(root) != dp.end())
        return dp[root];

    int leftMax = helper2(root->left, res, dp);
    int rightMax = helper2(root->right, res, dp);

    res = max(res, leftMax + rightMax);
    return dp[root] = 1 + max(leftMax, rightMax);
}

int diameterOfBinaryTree2(TreeNode *root)
{
    int res{INT_MIN};
    unordered_map<TreeNode *, int> dp;

    helper2(root, res, dp);
    return res;
}

void solve()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << diameterOfBinaryTree1(root) << endl;
    cout << diameterOfBinaryTree2(root) << endl;
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