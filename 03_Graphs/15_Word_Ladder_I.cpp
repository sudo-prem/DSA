#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
	unordered_set<string> words(wordList.begin(), wordList.end());
	int n = beginWord.size(), res{};
	queue<string> nodeQu;
	nodeQu.push(beginWord);

	if (words.find(endWord) == words.end())
		return 0;

	while (!nodeQu.empty())
	{
		int size = nodeQu.size();
		res++;

		while (size--)
		{
			string curr = nodeQu.front();
			nodeQu.pop();

			for (int i = 0; i < n; ++i)
			{
				for (char c = 'a'; c <= 'z'; ++c)
				{
					if (c == curr[i])
						continue;

					char exchangeChar = c;
					swap(curr[i], exchangeChar);

					if (curr == endWord)
						return res + 1;

					if (words.find(curr) != words.end())
					{
						nodeQu.push(curr);
						words.erase(curr);
					}

					swap(curr[i], exchangeChar);
				}
			}
		}
	}

	return 0;
}

void solve()
{
	string begin{"hit"};
	string end{"cog"};
	vector<string> words{"hot", "dot", "dog", "lot", "log", "cog"};

	cout << ladderLength(begin, end, words) << endl;
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
