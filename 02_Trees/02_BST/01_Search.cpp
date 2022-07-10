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

TreeNode* recursiveSearch(TreeNode* root, int val)
{
	if (!root)
		return NULL;

	if (root->val == val)
		return root;
	if (val < root->val)
		return recursiveSearch(root->left, val);
	return recursiveSearch(root->right, val);
}

TreeNode* iterativeSearch(TreeNode* root, int val)
{
	auto curr = root;

	while (curr)
	{
		if (curr->val == val)
			return curr;
		if (val < curr->val)
			curr = curr->left;
		else
			curr = curr->right;
	}

	return NULL;
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

	cout << iterativeSearch(root, 5)->val << " " << recursiveSearch(root, 5)->val << endl;
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
