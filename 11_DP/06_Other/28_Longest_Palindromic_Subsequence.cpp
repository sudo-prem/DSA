#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

int lcs(string &s, string &t)
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

	return dp[m][n];
}

int longestPalindromeSubseq(string s)
{
	string t(s.rbegin(), s.rend());

	return lcs(s, t);
}

void solve()
{
	string s{"bbbab"};
	cout << longestPalindromeSubseq(s) << endl;
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
