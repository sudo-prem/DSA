#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

vector<int> divisibleSet(vector<int> &nums)
{
	int n = nums.size();
	sort(nums.begin(), nums.end());
	vector<int> dp(n, 1), backtrack(n);
	for (int i = 0; i < n; ++i)
		backtrack[i] = i;

	int maxCount{1}, index{};

	for (int i = 0; i < n; ++i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			if (nums[i] % nums[j] == 0 and dp[j] + 1 > dp[i])
			{
				dp[i] = 1 + dp[j];
				backtrack[i] = j;

				if (dp[i] > maxCount)
				{
					maxCount = dp[i];
					index = i;
				}
			}
		}
	}

	vector<int> res{};
	while (maxCount)
	{
		res.push_back(nums[index]);
		index = backtrack[index];
		maxCount--;
	}

	return res;
}

void solve()
{
	vector<int> nums{1, 16, 7, 8, 4};

	auto res = divisibleSet(nums);
	for (int num : res)
		cout << num << " ";
	cout << endl;
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
