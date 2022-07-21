#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
bool helper(string &p, string &t, int i, int j, vector<vector<int>> &dp)
{
	if (i < 0 and j < 0)
		return true;
	if (i < 0)
		return false;
	if (j < 0)
		return p[i] == '*' and helper(p, t, i - 1, j, dp);
	if (dp[i][j] != -1)
		return dp[i][j];

	if (p[i] == t[j] or p[i] == '?')
		return dp[i][j] = helper(p, t, i - 1, j - 1, dp);
	if (p[i] == '*')
		return dp[i][j] = helper(p, t, i - 1, j, dp) or helper(p, t, i, j - 1, dp);
	return dp[i][j] = false;
}

bool wildcardMatching1(string p, string t)
{
	int m = p.size(), n = t.size();
	vector<vector<int>> dp(m, vector<int> (n, -1));

	return helper(p, t, m - 1, n - 1, dp);
}

// Approach 2:
bool wildcardMatching2(string p, string t)
{
	int m = p.size(), n = t.size();
	vector<vector<bool>> dp(m + 1, vector<bool> (n + 1, false));

	for (int i = 0; i <= m; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			if (i == 0 and j == 0)
				dp[i][j] = true;
			else if (i == 0)
				dp[i][j] = false;
			else if (j == 0)
				dp[i][j] = (p[i - 1] == '*') and dp[i - 1][j];
			else if ((p[i - 1] == t[j - 1]) or (p[i - 1] == '?'))
				dp[i][j] = dp[i - 1][j - 1];
			else if (p[i - 1] == '*')
				dp[i][j] = dp[i][j - 1] or dp[i - 1][j];
			else
				dp[i][j] = false;
		}
	}

	return dp[m][n];
}

// Approach 3:
bool wildcardMatching3(string p, string t)
{
	int m = p.size(), n = t.size();
	vector<vector<bool>> dp(2, vector<bool> (n + 1, false));

	for (int i = 0; i <= m; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			if (i == 0 and j == 0)
				dp[i % 2][j] = true;
			else if (i == 0)
				dp[i % 2][j] = false;
			else if (j == 0)
				dp[i % 2][j] = (p[i - 1] == '*') and dp[(i - 1) % 2][j];
			else if ((p[i - 1] == t[j - 1]) or (p[i - 1] == '?'))
				dp[i % 2][j] = dp[(i - 1) % 2][j - 1];
			else if (p[i - 1] == '*')
				dp[i % 2][j] = dp[i % 2][j - 1] or dp[(i - 1) % 2][j];
			else
				dp[i % 2][j] = false;
		}
	}

	return dp[m % 2][n];
}

void solve()
{
	string p{"?ay"}, t{"ray"};

	cout << wildcardMatching1(p, t) << endl;
	cout << wildcardMatching2(p, t) << endl;
	cout << wildcardMatching3(p, t) << endl;
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
