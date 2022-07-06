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

vector<int> morrisPostorder(TreeNode* root)
{
	vector<int> res{};

	while (root)
	{
		auto rightNode = root->right;
		if (rightNode)
		{
			while (rightNode->left and rightNode->left != root)
				rightNode = rightNode->left;

			if (rightNode->left == root)
			{
				rightNode->left = NULL;
				root = root->left;
			}
			else
			{
				rightNode->left = root;
				res.push_back(root->val);
				root = root->right;
			}
		}
		else
		{
			res.push_back(root->val);
			root = root->left;
		}
	}

	reverse(res.begin(), res.end());
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

	auto res = morrisPostorder(root);
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
