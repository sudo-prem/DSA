#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

int findMin(vector<int>& nums)
{
	int n = nums.size();
	int low = 0, high = n - 1;

	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		int prev = (mid - 1 + n) % n, next = (mid + 1) % n;

		if (nums[low] <= nums[high])
			return nums[low];

		if (nums[mid] <= nums[prev] and nums[mid] <= nums[next])
			return nums[mid];
		else if (nums[low] <= nums[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}

	return -1;
}

void solve()
{
	vector<int> nums{3, 4, 5, 1, 2};

	cout << findMin(nums) << endl;
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
