#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

int findNumberOfLIS(vector<int> &nums)
{
	int n = nums.size();
	vector<int> dp(n, 1), count(n, 1);
	int maxCount{1};

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (nums[j] < nums[i])
			{
				if (dp[j] + 1 > dp[i])
				{
					dp[i] = 1 + dp[j];
					count[i] = count[j];
				}
				else if (dp[j] + 1 == dp[i])
					count[i] += count[j];
			}
		}

		maxCount = max(maxCount, dp[i]);
	}

	int res{};
	for (int i = 0; i < n; ++i)
		if (dp[i] == maxCount)
			res += count[i];

	return res;
}

void solve()
{
	vector<int> nums{50, 3, 90, 60, 80};

	cout << findNumberOfLIS(nums) << endl;
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
