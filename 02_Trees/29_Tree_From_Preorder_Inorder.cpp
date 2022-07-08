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

TreeNode* helper(vector<int> &preorder, vector<int> &inorder, int &index, int left, int right)
{
	if (left > right)
		return NULL;

	TreeNode* currNode = new TreeNode(preorder[index]);
	int pos = find(inorder.begin() + left, inorder.begin() + right, preorder[index]) - inorder.begin();

	index++;
	currNode->left = helper(preorder, inorder, index, left, pos - 1);
	currNode->right = helper(preorder, inorder, index, pos + 1, right);
	return currNode;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
	int index{};
	int left{}, right = inorder.size() - 1;

	return helper(preorder, inorder, index, left, right);
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
	vector<int> preorder{3, 9, 20, 15, 7};
	vector<int> inorder{9, 3, 15, 20, 7};

	TreeNode* root = buildTree(preorder, inorder);
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
