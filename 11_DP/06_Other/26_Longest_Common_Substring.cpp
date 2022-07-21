#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

int longestCommonSubstring(string s1, string s2)
{
	int m = s1.size(), n = s2.size();
	int res{};

	vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));

	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = 1 + dp[i - 1][j - 1];
				res = max(res, dp[i][j]);
			}
		}
	}

	return res;
}

void solve()
{
	cout << longestCommonSubstring("acjkp", "abcjklp") << endl;
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
