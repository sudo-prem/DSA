#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
long getMaximumProfit1(long *nums, int n)
{
	if (n == 0 or n == 1)
		return 0;

	long res{};

	for (int i = 1; i < n; ++i)
	{
		if (nums[i] > nums[i - 1])
			res += nums[i] - nums[i - 1];
	}

	return res;
}

// Approach 2:
long helper(long *nums, int pos, int n, bool buy, vector<vector<long>> &dp)
{
	if (pos == n)
		return 0;
	if (dp[pos][buy] != -1)
		return dp[pos][buy];

	long res1 = helper(nums, pos + 1, n, buy, dp);
	long res2{};
	if (buy)
		res2 = (-nums[pos]) + helper(nums, pos + 1, n, !buy, dp);
	else
		res2 = (nums[pos]) + helper(nums, pos + 1, n, !buy, dp);

	return dp[pos][buy] = max(res1, res2);
}

long getMaximumProfit2(long *nums, int n)
{
	vector<vector<long>> dp(n, vector<long> (2, -1));

	return helper(nums, 0, n, true, dp);
}

// Approach 3:
long getMaximumProfit3(long *nums, int n)
{
	vector<vector<long>> dp(n + 1, vector<long> (2, 0));

	for (int i = n; i >= 0; --i)
	{
		for (int j = 0; j < 2; ++j)
		{
			if (i == n)
				dp[i][j] = 0;
			else
			{
				long res1 = dp[i + 1][j];
				long res2{};
				if (j)
					res2 = (-nums[i]) + dp[i + 1][!j];
				else
					res2 = (nums[i]) + dp[i + 1][!j];

				dp[i][j] = max(res1, res2);
			}
		}
	}

	return dp[0][1];
}

// Approach 4:
long getMaximumProfit4(long *nums, int n)
{
	vector<vector<long>> dp(2, vector<long> (2, 0));

	for (int i = n; i >= 0; --i)
	{
		for (int j = 0; j < 2; ++j)
		{
			if (i == n)
				dp[i % 2][j] = 0;
			else
			{
				long res1 = dp[(i + 1) % 2][j];
				long res2{};
				if (j)
					res2 = (-nums[i]) + dp[(i + 1) % 2][!j];
				else
					res2 = (nums[i]) + dp[(i + 1) % 2][!j];

				dp[i % 2][j] = max(res1, res2);
			}
		}
	}

	return dp[0][1];
}

void solve()
{
	long nums[] {1, 2, 3, 4, 5, 6, 7};
	int n = 7;

	cout << getMaximumProfit1(nums, n) << endl;
	cout << getMaximumProfit2(nums, n) << endl;
	cout << getMaximumProfit3(nums, n) << endl;
	cout << getMaximumProfit4(nums, n) << endl;
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
