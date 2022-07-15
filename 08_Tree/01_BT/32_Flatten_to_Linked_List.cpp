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

void flatten1(TreeNode* root)
{
	if (!root)
		return;

	auto leftNode = root->left;
	auto rightNode = root->right;
	flatten1(leftNode);

	root->left = NULL;
	root->right = leftNode;

	auto itr = root;
	while (itr->right)
		itr = itr->right;
	itr->right = rightNode;

	flatten1(rightNode);
}

void flatten2(TreeNode* root)
{
	auto curr = root;

	while (curr)
	{
		auto leftNode = curr->left;
		if (leftNode)
		{
			while (leftNode->right)
				leftNode = leftNode->right;

			leftNode->right = curr->right;
			curr->right = curr->left;
			curr->left = NULL;
			curr = curr->right;
		}
		else
			curr = curr->right;
	}
}

void inorderTraversal(TreeNode* root)
{
	if (!root)
		return;

	inorderTraversal(root->left);
	cout << root->val << " ";
	inorderTraversal(root->right);
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

	/* flatten1(root); */
	flatten2(root);
	inorderTraversal(root);
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
