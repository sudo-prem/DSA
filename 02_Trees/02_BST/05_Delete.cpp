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

void inorder(TreeNode* root)
{
	if (!root)
		return;

	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);
}

TreeNode* inPre(TreeNode* root)
{
	root = root->left;
	while (root->right)
		root = root->right;
	return root;
}

TreeNode* inSuc(TreeNode* root)
{
	root = root->right;
	while (root->left)
		root = root->left;
	return root;
}

TreeNode* deleteNode(TreeNode* root, int key)
{
	if (!root)
		return NULL;

	if (root->val == key)
	{
		if (!root->left and !root->right)
		{
			delete root;
			root = NULL;
		}
		else if (root->left)
		{
			auto pre = inPre(root);
			swap(pre->val, root->val);
			root->left = deleteNode(root->left, key);
		}
		else
		{
			auto suc = inSuc(root);
			swap(suc->val, root->val);
			root->right = deleteNode(root->right, key);
		}

		return root;
	}
	else if (key < root->val)
		root->left = deleteNode(root->left, key);
	else
		root->right = deleteNode(root->right, key);

	return root;
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

	inorder(root);
	cout << endl;
	deleteNode(root, 7);
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
