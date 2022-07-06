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

int leftHeight(TreeNode* root)
{
	int res{};

	while (root)
	{
		res++;
		root = root->left;
	}

	return res;
}

int rightHeight(TreeNode* root)
{
	int res{};

	while (root)
	{
		res++;
		root = root->right;
	}

	return res;
}

int countNodes(TreeNode* root)
{
	if (!root)
		return 0;

	int currLeft = leftHeight(root);
	int currRight = rightHeight(root);

	if (currLeft == currRight)
		return (1 << currLeft) - 1;
	return 1 + countNodes(root->left) + countNodes(root->right);
}

void solve()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);

	cout << countNodes(root) << endl;
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
