#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

class Node
{
public:
	vector<Node*> charList;

	Node()
	{
		charList.resize(26);
	}
};

class Trie
{
private:
	Node* root;

public:
	int res;

	Trie()
	{
		root = new Node();
		res = 0;
	}

	void insert(string s)
	{
		Node* node = root;

		for (char c : s)
		{
			if (!node->charList[c - 'a'])
			{
				res++;
				node->charList[c - 'a'] = new Node();
			}
			node = node->charList[c - 'a'];
		}
	}
};

int countDistinctSubstrings(string &s)
{
	Trie *t = new Trie();
	int n = s.size();

	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j <= n; ++j)
			t->insert(s.substr(i, j - i));

	return (t->res) + 1;
}

void solve()
{
	string s1 = "ababa";
	cout << "Total number of distinct substrings : " << countDistinctSubstrings(s1) << endl;

	string s2 = "ccfdf";
	cout << "Total number of distinct substrings : " << countDistinctSubstrings(s2) << endl;
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
