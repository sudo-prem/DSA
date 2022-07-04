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

vector<vector<int>> verticalTraversal(TreeNode* root)
{
	map<int, map<int, multiset<int>>> hash{};

	queue<pair<TreeNode*, pair<int, int>>> nodeQu{};
	nodeQu.push({root, {0, 0}});

	while (!nodeQu.empty())
	{
		TreeNode* currNode = nodeQu.front().first;
		int currPos = nodeQu.front().second.first;
		int currLevel = nodeQu.front().second.second;
		nodeQu.pop();

		hash[currPos][currLevel].insert(currNode->val);

		if (currNode->left)
			nodeQu.push({currNode->left, {currPos - 1, currLevel + 1}});
		if (currNode->right)
			nodeQu.push({currNode->right, {currPos + 1, currLevel + 1}});
	}

	vector<vector<int>> res{};
	for (auto itr1 : hash)
	{
		vector<int> curr{};
		for (auto itr2 : itr1.second)
			curr.insert(curr.end(), itr2.second.begin(), itr2.second.end());
		res.push_back(curr);
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

	auto res = verticalTraversal(root);

	for (auto vec : res)
	{
		for (int num : vec)
			cout << num << " ";
		cout << endl;
	}
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
