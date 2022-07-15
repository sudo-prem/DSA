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

pii findFloorAndCeil(vector<int> &nums, int target)
{
	int n = nums.size();
	if (n == 0)
		return {-1, -1};

	int lb = lowerBound(nums, target), ub = upperBound(nums, target);
	if (lb == 0 and nums[lb] != target)
		return {-1, nums[0]};
	else if (lb == n)
		return {nums.back(), -1};
	else if (nums[lb] == target)
		return {nums[lb], nums[lb]};

	return {nums[lb - 1], nums[ub]};
}

void solve()
{
	vector<int> nums{1, 4, 6, 8, 9};
	int target = 2;

	auto res = findFloorAndCeil(nums, target);
	cout << res.first << " " << res.second << endl;
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
