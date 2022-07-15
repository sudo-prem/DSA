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

TreeNode* helper(vector<int> &preorder, int start, int end)
{
	if (start > end)
		return NULL;

	int pivot{start + 1};
	while (pivot <= end and preorder[pivot] < preorder[start])
		pivot++;

	TreeNode* root = new TreeNode(preorder[start]);
	root->left = helper(preorder, start + 1, pivot - 1);
	root->right = helper(preorder, pivot, end);

	return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder)
{
	int start = 0, end = preorder.size() - 1;
	return helper(preorder, start, end);
}

void preorderTraversal(TreeNode* root)
{
	if (!root)
		return;

	cout << root->val << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

void solve()
{
	vector<int> preorder{8, 5, 1, 7, 10, 12};

	TreeNode* root = bstFromPreorder(preorder);

	preorderTraversal(root);
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
