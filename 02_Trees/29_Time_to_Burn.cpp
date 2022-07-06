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

int helper(TreeNode* start, unordered_map<TreeNode*, TreeNode*> &hash)
{
	queue<TreeNode*> nodeQu{};
	unordered_map<TreeNode*, bool> visited;

	visited[start] = true;
	nodeQu.push(start);
	int res{};

	while (!nodeQu.empty())
	{
		res++;
		int quSize = nodeQu.size();
		while (quSize--)
		{
			TreeNode* currNode = nodeQu.front();
			nodeQu.pop();

			if (currNode->left and !visited[currNode->left])
				visited[currNode->left] = true, nodeQu.push(currNode->left);
			if (currNode->right and !visited[currNode->right])
				visited[currNode->right] = true, nodeQu.push(currNode->right);

			TreeNode* parent = hash[currNode];
			if (parent and !visited[parent])
				visited[parent] = true, nodeQu.push(parent);
		}
	}

	return res - 1;
}

int timeToBurnTree(TreeNode* root, int start)
{
	queue<TreeNode*> nodeQu;
	nodeQu.push(root);
	unordered_map<TreeNode*, TreeNode*> hash{};
	TreeNode* startNode{};

	while (!nodeQu.empty())
	{
		TreeNode* currNode = nodeQu.front();
		nodeQu.pop();

		if (currNode->val == start)
			startNode = currNode;

		if (currNode->left)
			hash[currNode->left] = currNode, nodeQu.push(currNode->left);
		if (currNode->right)
			hash[currNode->right] = currNode, nodeQu.push(currNode->right);
	}

	return helper(startNode, hash);
}

void solve()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(5);

	cout << timeToBurnTree(root, 3) << endl;
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
