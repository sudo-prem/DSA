#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
int helper(vector<int> &nums, int n, int pos, int count, vector<vector<int>> &dp)
{
	if (pos == n or count == 0)
		return 0;
	if (dp[pos][count] != -1)
		return dp[pos][count];

	int res1 = helper(nums, n, pos + 1, count, dp);
	int res2{};
	if (count % 2 == 0)
		res2 = (-nums[pos]) + helper(nums, n, pos + 1, count - 1, dp);
	else
		res2 = (nums[pos]) + helper(nums, n, pos + 1, count - 1, dp);

	return dp[pos][count] = max(res1, res2);
}

int maximumProfit1(vector<int> &nums, int n, int k)
{
	vector<vector<int>> dp(n, vector<int> (2 * k + 1, -1));

	return helper(nums, n, 0, 2 * k, dp);
}

// Approach 2:
int maximumProfit2(vector<int> &nums, int n, int k)
{
	int count = 2 * k;
	vector<vector<int>> dp(n + 1, vector<int> (count + 1, -1));

	for (int i = n; i >= 0; --i)
	{
		for (int j = 0; j <= count; ++j)
		{
			if (i == n or j == 0)
				dp[i][j] = 0;
			else
			{
				int res1 = dp[i + 1][j];
				int res2{};
				if (j % 2 == 0)
					res2 = (-nums[i]) + dp[i + 1][j - 1];
				else
					res2 = (nums[i]) + dp[i + 1][j - 1];
				dp[i][j] = max(res1, res2);
			}
		}
	}

	return dp[0][count];
}
int maximumProfit(vector<int> &nums, int n, int k)
{
	int count = 2 * k;
	vector<vector<int>> dp(n + 1, vector<int> (count + 1, -1));

	for (int i = n; i >= 0; --i)
	{
		for (int j = 0; j <= count; ++j)
		{
			if (i == n or j == 0)
				dp[i][j] = 0;
			else
			{
				int res1 = dp[i + 1][j];
				int res2{};
				if (j % 2 == 0)
					res2 = (-nums[i]) + dp[i + 1][j - 1];
				else
					res2 = (nums[i]) + dp[i + 1][j - 1];
				dp[i][j] = max(res1, res2);
			}
		}
	}

	return dp[0][count];
}

// Approach 3:
int maximumProfit3(vector<int> &nums, int n, int k)
{
	int count = 2 * k;
	vector<vector<int>> dp(2, vector<int> (count + 1, -1));

	for (int i = n; i >= 0; --i)
	{
		for (int j = 0; j <= count; ++j)
		{
			if (i == n or j == 0)
				dp[i % 2][j] = 0;
			else
			{
				int res1 = dp[(i + 1) % 2][j];
				int res2{};
				if (j % 2 == 0)
					res2 = (-nums[i]) + dp[(i + 1) % 2][j - 1];
				else
					res2 = (nums[i]) + dp[(i + 1) % 2][j - 1];
				dp[i % 2][j] = max(res1, res2);
			}
		}
	}

	return dp[0][count];
}


void solve()
{
	int n = 6, k = 2;
	vector<int> nums{3, 2, 6, 5, 0, 3};

	cout << maximumProfit1(nums, n, k) << endl;
	cout << maximumProfit2(nums, n, k) << endl;
	cout << maximumProfit3(nums, n, k) << endl;
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
