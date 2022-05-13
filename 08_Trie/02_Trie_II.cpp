#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

class Node
{
public:
	vector<Node*> charList;
	int wordCount;
	int prefixCount;

	Node()
	{
		charList.resize(26);
		wordCount = prefixCount = 0;
	}

	bool containsKey(char ch)
	{
		return (charList[ch - 'a'] != NULL);
	}

	Node * get(char ch)
	{
		return charList[ch - 'a'];
	}

	void put(char ch, Node * node)
	{
		charList[ch - 'a'] = node;
	}

	void increaseEnd()
	{
		wordCount++;
	}

	void increasePrefix()
	{
		prefixCount++;
	}

	void deleteEnd()
	{
		wordCount--;
	}

	void reducePrefix()
	{
		prefixCount--;
	}

	int getWordCount()
	{
		return wordCount;
	}

	int getPrefixCount()
	{
		return prefixCount;
	}
};

class Trie
{
private:
	Node * root;

public:
	Trie()
	{
		root = new Node();
	}

	void insert(string word)
	{
		Node * node = root;

		for (char c : word)
		{
			if (!node->containsKey(c))
				node->put(c, new Node());

			node = node->get(c);
			node->increasePrefix();
		}

		node->increaseEnd();
	}

	int countWordsEqualTo(string &word)
	{
		Node *node = root;

		for (char c : word)
		{
			if (node->containsKey(c))
				node = node->get(c);
			else
				return 0;
		}

		return node->getWordCount();
	}


	int countWordsStartingWith(string & word)
	{
		Node * node = root;

		for (char c : word)
		{
			if (node->containsKey(c))
				node = node->get(c);
			else
				return 0;
		}

		return node->getPrefixCount();
	}

	void erase(string & word)
	{
		Node * node = root;

		for (char c : word)
		{
			if (node->containsKey(c))
			{
				node = node->get(c);
				node->reducePrefix();
			}
			else
				return;
		}

		node->deleteEnd();
	}
};


void solve()
{
	Trie T;
	T.insert("apple");
	T.insert("apple");
	T.insert("apps");
	T.insert("apps");

	string word1 = "apps";
	cout << "Count Words Equal to " << word1 << " " << T.countWordsEqualTo(word1) << endl;

	string word2 = "abc";
	cout << "Count Words Equal to " << word2 << " " << T.countWordsEqualTo(word2) << endl;

	string word3 = "ap";
	cout << "Count Words Starting With " << word3 << " " << T.countWordsStartingWith(word3) << endl;

	string word4 = "appl";
	cout << "Count Words Starting With " << word4 << " " << T.countWordsStartingWith(word4) << endl;

	T.erase(word1);
	cout << "Count Words equal to " << word1 << " " << T.countWordsEqualTo(word1) << endl;
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
