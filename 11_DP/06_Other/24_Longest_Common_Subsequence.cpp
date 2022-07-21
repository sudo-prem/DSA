#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
int helper(string &s, string &t, int i, int j, vector<vector<int>> &dp)
{
	if (i == 0 or j == 0)
		return s[i] == t[j];
	if (s[i] == t[j])
		return 1 + helper(s, t, i - 1, j - 1, dp);
	if (dp[i][j] != -1)
		return dp[i][j];

	int res1 = helper(s, t, i - 1, j, dp);
	int res2 = helper(s, t, i, j - 1, dp);

	return dp[i][j] = max(res1, res2);
}

int lcs1(string s, string t)
{
	int m = s.size(), n = t.size();
	vector<vector<int>> dp(m, vector<int> (n, -1));

	return helper(s, t, m - 1, n - 1, dp);
}

// Approach 2:
int lcs2(string s, string t)
{
	int m = s.size(), n = t.size();
	vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));

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

// Approach 3:
int lcs3(string s, string t)
{
	int m = s.size(), n = t.size();
	vector<vector<int>> dp(2, vector<int> (n + 1, 0));

	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (s[i - 1] == t[j - 1])
				dp[i % 2][j] = 1 + dp[(i - 1) % 2][j - 1];
			else
				dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
		}
	}

	return dp[m % 2][n];
}

void solve()
{
	string s1, s2;
	s1 = "adebc", s2 = "dcadb";

	cout << lcs1(s1, s2) << endl;
	cout << lcs2(s1, s2) << endl;
	cout << lcs3(s1, s2) << endl;
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
