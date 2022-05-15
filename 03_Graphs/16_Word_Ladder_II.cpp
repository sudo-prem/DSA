#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

vector<vector<string>> findLadders(string &beginWord, string &endWord, vector<string> &wordList)
{
	int n = beginWord.size();
	vector<vector<string>> res{};
	unordered_set<string> words(wordList.begin(), wordList.end());
	queue<vector<string>> nodeQu;
	nodeQu.push({beginWord});

	if (words.find(endWord) == words.end())
		return {};

	while (nodeQu.empty() == false)
	{
		unordered_set<string> visited{};
		int size = nodeQu.size();
		while (size--)
		{
			auto currList = nodeQu.front();
			auto currWord = currList.back();
			nodeQu.pop();

			for (int i = 0; i < n; ++i)
			{
				char temp = currWord[i];
				for (char c = 'a'; c <= 'z'; ++c)
				{
					if (c == temp)
						continue;
					currWord[i] = c;
					if (words.find(currWord) != words.end())
					{
						visited.insert(currWord);
						currList.push_back(currWord);
						if (currWord == endWord)
							res.push_back(currList);
						else
							nodeQu.push(currList);
						currList.pop_back();
					}
				}
				currWord[i] = temp;
			}
		}

		for (string s : visited)
			words.erase(s);
	}

	return res;
}

void solve()
{
	string beginWord{"hit"}, endWord{"cog"};
	vector<string> wordList{"hot", "dot", "dog", "lot", "log", "cog"};

	auto res = findLadders(beginWord, endWord, wordList);
	for (auto vec : res)
	{
		for (auto num : vec)
			cout << num << " ";
		cout << endl;
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
