#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

class TrieNode
{
public:
	vector<TrieNode*> bitList;

	TrieNode()
	{
		bitList.resize(2);
	}
};

class Trie
{
private:
	TrieNode* root;

public:
	Trie()
	{
		root = new TrieNode();
	}

	void insert(int num)
	{
		TrieNode* node = root;

		for (int i = 31; i >= 0; --i)
		{
			// Find the MSB
			bool msb = (num >> i) & 1;
			// If the TrieNode is null, create one
			if (!node->bitList[msb])
				node->bitList[msb] = new TrieNode();
			node = node->bitList[msb];
		}
	}

	int getMax(int num)
	{
		TrieNode* node = root;
		int res{};

		for (int i = 31; i >= 0; --i)
		{
			bool msb = (num >> i) & 1;
			if (node->bitList[!msb])
			{
				res |= (1 << i);
				node = node->bitList[!msb];
			}
			else
				node = node->bitList[msb];
		}

		return res;
	}
};

int maxXOR(vector<int> &arr1, vector<int> &arr2)
{
	Trie *t = new Trie();
	for (int num : arr1)
		t->insert(num);

	int res{};
	for (int num : arr2)
		res = max(res, t->getMax(num));

	return res;
}

void solve()
{
	vector<int> arr1{6, 6, 0, 6, 8, 5, 6};
	vector<int> arr2{1, 7, 1, 7, 8, 0, 2};

	cout << maxXOR(arr1, arr2) << endl;
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
