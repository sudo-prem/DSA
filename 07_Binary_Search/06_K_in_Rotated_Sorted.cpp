#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

int findKRotation(int arr[], int n)
{
	int low = 0, high = n - 1;

	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		int prev = (mid - 1 + n) % n, next = (mid + 1) % n;

		if (arr[low] <= arr[high])
			return low;

		if (arr[mid] <= arr[prev] and arr[mid] <= arr[next])
			return mid;
		else if (arr[low] <= arr[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}

	return -1;
}

void solve()
{
	int arr[] {5, 1, 2, 3, 4};
	int n = 5;

	cout << findKRotation(arr, n) << endl;
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
