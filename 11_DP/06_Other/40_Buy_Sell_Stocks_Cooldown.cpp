#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
int helper(vector<int> &nums, int n, int pos, bool buy, vector<vector<int>> &dp)
{
	if (pos >= n)
		return 0;
	if (dp[pos][buy] != -1)
		return dp[pos][buy];

	int res1 = helper(nums, n, pos + 1, buy, dp);
	int res2{};
	if (buy)
		res2 = (-nums[pos]) + helper(nums, n, pos + 1, !buy, dp);
	else
		res2 = (nums[pos]) + helper(nums, n, pos + 2, !buy, dp);

	return dp[pos][buy] = max(res1, res2);
}

int stockProfit1(vector<int> &nums)
{
	int n = nums.size();
	vector<vector<int>> dp(n, vector<int> (2, -1));

	return helper(nums, n, 0, true, dp);
}

// Approach 2:
int stockProfit2(vector<int> &nums)
{
	int n = nums.size();
	vector<vector<int>> dp(n + 2, vector<int> (2, -1));

	for (int i = n + 1; i >= 0; --i)
	{
		for (int j = 0; j < 2; ++j)
		{
			if (i >= n)
				dp[i][j] = 0;
			else
			{
				int res1 = dp[i + 1][j];
				int res2{};
				if (j)
					res2 = (-nums[i]) + dp[i + 1][!j];
				else
					res2 = (nums[i]) + dp[i + 2][!j];
				dp[i][j] = max(res1, res2);
			}
		}
	}

	return dp[0][1];
}

// Approach 3:
int stockProfit3(vector<int> &nums)
{
	int n = nums.size();
	vector<vector<int>> dp(3, vector<int> (2, -1));

	for (int i = n + 1; i >= 0; --i)
	{
		for (int j = 0; j < 2; ++j)
		{
			if (i >= n)
				dp[i % 3][j] = 0;
			else
			{
				int res1 = dp[(i + 1) % 3][j];
				int res2{};
				if (j)
					res2 = (-nums[i]) + dp[(i + 1) % 3][!j];
				else
					res2 = (nums[i]) + dp[(i + 2) % 3][!j];
				dp[i % 3][j] = max(res1, res2);
			}
		}
	}

	return dp[0][1];
}

void solve()
{
	vector<int> nums{4, 9, 0, 4, 10};

	cout << stockProfit1(nums) << endl;
	cout << stockProfit2(nums) << endl;
	cout << stockProfit3(nums) << endl;
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
