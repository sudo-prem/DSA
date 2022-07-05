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

void nodesFromTarget(TreeNode* target, int k, vector<int> &res)
{
	if (!target)
		return;
	if (k == 0)
	{
		res.push_back(target->val);
		return;
	}

	if (target->left)
		nodesFromTarget(target->left, k - 1, res);
	if (target->right)
		nodesFromTarget(target->right, k - 1, res);
}

int nodesAboveTarget(TreeNode* root, TreeNode* target, int k, vector<int> &res)
{
	if (!root)
		return -1;
	if (root == target)
		return 0;

	int left = nodesAboveTarget(root->left, target, k, res);
	if (left != -1)
	{
		left++;
		if (left == k)
			res.push_back(root->val);
		else
			nodesFromTarget(root->right, k - left - 1, res);
		return left;
	}

	int right = nodesAboveTarget(root->right, target, k, res);
	if (right != -1)
	{
		right++;
		if (right == k)
			res.push_back(root->val);
		else
			nodesFromTarget(root->left, k - right - 1, res);
		return right;
	}

	return -1;
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
{
	vector<int> res{};

	nodesFromTarget(target, k, res);
	nodesAboveTarget(root, target, k, res);

	return res;
}

void solve()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);
	root->left->right->left = new TreeNode(8);
	root->right->right->left = new TreeNode(9);
	root->right->right->right = new TreeNode(10);

	auto res = distanceK(root, root->left->left, 2);

	for (int num : res)
		cout << num << " ";
	cout << endl;
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
