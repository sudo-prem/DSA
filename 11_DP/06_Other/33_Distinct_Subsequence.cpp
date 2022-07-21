#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

int MOD = 1e9 + 7;

// Approach 1:
int helper(string &t, string &s, int i, int j, vector<vector<int>> &dp)
{
	if (i == 0 and j == 0)
		return t[i] == s[j];
	if (j == 0)
		return ((t[i] == s[j]) + helper(t, s, i - 1, j, dp)) % MOD;
	if (i == 0)
		return 0;
	if (t[i] != s[j])
		return helper(t, s, i - 1, j, dp);
	if (dp[i][j] != -1)
		return dp[i][j];

	int res1 = helper(t, s, i - 1, j - 1, dp);
	int res2 = helper(t, s, i - 1, j, dp);

	return dp[i][j] = (res1 + res2) % MOD;
}

int subsequenceCounting1(string &t, string &s, int m, int n)
{
	vector<vector<int>> dp(m, vector<int> (n, -1));

	return helper(t, s, m - 1, n - 1, dp);
}

// Approach 2:
int subsequenceCounting2(string &t, string &s, int m, int n)
{
	vector<vector<int>> dp(m, vector<int> (n, 0));
	dp[0][0] = (t[0] == s[0]);

	for (int i = 1; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (j == 0)
				dp[i][j] = ((t[i] == s[j]) + dp[i - 1][j]) % MOD;
			else if (t[i] != s[j])
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
		}
	}

	return dp[m - 1][n - 1];
}

// Approach 3:
int subsequenceCounting3(string &t, string &s, int m, int n)
{
	vector<vector<int>> dp(2, vector<int> (n, 0));
	dp[0][0] = (t[0] == s[0]);

	for (int i = 1; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (j == 0)
				dp[i % 2][j] = ((t[i] == s[j]) + dp[(i - 1) % 2][j]) % MOD;
			else if (t[i] != s[j])
				dp[i % 2][j] = dp[(i - 1) % 2][j];
			else
				dp[i % 2][j] = (dp[(i - 1) % 2][j - 1] + dp[(i - 1) % 2][j]) % MOD;
		}
	}

	return dp[(m - 1) % 2][n - 1];
}

void solve()
{
	string t{"brootgroot"}, s{"brt"};
	int m = t.size(), n = s.size();

	cout << subsequenceCounting1(t, s, m, n) << endl;
	cout << subsequenceCounting2(t, s, m, n) << endl;
	cout << subsequenceCounting3(t, s, m, n) << endl;
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
