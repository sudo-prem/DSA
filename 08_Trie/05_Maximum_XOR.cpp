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
		Node* node = root;

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
		Node *node = root;
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
