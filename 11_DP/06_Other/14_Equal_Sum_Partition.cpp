#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
bool helper(vector<int> &nums, int pos, int target, vector<vector<int>> &dp)
{
	int n = nums.size();
	if (target == 0)
		return true;
	if (pos == n - 1)
		return nums[pos] == target;
	if (target < 0)
		return false;
	if (dp[pos][target] != -1)
		return dp[pos][target];

	return dp[pos][target] = helper(nums, pos + 1, target, dp) or helper(nums, pos + 1, target - nums[pos], dp);
}

bool canPartition1(vector<int> &nums, int n)
{
	int sum = accumulate(nums.begin(), nums.end(), 0);
	if (sum % 2)
		return false;

	int target = sum / 2;
	vector<vector<int>> dp(n, vector<int> (target + 1, -1));
	return helper(nums, 0, target, dp);
}

// Approach 2:
bool canPartition2(vector<int> &nums, int n)
{
	int sum = accumulate(nums.begin(), nums.end(), 0);
	if (sum % 2)
		return false;

	int target = sum / 2;
	vector<vector<bool>> dp(n, vector<bool> (target + 1, false));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= target; ++j)
		{
			if (i == 0 and nums[i] == j)
				dp[i][j] = true;
			else if (j == 0)
				dp[i][j] = true;
			else if (i > 0 and dp[i - 1][j])
				dp[i][j] = true;
			else if (i > 0 and j >= nums[i] and dp[i - 1][j - nums[i]])
				dp[i][j] = true;
		}
	}

	return dp[n - 1][target];
}

// Approach 3
bool canPartition3(vector<int> &nums, int n)
{
	int sum = accumulate(nums.begin(), nums.end(), 0);
	if (sum % 2)
		return false;

	int target = sum / 2;
	vector<vector<bool>> dp(2, vector<bool> (target + 1, false));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= target; ++j)
		{
			if (i == 0 and nums[i] == j)
				dp[i % 2][j] = true;
			else if (j == 0)
				dp[i % 2][j] = true;
			else if (i > 0 and dp[(i - 1) % 2][j])
				dp[i % 2][j] = true;
			else if (i > 0 and j >= nums[i] and dp[(i - 1) % 2][j - nums[i]])
				dp[i % 2][j] = true;
		}
	}

	return dp[(n - 1) % 2][target];
}

void solve()
{
	int n = 6;
	vector<int> nums{3, 1, 1, 2, 2, 1};

	cout << canPartition1(nums, n) << endl;
	cout << canPartition2(nums, n) << endl;
	cout << canPartition3(nums, n) << endl;
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
