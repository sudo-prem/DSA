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

void addLeftBoundary(TreeNode *root, vector<int> &res)
{
	if (!root or (!root->left and !root->right))
		return;

	res.push_back(root->val);
	if (root->left)
		addLeftBoundary(root->left, res);
	else
		addLeftBoundary(root->right, res);
}

void addLeaves(TreeNode* root, vector<int> &res)
{
	if (!root)
		return;
	if (!root->left and !root->right)
		res.push_back(root->val);

	addLeaves(root->left, res);
	addLeaves(root->right, res);
}

void addRightBoundary(TreeNode *root, vector<int> &res)
{
	if (!root or (!root->left and !root->right))
		return;

	if (root->right)
		addRightBoundary(root->right, res);
	else
		addRightBoundary(root->left, res);
	res.push_back(root->val);
}

vector<int> boundary(TreeNode *root)
{
	vector<int> res{root->val};

	addLeftBoundary(root->left, res);
	addLeaves(root->left, res);
	addLeaves(root->right, res);
	addRightBoundary(root->right, res);

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

	auto res = boundary(root);
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
