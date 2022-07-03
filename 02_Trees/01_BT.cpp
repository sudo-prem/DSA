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

void dfs(TreeNode* root)
{
	if (!root)
		return;

	cout << root->val << " ";
	dfs(root->left);
	dfs(root->right);
}

void solve()
{
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(4);
	root->right = new TreeNode(5);

	dfs(root);
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
