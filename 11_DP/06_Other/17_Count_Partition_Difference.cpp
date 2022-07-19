#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
int helper(vector<int> &nums, int target, int pos, vector<vector<int>> &dp)
{
	int n = nums.size();
	if (pos == n)
		return target == 0;
	if (target < 0)
		return 0;
	if (dp[pos][target] != -1)
		return dp[pos][target];

	int taken = helper(nums, target - nums[pos], pos + 1, dp);
	int notTaken = helper(nums, target, pos + 1, dp);

	return dp[pos][target] = (taken + notTaken) % MOD;
}

int countPartitions(int n, int d, vector<int> &nums)
{
	int sum = accumulate(nums.begin(), nums.end(), 0);
	if (sum - d < 0 or (sum - d) % 2)
		return 0;
	int target = (sum - d) / 2;

	vector<vector<int>> dp(n, vector<int> (target + 1, -1));

	return helper(nums, target, 0, dp);
}


void solve()
{
	vector<int> nums{5, 2, 5, 1};
	int d = 3, n = 4;

	cout << countPartitions(n, d, nums) << endl;
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
