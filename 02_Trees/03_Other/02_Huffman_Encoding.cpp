#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

class TreeNode
{
public:
	int freq;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int _freq) : freq(_freq)
	{
		left = right = NULL;
	}
};

// Helps creating a max-heap
class comparator
{
public:
	bool operator()(const TreeNode *a, const TreeNode *b)
	{
		return a->freq > b->freq;
	}
};

void preorder(TreeNode *root, string s, vector<string> &res)
{
	if (!root)
		return;

	if (!root->left and !root->right)
	{
		res.push_back(s);
		return;
	}

	preorder(root->left, s + '0', res);
	preorder(root->right, s + '1', res);
}

vector<string> huffmanCodes(string &s, vector<int> &freq)
{
	int n = s.size();
	vector<string> res{};
	priority_queue<TreeNode *, vector<TreeNode *>, comparator> pq;

	// Push all nodes in pq
	for (int i : freq)
	{
		TreeNode *temp = new TreeNode(i);
		pq.push(temp);
	}

	for (int i = 1; i < n; ++i)
	{
		TreeNode *x = pq.top();
		pq.pop();

		TreeNode *y = pq.top();
		pq.pop();

		TreeNode *temp = new TreeNode(x->freq + y->freq);
		temp->left = x;
		temp->right = y;
		pq.push(temp);
	}

	TreeNode *currTop = pq.top();
	preorder(currTop, "", res);

	return res;
}

void solve()
{
	string s{"abcdef"};
	vector<int> freq{5, 9, 12, 13, 16, 45};
	int n = 6;

	auto res = huffmanCodes(s, freq);
	for (auto itr : res)
		cout << itr << endl;
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
