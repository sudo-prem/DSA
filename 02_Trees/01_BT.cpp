#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

class Node
{
public:
	int val;
	Node* left, *right;
};

void dfs(Node* root)
{
	if (!root)
		return;

	cout << root->val << " ";
	dfs(root->left);
	dfs(root->right);
}

void solve()
{
	Node* root = new Node();
	root->val = 3;
	root->left = new Node();
	root->left->val = 4;
	root->right = new Node();
	root->right->val = 5;

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
