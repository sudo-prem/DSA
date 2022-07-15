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

TreeNode* recursiveInsert(TreeNode* root, int val)
{
	if (!root)
		return new TreeNode(val);

	if (val < root->val)
		root->left = recursiveInsert(root->left, val);
	else
		root->right = recursiveInsert(root->right, val);
	return root;
}

TreeNode* iterativeInsert(TreeNode* root, int val)
{
	if (!root)
		return new TreeNode(val);

	TreeNode* p{root}, *q{};

	while (p)
	{
		q = p;
		if (val < p->val)
			p = p->left;
		else
			p =  p->right;
	}

	if (val < q->val)
		q->left = new TreeNode(val);
	else
		q->right = new TreeNode(val);

	return root;
}

void inorder(TreeNode* root)
{
	if (!root)
		return;

	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);
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

	recursiveInsert(root, 9);
	iterativeInsert(root, 2);

	inorder(root);
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
