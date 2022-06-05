#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

int search(vector<int> &nums, int target)
{
	if (nums.size() == 1)
		return nums[0] == target;

	int n = nums.size();
	bool flag = nums.front() < nums.back() ? 1 : 0;
	int low{}, high{n - 1};

	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (nums[mid] == target)
			return mid;

		if (flag)
		{
			if (nums[mid] < target)
				low = mid + 1;
			else
				high = mid - 1;
		}
		else
		{
			if (nums[mid] > target)
				low = mid + 1;
			else
				high = mid - 1;
		}
	}

	return -1;
}

void solve()
{
	vector<int> nums{40, 10, 5, 2, 1};
	int target = 10;

	cout << search(nums, target) << endl;
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
