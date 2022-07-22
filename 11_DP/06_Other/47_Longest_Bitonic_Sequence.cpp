#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

int longestBitonicSequence(vector<int>& nums, int n)
{
	vector<int> dp1(n, 1), dp2(n, 1);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (nums[i] > nums[j] and 1 + dp1[j] > dp1[i])
				dp1[i] = 1 + dp1[j];
		}
	}

	for (int i = n - 1; i >= 0; --i)
	{
		for (int j = n - 1; j > i; --j)
		{
			if (nums[i] > nums[j] and 1 + dp2[j] > dp2[i])
				dp2[i] = 1 + dp2[j];
		}
	}

	int res{};
	for (int i = 0; i < n; ++i)
		res = max(res, dp1[i] + dp2[i] - 1);

	return res;
}


void solve()
{
	int n = 5;
	vector<int> nums{1, 2, 1, 2, 1};

	cout << longestBitonicSequence(nums, n) << endl;
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
