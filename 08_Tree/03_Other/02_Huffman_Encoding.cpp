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

void preorder(TreeNode *root, string &s, vector<string> &res)
{
	if (!root)
		return;

	if (!root->left and !root->right)
	{
		res.push_back(s);
		return;
	}

	s.push_back('0');
	preorder(root->left, s, res);
	s.pop_back();

	s.push_back('1');
	preorder(root->right, s, res);
	s.pop_back();
}

vector<string> huffmanCodes(string &word, vector<int> &freq)
{
	int n = word.size();
	vector<string> res{};
	priority_queue<TreeNode *, vector<TreeNode *>, comparator> maxHeap;

	// Push all nodes in maxHeap
	for (int i : freq)
	{
		TreeNode *temp = new TreeNode(i);
		maxHeap.push(temp);
	}

	while (maxHeap.size() > 1)
	{
		TreeNode *x = maxHeap.top();
		maxHeap.pop();

		TreeNode *y = maxHeap.top();
		maxHeap.pop();

		TreeNode *temp = new TreeNode(x->freq + y->freq);
		temp->left = x;
		temp->right = y;
		maxHeap.push(temp);
	}

	TreeNode *currTop = maxHeap.top();
	string s{};
	preorder(currTop, s, res);

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
