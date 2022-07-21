#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
int helper(vector<int> &nums, int target, int pos, vector<vector<int>> &dp)
{
	if (pos == 0)
		return (target % nums[pos] == 0) ? target / nums[pos] : -1;
	if (dp[pos][target] != -1)
		return dp[pos][target];

	int notTake = helper(nums, target, pos - 1, dp);
	int take{-1};
	if (target >= nums[pos])
		take = helper(nums, target - nums[pos], pos, dp);

	if (take == -1 and notTake == -1)
		return dp[pos][target] = -1;
	if (take == -1)
		return dp[pos][target] = notTake;
	if (notTake == -1)
		return dp[pos][target] = 1 + take;
	return dp[pos][target] = min(notTake, 1 + take);
}

int minimumElements1(vector<int> &nums, int target)
{
	int n = nums.size();
	vector<vector<int>> dp(n, vector<int> (target + 1, -1));

	return helper(nums, target, n - 1, dp);
}

// Approach 2:
int minimumElements2(vector<int> &nums, int target)
{
	int n = nums.size();
	vector<vector<int>> dp(n, vector<int> (target + 1, 0));

	for (int i = 0; i <= target; ++i)
		dp[0][i] = (i % nums[0] == 0) ? i / nums[0] : -1;

	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j <= target; ++j)
		{
			int notTake = dp[i - 1][j];
			int take{-1};
			if (j >= nums[i])
				take = dp[i][j - nums[i]];

			if (take == -1 and notTake == -1)
				dp[i][j] = -1;
			else if (take == -1)
				dp[i][j] = notTake;
			else if (notTake == -1)
				dp[i][j] = 1 + take;
			else
				dp[i][j] = min(notTake, 1 + take);
		}
	}

	return dp[n - 1][target];
}

// Approach 3:
int minimumElements3(vector<int> &nums, int target)
{
	int n = nums.size();
	vector<vector<int>> dp(2, vector<int> (target + 1, 0));

	for (int i = 0; i <= target; ++i)
		dp[0][i] = (i % nums[0] == 0) ? i / nums[0] : -1;

	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j <= target; ++j)
		{
			int notTake = dp[(i - 1) % 2][j];
			int take{-1};
			if (j >= nums[i])
				take = dp[i % 2][j - nums[i]];

			if (take == -1 and notTake == -1)
				dp[i % 2][j] = -1;
			else if (take == -1)
				dp[i % 2][j] = notTake;
			else if (notTake == -1)
				dp[i % 2][j] = 1 + take;
			else
				dp[i % 2][j] = min(notTake, 1 + take);
		}
	}

	return dp[(n - 1) % 2][target];
}

void solve()
{
	int target{7};
	vector<int> nums{1, 2, 3};

	cout << minimumElements1(nums, target) << endl;
	cout << minimumElements2(nums, target) << endl;
	cout << minimumElements3(nums, target) << endl;
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
