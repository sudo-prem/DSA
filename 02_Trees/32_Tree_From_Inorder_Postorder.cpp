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

TreeNode* helper(vector<int> &inorder, vector<int> &postorder, int &index, int left, int right)
{
	if (left > right)
		return NULL;

	TreeNode* currNode = new TreeNode(postorder[index]);
	int pos = find(inorder.begin(), inorder.end(), postorder[index]) - inorder.begin();

	index--;
	currNode->right = helper(inorder, postorder, index, pos + 1, right);
	currNode->left = helper(inorder, postorder, index, left, pos - 1);

	return currNode;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
	int n = postorder.size();
	int index{n - 1}, left{}, right{n - 1};

	return helper(inorder, postorder, index, left, right);
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
	vector<int> inorder{9, 3, 15, 20, 7};
	vector<int> postorder{9, 15, 7, 20, 3};

	TreeNode* root = buildTree(inorder, postorder);
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
