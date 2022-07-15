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

bool helper(TreeNode* root, int target, unordered_set<int> &hash)
{
	if (!root)
		return false;

	if (hash.find(target - root->val) != hash.end())
		return true;
	hash.insert(root->val);

	bool leftSearch = helper(root->left, target, hash);
	if (leftSearch)
		return true;

	return helper(root->right, target, hash);
}

bool findTarget(TreeNode* root, int target)
{
	unordered_set<int> hash{};

	return helper(root, target, hash);
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

	cout << findTarget(root, 6) << endl;
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
