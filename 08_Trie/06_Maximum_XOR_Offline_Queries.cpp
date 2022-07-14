#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

class TreeNode
{
public:
	vector<TreeNode*> bitList;

	TreeNode()
	{
		bitList.resize(2);
	}
};

class Trie
{
private:
	TreeNode* root;

public:
	Trie()
	{
		root = new TreeNode();
	}

	void insert(int num)
	{
		TreeNode *node = root;

		for (int i = 31; i >= 0; --i)
		{
			bool bit = (num >> i) & 1;
			if (!node->bitList[bit])
				node->bitList[bit] = new TreeNode();
			node = node->bitList[bit];
		}
	}

	int getMax(int num)
	{
		TreeNode* node = root;
		int res{};

		for (int i = 31; i >= 0; --i)
		{
			bool bit = (num >> i) & 1;
			if (node->bitList[!bit])
			{
				res |= (1 << i);
				node = node->bitList[!bit];
			}
			else
				node = node->bitList[bit];
		}

		return res;
	}
};

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
	int n = queries.size(), m = arr.size();
	vector<int> res(n, 0);
	vector<pair<int, pair<int, int>>> offlineQueries;

	for (int i = 0; i < n; ++i)
		offlineQueries.push_back({queries[i][1], {queries[i][0], i}});

	sort(arr.begin(), arr.end());
	sort(offlineQueries.begin(), offlineQueries.end());

	Trie *t = new Trie();
	int index{};
	for (int i = 0; i < n; ++i)
	{
		while (index < m and arr[index] <= offlineQueries[i].first)
			t->insert(arr[index++]);

		int queryIndex = offlineQueries[i].second.second;
		int queryNum = offlineQueries[i].second.first;

		if (index == 0)
			res[queryIndex] = -1;
		else
			res[queryIndex] = t->getMax(queryNum);
	}

	return res;
}

void solve()
{
	vector<int> arr{0, 1, 2, 3, 4};
	vector<vector<int>> queries{{1, 3}, {5, 6}};

	auto res = maxXorQueries(arr, queries);
	for (int num : res)
		cout << num << " ";
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
