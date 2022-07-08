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

int widthOfBinaryTree(TreeNode* root)
{
	int res{};
	queue<pair<TreeNode*, int>> nodeQu{};
	nodeQu.push({root, 0});

	while (!nodeQu.empty())
	{
		int quSize = nodeQu.size();
		int currMax{INT_MIN}, currMin{INT_MAX};

		while (quSize--)
		{
			TreeNode* currNode = nodeQu.front().first;
			int currIndex = nodeQu.front().second;
			nodeQu.pop();

			currMax = max(currMax, currIndex);
			currMin = min(currMin, currIndex);

			if (currNode->left)
				nodeQu.push({currNode->left, (2LL * currIndex) + 1});
			if (currNode->right)
				nodeQu.push({currNode->right, (2LL * currIndex) + 2});
		}

		res = max(res, currMax - currMin + 1);
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

	cout << widthOfBinaryTree(root) << endl;
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
