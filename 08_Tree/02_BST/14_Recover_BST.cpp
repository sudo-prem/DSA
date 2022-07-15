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

void inorder(TreeNode* root, TreeNode* &first, TreeNode* &second, TreeNode* &prev)
{
	if (!root)
		return;

	inorder(root->left, first, second, prev);

	if (prev->val > root->val)
	{
		if (!first)
			first = prev;
		second = root;
	}

	prev = root;
	inorder(root->right, first, second, prev);
}

void recoverTree(TreeNode* root)
{
	TreeNode* first{NULL}, *second{NULL};
	TreeNode* prev = new TreeNode(INT_MIN);

	inorder(root, first, second, prev);

	swap(first->val, second->val);
}

void preorder(TreeNode* root)
{
	if (!root)
		return;

	preorder(root->left);
	cout << root->val << " ";
	preorder(root->right);
}

void solve()
{
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(5);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(8);

	preorder(root);
	cout << endl;

	recoverTree(root);

	preorder(root);
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
