// Problem Link:
// https://leetcode.com/problems/house-robber-ii/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
int helper(vector<int> &nums, int pos, bool isFirst, vector<vector<int>> &dp)
{
	int n = nums.size();
	if (pos >= n)
		return 0;
	if (pos == n - 1)
		return isFirst ? 0 : nums[pos];
	if (dp[pos][isFirst] != -1)
		return dp[pos][isFirst];

	return dp[pos][isFirst] = max(nums[pos] + helper(nums, pos + 2, isFirst, dp), helper(nums, pos + 1, isFirst, dp));
}

int rob1(vector<int>& nums)
{
	int n = nums.size();
	vector<vector<int>> dp(n + 1, vector<int> (2, -1));

	return max(helper(nums, 1, false, dp), nums[0] + helper(nums, 2, true, dp));
}

// Approach 2:
int rob2(vector<int> &nums)
{
	int n = nums.size(), res;
	if (n == 1)
		return nums[0];
	if (n == 2)
		return max(nums[0], nums[1]);

	vector<int> dp(n - 1);

	dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
	for (int i = 2; i < n - 1; ++i)
		dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
	res = dp[n - 2];

	dp[0] = nums[1], dp[1] = max(nums[1], nums[2]);
	for (int i = 2; i < n - 1; ++i)
		dp[i] = max(nums[i + 1] + dp[i - 2], dp[i - 1]);

	return max(res, dp[n - 2]);
}

// Approach 3:
int rob3(vector<int>& nums)
{
	int n = nums.size();
	if (n == 1)
		return nums[0];
	if (n == 2)
		return max(nums[0], nums[1]);

	int res{}, prev, prevBefore, curr;
	vector<int> dp(n - 1);

	prevBefore = nums[0], prev = max(nums[0], nums[1]);
	curr = prev;
	for (int i = 2; i < n - 1; ++i)
	{
		curr = max(nums[i] + prevBefore, prev);
		prevBefore = prev;
		prev = curr;
	}
	res = curr;

	prevBefore = nums[1], prev = max(nums[1], nums[2]);
	curr = prev;
	for (int i = 2; i < n - 1; ++i)
	{
		curr = max(nums[i + 1] + prevBefore, prev);
		prevBefore = prev;
		prev = curr;
	}
	res = max(res, curr);

	return res;
}

void solve()
{
	vector<int> nums{2, 3, 2};

	cout << rob1(nums) << endl;
	cout << rob2(nums) << endl;
	cout << rob3(nums) << endl;
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
