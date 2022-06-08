#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

int findPeak(vector<int> &nums)
{
	int n = nums.size();
	int low = 0, high = n - 1;

	while (low <= high)
	{
		int mid = low + (high - low) / 2;

		if (mid + 1 < n and nums[mid] < nums[mid + 1])
			low = mid + 1;
		else
			high = mid - 1;
	}

	return low;
}

void solve()
{
	vector<int> nums{1, 2, 3, 1};

	cout << findPeak(nums) << endl;
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
