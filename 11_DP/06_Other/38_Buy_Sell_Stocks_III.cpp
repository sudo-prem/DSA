#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
int helper(vector<int> &nums, int pos, int n, int count, vector<vector<int>> &dp)
{
	if (count == 0 or pos == n)
		return 0;
	if (dp[pos][count] != -1)
		return dp[pos][count];

	int res1 = helper(nums, pos + 1, n, count, dp);
	int res2{};
	if (count % 2 == 0)
		res2 = (-nums[pos]) + helper(nums, pos + 1, n, count - 1, dp);
	else
		res2 = (nums[pos]) + helper(nums, pos + 1, n, count - 1, dp);

	return dp[pos][count] = max(res1, res2);
}

int maxProfit1(vector<int>& nums, int n)
{
	vector<vector<int>> dp(n, vector<int> (5, -1));
	return helper(nums, 0, n, 4, dp);
}

// Approach 2:
int maxProfit2(vector<int>& nums, int n)
{
	vector<vector<int>> dp(n + 1, vector<int> (5, -1));

	for (int i = n; i >= 0; --i)
	{
		for (int j = 0; j < 5; ++j)
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

	return dp[0][4];
}

// Approach 3:
int maxProfit3(vector<int>& nums, int n)
{
	vector<vector<int>> dp(2, vector<int> (5, -1));

	for (int i = n; i >= 0; --i)
	{
		for (int j = 0; j < 5; ++j)
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

	return dp[0][4];
}

void solve()
{
	vector<int> nums{3, 3, 5, 0, 3, 1, 4};
	int n = 7;

	cout << maxProfit1(nums, n) << endl;
	cout << maxProfit2(nums, n) << endl;
	cout << maxProfit3(nums, n) << endl;
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
