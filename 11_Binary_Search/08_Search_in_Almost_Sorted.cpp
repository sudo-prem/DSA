#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

int search(vector<int> &nums, int target)
{
	int low = 0, high = nums.size() - 1;
	int n = nums.size();

	while (low <= high)
	{
		int mid = low + (high - low) / 2;

		if (nums[mid] == target)
			return mid;
		else if (nums[(mid + 1) % n] == target)
			return (mid + 1) % n;
		else if (nums[(mid - 1 + n) % n] == target)
			return (mid - 1 + n) % n;

		if (nums[mid] < target)
			low = mid + 1;
		else
			high = mid - 1;
	}

	return -1;
}

void solve()
{
	vector<int> nums{10, 3, 40, 20, 50, 80, 70};
	int target = 20;

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
