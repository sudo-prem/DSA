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

class BSTIterator
{
private:
	stack<TreeNode*> nodeSt;

public:
	BSTIterator(TreeNode* root)
	{
		while (root)
		{
			nodeSt.push(root);
			root = root->left;
		}
	}

	int next()
	{
		auto currNode = nodeSt.top();
		int currVal = currNode->val;
		nodeSt.pop();

		currNode = currNode->right;
		while (currNode)
		{
			nodeSt.push(currNode);
			currNode = currNode->left;
		}

		return currVal;
	}

	bool hasNext()
	{
		return (!nodeSt.empty());
	}
};

void solve()
{
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(3);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(8);

	BSTIterator* obj = new BSTIterator(root);
	int param_1 = obj->next();
	bool param_2 = obj->hasNext();

	cout << param_1 << " " << param_2 << endl;
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
