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

pair<TreeNode*, TreeNode*> findPreSuc(TreeNode* root, int key)
{
	TreeNode* pre{}, *suc{};

	while (root)
	{
		if (root->val == key)
		{
			if (root->left)
			{
				pre = root->left;
				while (pre->right)
					pre = pre->right;
			}
			if (root->right)
			{
				suc = root->right;
				while (suc->left)
					suc = suc->left;
			}

			return {pre, suc};
		}
		else if (key < root->val)
			suc = root, root = root->left;
		else
			pre = root, root = root->right;
	}

	return {pre, suc};
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

	auto res = findPreSuc(root, 6);
	cout << res.first->val << " " << res.second->val << endl;
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
