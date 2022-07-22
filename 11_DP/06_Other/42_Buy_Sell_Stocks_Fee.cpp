#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
int helper(vector<int> &nums, int n, int fee, int pos, int buy, vector<vector<int>> &dp)
{
	if (pos == n)
		return 0;
	if (dp[pos][buy] != -1)
		return dp[pos][buy];

	int res1 = helper(nums, n, fee, pos + 1, buy, dp);
	int res2{};
	if (buy)
		res2 = (-nums[pos]) + helper(nums, n, fee, pos + 1, !buy, dp);
	else
		res2 = (nums[pos] - fee) + helper(nums, n, fee, pos + 1, !buy, dp);

	return dp[pos][buy] = max(res1, res2);
}

int maximumProfit1(int n, int fee, vector<int> &nums)
{
	vector<vector<int>> dp(n, vector<int> (2, -1));

	return helper(nums, n, fee, 0, true, dp);
}

// Approach 2:
int maximumProfit2(int n, int fee, vector<int> &nums)
{
	vector<vector<int>> dp(n + 1, vector<int> (2, -1));

	for (int i = n; i >= 0; --i)
	{
		for (int j = 0; j < 2; ++j)
		{
			if (i == n)
				dp[i][j] = 0;
			else
			{
				int res1 = dp[i + 1][j];
				int res2{};
				if (j)
					res2 = (-nums[i]) + dp[i + 1][!j];
				else
					res2 = (nums[i] - fee) + dp[i + 1][!j];
				dp[i][j] = max(res1, res2);
			}
		}
	}

	return dp[0][1];
}

// Approach 3:
int maximumProfit3(int n, int fee, vector<int> &nums)
{
	vector<vector<int>> dp(2, vector<int> (2, -1));

	for (int i = n; i >= 0; --i)
	{
		for (int j = 0; j < 2; ++j)
		{
			if (i == n)
				dp[i % 2][j] = 0;
			else
			{
				int res1 = dp[(i + 1) % 2][j];
				int res2{};
				if (j)
					res2 = (-nums[i]) + dp[(i + 1) % 2][!j];
				else
					res2 = (nums[i] - fee) + dp[(i + 1) % 2][!j];
				dp[i % 2][j] = max(res1, res2);
			}
		}
	}

	return dp[0][1];
}

void solve()
{
	int n = 3, fee = 1;
	vector<int> nums{1, 2, 3};

	cout << maximumProfit1(n, fee, nums) << endl;
	cout << maximumProfit2(n, fee, nums) << endl;
	cout << maximumProfit3(n, fee, nums) << endl;
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
