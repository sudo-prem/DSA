#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

int binarySearch(vector<int> &nums, int low, int high)
{
	while (low <= high)
	{
		int mid = low + (high - low) / 2;

		if (nums[mid] == 1)
			high = mid - 1;
		else
			low = mid + 1;
	}

	return low;
}

int search(vector<int> &nums)
{
	int low = 0, high = 1;

	while (nums[high] != 1)
	{
		low = high;
		high = 2 * high;
	}

	return binarySearch(nums, low, high);
}

void solve()
{
	vector<int> nums{0, 0, 1, 1, 1, 1};
	cout << search(nums) << endl;
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
