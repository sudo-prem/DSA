#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

void subsetSumToK(int n, int target, vector<int> &nums, vector<vector<int>> &dp)
{

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= target; ++j)
		{
			if (i == 0 and nums[i] == j)
				dp[i][j] = true;
			else if (j == 0)
				dp[i][j] = true;
			else if (i > 0 and j >= nums[i] and dp[i - 1][j - nums[i]])
				dp[i][j] = true;
			else if (i > 0 and dp[i - 1][j])
				dp[i][j] = true;
		}
	}
}

int minSubsetSumDifference(vector<int>& nums, int n)
{
	int sum = accumulate(nums.begin(), nums.end(), 0);
	int mid = sum / 2;

	vector<vector<int>> dp(n, vector<int> (mid + 1, 0));
	subsetSumToK(n, mid, nums, dp);

	for (int i = mid; i >= 0; --i)
		if (dp[n - 1][i])
			return abs(i - (sum - i));

	return -1;
}

void solve()
{
	int n = 3;
	vector<int> nums{8, 6, 5};

	cout << minSubsetSumDifference(nums, n) << endl;
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
