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

int maxDepthRecursive(TreeNode* root)
{
	if (!root)
		return 0;

	int res1 = maxDepthRecursive(root->left);
	int res2 = maxDepthRecursive(root->right);
	return max(res1, res2) + 1;
}

int maxDepthIterative(TreeNode* root)
{
	if (!root)
		return 0;

	queue<TreeNode*> nodeQu;
	nodeQu.push(root);
	int res{};

	while (!nodeQu.empty())
	{
		res++;
		int quSize = nodeQu.size();
		while (quSize--)
		{
			TreeNode* curr = nodeQu.front();
			nodeQu.pop();

			if (curr->left)
				nodeQu.push(curr->left);
			if (curr->right)
				nodeQu.push(curr->right);
		}
	}

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

	cout << maxDepthRecursive(root) << endl;
	cout << maxDepthIterative(root) << endl;
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
