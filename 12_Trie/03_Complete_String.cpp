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
		return charList[c - 'a'] != NULL;
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

	void insert(string s)
	{
		Node* node = root;

		for (char c : s)
		{
			if (!node->doesContain(c))
				node->putNode(c);
			node = node->getNode(c);
		}

		node->isEnd = true;
	}

	bool isValid(string s)
	{
		Node* node = root;

		for (char c : s)
		{
			if ((node->getNode(c))->isEnd == false)
				return false;
			node = node->getNode(c);
		}

		return node->isEnd;
	}
};

string completeString(vector<string> &words)
{
	int n = words.size();
	Trie *T = new Trie();
	for (string s : words)
		T->insert(s);

	sort(words.begin(), words.end());

	string res{""};
	for (string s : words)
		if (T->isValid(s) and s.size() > res.size())
			res = s;

	if (res == "")
		return "None";
	return res;
}

void solve()
{
	vector<string> words{"n", "ni", "nin", "ninj", "ninja", "ninga"};
	cout << completeString(words) << endl;
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
