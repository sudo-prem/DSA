#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
ll helper(int *nums, int pos, int target, vector<vector<ll>> &dp)
{
	if (pos == 0)
		return (target == 0 or target % nums[0] == 0);
	if (dp[pos][target] != -1)
		return dp[pos][target];

	ll notTake = helper(nums, pos - 1, target, dp);
	ll take{};
	if (target >= nums[pos])
		take = helper(nums, pos, target - nums[pos], dp);

	return dp[pos][target] = take + notTake;
}

ll countWaysToMakeChange1(int *nums, int n, int target)
{
	vector<vector<ll>> dp(n, vector<ll> (target + 1, -1));

	return helper(nums, n - 1, target, dp);
}

// Approach 2:
ll countWaysToMakeChange2(int *nums, int n, int target)
{
	vector<vector<ll>> dp(n, vector<ll> (target + 1, 0));

	dp[0][0] = 1;
	for (int i = 1; i <= target; ++i)
		dp[0][i] = (i % nums[0] == 0);

	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j <= target; ++j)
		{
			ll notTake = dp[i - 1][j];
			ll take{};
			if (j >= nums[i])
				take = dp[i][j - nums[i]];

			dp[i][j] = take + notTake;
		}
	}

	return dp[n - 1][target];
}

// Approach 3:
ll countWaysToMakeChange3(int *nums, int n, int target)
{
	vector<vector<ll>> dp(2, vector<ll> (target + 1, 0));

	dp[0][0] = 1;
	for (int i = 1; i <= target; ++i)
		dp[0][i] = (i % nums[0] == 0);

	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j <= target; ++j)
		{
			ll notTake = dp[(i - 1) % 2][j];
			ll take{};
			if (j >= nums[i])
				take = dp[i % 2][j - nums[i]];

			dp[i % 2][j] = take + notTake;
		}
	}

	return dp[(n - 1) % 2][target];
}

void solve()
{
	int nums[] {1, 2, 3};
	int n = 3, target = 4;

	cout << countWaysToMakeChange1(nums, n, target) << endl;
	cout << countWaysToMakeChange2(nums, n, target) << endl;
	cout << countWaysToMakeChange3(nums, n, target) << endl;
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
