#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

class TreeNode
{
public:
	int val;
	TreeNode* left, *right;

	TreeNode(int _val): val(_val), left(NULL), right(NULL) {}
};

class NodeValue
{
public:
	bool isValid;
	int count;
	int maxVal;
	int minVal;

	NodeValue(bool _isValid, int _count, int _maxVal, int _minVal):
		isValid(_isValid), count(_count), maxVal(_maxVal), minVal(_minVal) {}
};

NodeValue helper(TreeNode* root, int &res)
{
	if (!root)
		return {true, 0, INT_MIN, INT_MAX};

	auto left = helper(root->left, res);
	auto right = helper(root->right, res);

	if (!left.isValid or !right.isValid)
		return {false, 0, 0, 0};

	if (root->val <= left.maxVal or root->val >= right.minVal)
		return {false, 0, 0, 0};

	res = max(res, left.count + right.count + 1);
	return {true, left.count + right.count + 1,  max(root->val, right.maxVal), min(root->val, left.minVal)};
}

int largestBst(TreeNode *root)
{
	int res{};

	helper(root, res);

	return res;
}

void solve()
{
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(3);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(8);

	cout << largestBst(root) << endl;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ONPC
	freopen("input.txt", "r", stdin);
#endif
	int t {1};
	/* int i {1}; cin >> t; */
	while (t--)
	{
		/* cout << "Case #" << i++ << ": "; */
		solve();
	}
	return 0;
}
