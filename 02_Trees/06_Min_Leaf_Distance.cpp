// Problem Link:
// https://www.geeksforgeeks.org/closest-leaf-to-a-given-node-in-binary-tree/

// TC: O(n)
// SC: O(n)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int _data) : data(_data), left(NULL), right(NULL) {}
};

void findByLeaf(Node *root, int level, int &res)
{
    if (root == NULL)
        return;

    if (root->left == NULL and root->right == NULL)
    {
        res = min(res, level);
        return;
    }

    findByLeaf(root->left, level + 1, res);
    findByLeaf(root->right, level + 1, res);
}

int findByParent(Node *root, Node *target, int &res)
{
    if (!root)
        return -1;
    if (root == target)
        return 0;

    int l = findByParent(root->left, target, res);
    if (l != -1)
    {
        findByLeaf(root->right, l + 2, res);
        return l + 1;
    }

    int r = findByParent(root->right, target, res);
    if (r != -1)
    {
        findByLeaf(root->left, r + 2, res);
        return r + 1;
    }

    return -1;
}

int minHeightToLeaf(Node *root, Node *target)
{
    int res = INT_MAX;

    findByLeaf(target, 0, res);
    findByParent(root, target, res);

    return res;
}

void solve()
{
    Node *root = new Node(1);
    root->left = new Node(12);
    root->left->left = new Node(19);
    root->right = new Node(13);

    root->right->left = new Node(14);
    root->right->right = new Node(15);

    root->right->left->left = new Node(21);
    root->right->left->right = new Node(22);
    root->right->right->left = new Node(23);
    root->right->right->right = new Node(24);

    root->right->left->left->left = new Node(1);
    root->right->left->left->right = new Node(2);
    root->right->left->right->left = new Node(3);
    root->right->left->right->right = new Node(4);
    root->right->right->left->left = new Node(5);
    root->right->right->left->right = new Node(6);
    root->right->right->right->left = new Node(7);
    root->right->right->right->right = new Node(8);
    Node *target = root->right;

    cout << minHeightToLeaf(root, target) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t{1}, i{1};
    // cin >> t;
    while (t--)
    {
        // cout << "Case #" << i++ << ": ";
        solve();
    }
    return 0;
}