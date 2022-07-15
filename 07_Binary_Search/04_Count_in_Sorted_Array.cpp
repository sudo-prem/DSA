#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

int upperBound(vector<int> &nums, int target)
{
	int low = 0, high = nums.size() - 1;

	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (nums[mid] <= target)
			low = mid + 1;
		else
			high = mid - 1;
	}

	return low;
}

int lowerBound(vector<int> &nums, int target)
{
	int low = 0, high = nums.size() - 1;

	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (nums[mid] >= target)
			high = mid - 1;
		else
			low = mid + 1;
	}

	return low;
}

int countSorted(vector<int> &nums, int target)
{
	int n = nums.size();
	int lb = lowerBound(nums, target), ub = upperBound(nums, target);

	if (lb < 0 or lb >= n or ub < 0 or ub >= n)
		return -1;

	return ub - lb;
}

void solve()
{
	vector<int> nums{2, 4, 10, 10, 10, 18, 20};
	int target = 10;

	cout << countSorted(nums, target) << endl;
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
