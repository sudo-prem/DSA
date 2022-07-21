#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

string printLCS(string s, string t)
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
			{
				int res1 = dp[i - 1][j];
				int res2 = dp[i][j - 1];

				dp[i][j] = max(res1, res2);
			}
		}
	}

	string res{};
	int i{m}, j{n};
	while (i > 0 and j > 0)
	{
		if (dp[i - 1][j] == dp[i][j])
			i--;
		else if (dp[i][j - 1] == dp[i][j])
			j--;
		else
		{
			res.push_back(s[i - 1]);
			i--, j--;
		}
	}

	reverse(res.begin(), res.end());
	return res;
}

void solve()
{
	string s1, s2;
	s1 = "adebc", s2 = "dcadb";

	cout << printLCS(s1, s2) << endl;
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
