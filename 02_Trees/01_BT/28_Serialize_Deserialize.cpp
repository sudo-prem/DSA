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

class Codec
{
public:
	// Encodes a tree to a single string.
	string serialize(TreeNode* root)
	{
		if (!root)
			return "#";

		string left = serialize(root->left);
		string right = serialize(root->right);

		return to_string(root->val) + " " + left + " " + right;
	}

	TreeNode* helper(queue<char> &nodeQu)
	{
		string curr{};
		while (!nodeQu.empty() and nodeQu.front() != ' ')
			curr.push_back(nodeQu.front()), nodeQu.pop();
		if (!nodeQu.empty())
			nodeQu.pop();

		if (curr == "#")
			return NULL;

		TreeNode* root = new TreeNode(stoi(curr));
		root->left = helper(nodeQu);
		root->right = helper(nodeQu);
		return root;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data)
	{
		queue<char> nodeQu;

		for (char c : data)
			nodeQu.push(c);

		return helper(nodeQu);
	}
};

void preorder(TreeNode* root)
{
	if (!root)
		return;

	cout << root->val << " ";
	preorder(root->left);
	preorder(root->right);
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

	Codec ser, deser;
	TreeNode* res = deser.deserialize(ser.serialize(root));

	preorder(root);
	cout << endl;
	preorder(res);
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
