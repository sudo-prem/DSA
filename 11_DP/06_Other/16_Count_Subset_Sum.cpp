#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
int helper(vector<int> &nums, int target, int pos, vector<vector<int>> &dp)
{
	int n = nums.size();
	if (target < 0)
		return 0;
	// Note that subsets are traversed till the end
	// So do not take if(target == 0) as a condition
	if (pos == n)
		return target == 0;
	if (dp[pos][target] != -1)
		return dp[pos][target];

	return dp[pos][target] = helper(nums, target, pos + 1, dp) + helper(nums, target - nums[pos], pos + 1, dp);
}

int findWays1(vector<int> &nums, int target)
{
	int n = nums.size();
	vector<vector<int>> dp(n, vector<int>(target + 1, -1));

	return helper(nums, target, 0, dp);
}

void solve()
{
	vector<int> nums {1, 2, 2, 3};
	int target {3};

	cout << findWays1(nums, target) << endl;
	/* cout << findWays2(nums, target) << endl; */
	/* cout << findWays3(nums, target) << endl; */
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
