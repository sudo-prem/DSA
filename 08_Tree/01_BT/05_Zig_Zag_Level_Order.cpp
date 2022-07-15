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

vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
	if (!root)
		return {};

	vector<vector<int>> res{};
	bool flag{true};

	deque<TreeNode*> nodeQu{};
	nodeQu.push_back(root);

	while (!nodeQu.empty())
	{
		vector<int> currLevel{};
		int quSize = nodeQu.size();

		if (flag)
		{
			while (quSize--)
			{
				TreeNode* currNode = nodeQu.front();
				nodeQu.pop_front();
				currLevel.push_back(currNode->val);

				if (currNode->left)
					nodeQu.push_back(currNode->left);
				if (currNode->right)
					nodeQu.push_back(currNode->right);
			}
		}
		else
		{
			while (quSize--)
			{
				TreeNode* currNode = nodeQu.back();
				nodeQu.pop_back();
				currLevel.push_back(currNode->val);

				if (currNode->right)
					nodeQu.push_front(currNode->right);
				if (currNode->left)
					nodeQu.push_front(currNode->left);
			}
		}

		res.push_back(currLevel);
		flag = (!flag);
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

	auto res = zigZagLevelOrder(root);
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
