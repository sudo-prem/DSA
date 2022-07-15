#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

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

vector<int> searchRange(vector<int> &nums, int target)
{
	int n = nums.size(), lb = lowerBound(nums, target), ub = upperBound(nums, target) - 1;
	vector<int> res(2, -1);

	if (lb >= 0 and lb < n and nums[lb] == target)
		res[0] = lb;
	if (ub >= 0 and ub < n and nums[ub] == target)
		res[1] = ub;

	return res;
}

void solve()
{
	vector<int> nums{5, 7, 7, 8, 8, 10};
	int target = 8;

	auto res = searchRange(nums, target);
	for (int i : res)
		cout << i << " ";
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
