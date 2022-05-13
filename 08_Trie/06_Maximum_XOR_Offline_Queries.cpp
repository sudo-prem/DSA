#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

class Node
{
public:
	vector<Node*> bitList;

	Node()
	{
		bitList.resize(2);
	}
};

class Trie
{
private:
	Node* root;

public:
	Trie()
	{
		root = new Node();
	}

	void insert(int num)
	{
		Node *node = root;

		for (int i = 31; i >= 0; --i)
		{
			bool bit = (num >> i) & 1;
			if (!node->bitList[bit])
				node->bitList[bit] = new Node();
			node = node->bitList[bit];
		}
	}

	int getMax(int num)
	{
		Node* node = root;
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

		if (index == 0)
			res[offlineQueries[i].second.second] = -1;
		else
			res[offlineQueries[i].second.second] = t->getMax(offlineQueries[i].second.first);
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
