#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
int helper(string &s, int i, int j, vector<vector<int>> &dp)
{
	if (i >= j)
		return 0;
	if (s[i] == s[j])
		return dp[i][j] = helper(s, i + 1, j - 1, dp);
	if (dp[i][j] != -1)
		return dp[i][j];

	int res1 = helper(s, i + 1, j, dp);
	int res2 = helper(s, i, j - 1, dp);

	return dp[i][j] = 1 + min(res1, res2);
}

int minInsertion1(string &s)
{
	int n = s.size();
	vector<vector<int>> dp(n, vector<int> (n, -1));

	return helper(s, 0, n - 1, dp);
}

// Approach 2:
int minInsertion2(string &s)
{
	int n = s.size();
	vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
	string t(s.rbegin(), s.rend());

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (s[i - 1] == t[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	return n - dp[n][n];
}


void solve()
{
	string s{"abcaa"};

	cout << minInsertion1(s) << endl;
	cout << minInsertion2(s) << endl;
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
