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

void helper(TreeNode* root, vector<int> &res)
{
	if (!root)
		return;

	helper(root->left, res);
	res.push_back(root->val);
	helper(root->right, res);
}

vector<int> recursiveInorder(TreeNode* root)
{
	vector<int> res{};

	helper(root, res);

	return res;
}

vector<int> iterativeInorder(TreeNode* root)
{
	vector<int> res{};
	stack<TreeNode*> nodeSt{};

	while (!nodeSt.empty() or root)
	{
		if (root)
		{
			nodeSt.push(root);
			root = root->left;
		}
		else
		{
			res.push_back(nodeSt.top()->val);
			root = nodeSt.top()->right;
			nodeSt.pop();
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

	auto res1 = recursiveInorder(root);
	for (int num : res1)
		cout << num << " ";
	cout << endl;

	auto res2 = iterativeInorder(root);
	for (int num : res2)
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
