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

int minDiff(vector<int> nums, int target)
{
	pii floorCeil = findFloorAndCeil(nums, target);

	if (floorCeil.first != -1 and floorCeil.second != -1)
	{
		if (abs(floorCeil.first - target) < abs(floorCeil.second - target))
			return floorCeil.first;
		return floorCeil.second;
	}
	else if (floorCeil.first == -1 and floorCeil.second == -1)
		return -1;
	else if (floorCeil.first == -1)
		return floorCeil.second;
	return floorCeil.first;
}

void solve()
{
	vector<int> nums{2, 5, 10, 12, 15};
	int target = 8;

	cout << minDiff(nums, target) << endl;
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
