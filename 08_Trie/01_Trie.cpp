#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

class Node
{
public:
	vector<Node*> charList;
	bool isEnd;

	Node()
	{
		charList.resize(26);
		isEnd = false;
	}

	bool doesContain(char c)
	{
		return (charList[c - 'a'] != NULL);
	}

	void putNode(char c)
	{
		charList[c - 'a'] = new Node();
	}

	Node* getNode(char c)
	{
		return charList[c - 'a'];
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

	void insert(string word)
	{
		Node* node = root;

		for (char c : word)
		{
			if (node->doesContain(c) == false)
				node->putNode(c);
			node = node->getNode(c);
		}

		node->isEnd = true;
	}

	bool search(string word)
	{
		Node* node = root;

		for (char c : word)
		{
			if (node->doesContain(c) == false)
				return false;
			node = node->getNode(c);
		}

		return node->isEnd;
	}

	bool startsWith(string prefix)
	{
		Node* node = root;

		for (char c : prefix)
		{
			if (node->doesContain(c) == false)
				return false;
			node = node->getNode(c);
		}

		return true;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

void solve()
{
	int n = 5;
	vector<int>type = {1, 1, 2, 3, 2};
	vector<string>value = {"hello", "help", "help", "hel", "hel"};
	Trie trie;
	for (int i = 0; i < n; i++)
	{
		if (type[i] == 1)
			trie.insert(value[i]);
		else if (type[i] == 2)
		{
			if (trie.search(value[i]))
				cout << "true" << "\n";
			else
				cout << "false" << "\n";
		}
		else
		{
			if (trie.startsWith(value[i]))
				cout << "true" << "\n";
			else
				cout << "false" << "\n";
		}
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
