#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 2:
int helper(vector<int> &nums, int pos, int target, vector<unordered_map<int, int>> &dp)
{
	if (pos == 0)
	{
		if (nums[pos] == 0)
			return (target == 0) ? 2 : 0;
		if (target - nums[pos] == 0 or target + nums[pos] == 0)
			return 1;
		return 0;
	}
	if (dp[pos].find(target) != dp[pos].end())
		return dp[pos][target];

	int add = helper(nums, pos - 1, target + nums[pos], dp);
	int sub = helper(nums, pos - 1, target - nums[pos], dp);

	return dp[pos][target] = add + sub;
}

int targetSum1(int n, int target, vector<int>& nums)
{
	vector<unordered_map<int, int>> dp(n);

	return helper(nums, n - 1, target, dp);
}

// Approach 2:
int countSubsetSumRecursive(vector<int> &nums, int pos, int target, vector<vector<int>> &dp)
{
	if (pos == 0)
	{
		if (target == 0 and nums[0] == 0)
			return 2;
		// Not Take
		if (target == 0)
			return 1;
		// Take
		return (nums[0] == target);
	}
	if (dp[pos][target] != -1)
		return dp[pos][target];

	int notTake = countSubsetSumRecursive(nums, pos - 1, target, dp);
	int take{};
	if (target >= nums[pos])
		take = countSubsetSumRecursive(nums, pos - 1, target - nums[pos], dp);

	return dp[pos][target] = take + notTake;
}

int targetSum2(int n, int target, vector<int>& nums)
{
	int sum = accumulate(nums.begin(), nums.end(), 0);
	if ((target + sum) % 2)
		return 0;

	int newTarget = (target + sum) / 2;
	vector<vector<int>> dp(n, vector<int> (newTarget + 1, -1));

	return countSubsetSumRecursive(nums, n - 1, newTarget, dp);
}

// Approach 3:
int countSubsetSumIterative(vector<int> &nums, int target)
{
	int n = nums.size();
	vector<vector<int>> dp(n, vector<int> (target + 1, 0));

	for (int i = 0; i <= target; ++i)
	{
		if (i == 0 and nums[0] == 0)
			dp[0][i] = 2;
		else if (i == 0)
			dp[0][i] = 1;
		else
			dp[0][i] = (nums[0] == i);
	}

	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j <= target; ++j)
		{
			int notTake = dp[i - 1][j];
			int take{};
			if (j >= nums[i])
				take = dp[i - 1][j - nums[i]];

			dp[i][j] = take + notTake;
		}
	}

	return dp[n - 1][target];
}

int targetSum3(int n, int target, vector<int>& nums)
{
	int sum = accumulate(nums.begin(), nums.end(), 0);
	if ((target + sum) % 2)
		return 0;

	int newTarget = (target + sum) / 2;
	return countSubsetSumIterative(nums, newTarget);
}

void solve()
{
	int n = 5, target = 3;
	vector<int> nums{1, 1, 1, 1, 1};

	cout << targetSum1(n, target, nums) << endl;
	cout << targetSum2(n, target, nums) << endl;
	cout << targetSum3(n, target, nums) << endl;
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
