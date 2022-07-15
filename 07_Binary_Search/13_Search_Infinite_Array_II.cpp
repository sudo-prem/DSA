#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

int binarySearch(vector<int> &nums, int low, int high, int target)
{
	while (low <= high)
	{
		int mid = low + (high - low) / 2;

		if (nums[mid] == target)
			return mid;
		else if (nums[mid] < target)
			low = mid + 1;
		else
			high = mid - 1;
	}

	return -1;
}

int findPos(vector<int> &nums, int target)
{
	int low = 0, high = 1;
	int val = nums[0];

	while (val < target)
	{
		low = high;
		high = 2 * high;
		val = nums[high];
	}

	return binarySearch(nums, low, high, target);
}

void solve()
{
	vector<int> nums{3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170};
	int target = 10;

	cout << findPos(nums, target) << endl;
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
