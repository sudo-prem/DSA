#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

int search(vector<int>& nums, int target)
{
	int n = nums.size();
	int low = 0, high = n - 1;

	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] > target)
			high = mid - 1;
		else
			low = mid + 1;
	}

	return -1;
}

void solve()
{
	vector<int> nums{-1, 0, 3, 5, 9, 12};
	int target = 9;

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
