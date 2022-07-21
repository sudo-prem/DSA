#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
int helper(string &s, string &t, int i, int j, vector<vector<int>> &dp)
{
	if (i < 0)
		return j + 1;
	if (j < 0)
		return i + 1;
	if (dp[i][j] != -1)
		return dp[i][j];
	if (s[i] == t[j])
		return dp[i][j] = helper(s, t, i - 1, j - 1, dp);

	int res1 = helper(s, t, i - 1, j - 1, dp);
	int res2 = helper(s, t, i, j - 1, dp);
	int res3 = helper(s, t, i - 1, j, dp);
	return dp[i][j] = 1 + min({res1, res2, res3});
}

int editDistance1(string s, string t)
{
	int m = s.size(), n = t.size();
	vector<vector<int>> dp(m, vector<int> (n, -1));

	return helper(s, t, m - 1, n - 1, dp);
}

// Approach 2:
int editDistance2(string s, string t)
{
	int m = s.size(), n = t.size();
	vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));

	for (int i = 0; i <= m; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			if (i == 0)
				dp[i][j] = j;
			else if (j == 0)
				dp[i][j] = i;
			else if (s[i - 1] == t[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]});
		}
	}

	return dp[m][n];
}

// Approach 3:
int editDistance3(string s, string t)
{
	int m = s.size(), n = t.size();
	vector<vector<int>> dp(2, vector<int> (n + 1, 0));

	for (int i = 0; i <= m; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			if (i == 0)
				dp[i % 2][j] = j;
			else if (j == 0)
				dp[i % 2][j] = i;
			else if (s[i - 1] == t[j - 1])
				dp[i % 2][j] = dp[(i - 1) % 2][j - 1];
			else
				dp[i % 2][j] = 1 + min({dp[(i - 1) % 2][j - 1], dp[i % 2][j - 1], dp[(i - 1) % 2][j]});
		}
	}

	return dp[m % 2][n];
}

void solve()
{
	string s{"abc"}, t{"dc"};

	cout << editDistance1(s, t) << endl;
	cout << editDistance2(s, t) << endl;
	cout << editDistance3(s, t) << endl;
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
