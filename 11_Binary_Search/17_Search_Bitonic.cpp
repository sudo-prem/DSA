#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

int getBitonicPoint(vector<int> &nums)
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

int agnosticSearch(vector<int> &nums, int low, int high, int target)
{
	if (nums[low] <= nums[high])
	{
		while (low <= high)
		{
			int mid = low + (high - low) / 2;

			if (nums[mid] == target)
				return mid;
			if (nums[mid] < target)
				low = mid + 1;
			else
				high = mid - 1;
		}
	}
	else
	{
		while (low <= high)
		{
			int mid = low + (high - low) / 2;

			if (nums[mid] == target)
				return mid;
			if (nums[mid] >= target)
				low = mid + 1;
			else
				high = mid - 1;
		}
	}

	return -1;
}

int bitonicSearch(vector<int> &nums, int target)
{
	int bitonicPoint = getBitonicPoint(nums);

	int res1 = agnosticSearch(nums, 0, bitonicPoint, target);
	int res2 = agnosticSearch(nums, bitonicPoint + 1, nums.size() - 1, target);

	if (res1 == -1)
		return res2;
	return res1;
}

void solve()
{
	vector<int> nums{-3, 9, 18, 20, 17, 5, 1};
	int target{9};

	cout << bitonicSearch(nums, target) << endl;
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
