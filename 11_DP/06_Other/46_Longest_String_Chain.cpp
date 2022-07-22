#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

bool differByOne(string &s, string &t)
{
	int n = s.size();
	vector<int> hash(26, 0);
	if (n - t.size() != 1)
		return false;

	int i{}, j{};
	while (i < n)
	{
		if (s[i] == t[j])
			i++, j++;
		else
			i++;
	}

	if (i == n and j == t.size())
		return true;
	return false;
}

class Comparator
{
public:
	bool operator()(string &s, string &t)
	{
		return s.size() < t.size();
	}
};

int longestStrChain(vector<string> &words)
{
	sort(words.begin(), words.end(), Comparator());
	int n = words.size();
	vector<int> dp(n, 1);
	int maxCount{1};

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (differByOne(words[i], words[j]) and dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j] + 1;
			}
		}

		maxCount = max(maxCount, dp[i]);
	}

	return maxCount;
}

void solve()
{
	vector<string> words{"x", "xx", "y", "xyx"};

	cout << longestStrChain(words) << endl;
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
