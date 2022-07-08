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

TreeNode* convertChildrenSum(TreeNode* root)
{
	if (!root or (!root->left and !root->right))
		return root;

	int leftVal = root->left ? root->left->val : 0;
	int rightVal = root->right ? root->right->val : 0;

	if (root->val >= leftVal + rightVal)
	{
		if (root->left)
			root->left->val = root->val;
		if (root->right)
			root->right->val = root->val;
	}
	else
		root->val = leftVal + rightVal;

	root->left = convertChildrenSum(root->left);
	root->right = convertChildrenSum(root->right);

	leftVal = root->left ? root->left->val : 0;
	rightVal = root->right ? root->right->val : 0;
	root->val = leftVal + rightVal;

	return root;
}

int isSumProperty(TreeNode *root)
{
	if (!root or (!root->left and !root->right))
		return true;

	int left = root->left ? root->left->val : 0;
	int right = root->right ? root->right->val : 0;

	if (left + right != root->val)
		return false;
	return isSumProperty(root->left) and isSumProperty(root->right);
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

	root = convertChildrenSum(root);
	cout << isSumProperty(root) << endl;
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
