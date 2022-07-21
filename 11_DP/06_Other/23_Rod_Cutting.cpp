#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
int helper(vector<int> &price, int pos, int rodLen, vector<vector<int>> &dp)
{
	if (pos == 0)
	{
		if (rodLen == 0)
			return 0;
		return rodLen * price[0];
	}
	if (dp[pos][rodLen] != -1)
		return dp[pos][rodLen];

	int notTake = helper(price, pos - 1, rodLen, dp);
	int take{};
	if (rodLen - pos - 1 >= 0)
		take = price[pos] + helper(price, pos, rodLen - pos - 1, dp);

	return dp[pos][rodLen] = max(take, notTake);
}

int cutRod1(vector<int> &price, int n)
{
	vector<vector<int>> dp(n, vector<int> (n + 1, -1));

	return helper(price, n - 1, n, dp);
}

// Approach 2:
int cutRod2(vector<int> &price, int n)
{
	vector<vector<int>> dp(n, vector<int> (n + 1, 0));

	for (int i = 1; i <= n; ++i)
		dp[0][i] = i * price[0];

	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			int notTake = dp[i - 1][j];
			int take{};
			if (j - i - 1 >= 0)
				take = price[i] + dp[i][j - i - 1];

			dp[i][j] = max(take, notTake);
		}
	}

	return dp[n - 1][n];
}

// Approach 3:
int cutRod3(vector<int> &price, int n)
{
	vector<vector<int>> dp(2, vector<int> (n + 1, 0));

	for (int i = 1; i <= n; ++i)
		dp[0][i] = i * price[0];

	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			int notTake = dp[(i - 1) % 2][j];
			int take{};
			if (j - i - 1 >= 0)
				take = price[i] + dp[i % 2][j - i - 1];

			dp[i % 2][j] = max(take, notTake);
		}
	}

	return dp[(n - 1) % 2][n];
}


void solve()
{
	int n = 5;
	vector<int> price{2, 5, 7, 8, 10};

	cout << cutRod1(price, n) << endl;
	cout << cutRod2(price, n) << endl;
	cout << cutRod3(price, n) << endl;
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
