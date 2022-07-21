#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

string shortestSupersequence(string s, string t)
{
	int m = s.size(), n = t.size();
	vector<vector<int>> dp(m + 1, vector<int> (n + 1));

	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (s[i - 1] == t[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	string res{};
	int i = m, j = n;
	while (i > 0 and j > 0)
	{
		if (s[i - 1] == t[j - 1])
		{
			res.push_back(s[i - 1]);
			i--, j--;
		}
		else if (dp[i - 1][j] > dp[i][j - 1])
		{
			res.push_back(s[i - 1]);
			i--;
		}
		else
		{
			res.push_back(t[j - 1]);
			j--;
		}
	}
	while (i > 0)
		res.push_back(s[i - 1]), i--;
	while (j > 0)
		res.push_back(t[j - 1]), j--;

	reverse(res.begin(), res.end());
	return res;
}

void solve()
{
	string s{"brute"}, t{"groot"};

	cout << shortestSupersequence(s, t) << endl;
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
